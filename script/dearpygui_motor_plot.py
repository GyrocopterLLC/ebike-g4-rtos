import dearpygui.dearpygui as dpg
import numpy as np
import time
from threading import Thread

import serial
import serial.tools.list_ports
import os
import pandas as pd
from receive_thread import CobsReceiver

FRAME_RATE = 60

labels = ['angle', 'hallState', 'throttle', 'tA', 'tB', 'tC', 'iA', 'iB', 'iC', 'vA','vB','vC','vBus']
timestamp_period = 50e-6 # 20kHz counter = 50us
data_period = 2e-3 # every 2 millisecs we should get more data
plot_length = 5
dataseries_x = np.arange(0, plot_length, data_period)
dataseries_length = dataseries_x.size
dataseries = np.zeros((dataseries_length, len(labels)))
series_uuids = []
data_on = False

all_comports = []
selected_comport = 0
comport_connected = False
flatmcu = serial.Serial()
mythread = CobsReceiver()

def printcb(caller):
    print('clicked {}'.format(caller))

def plotcancel(caller, appdata, userdata):
    pass

def saveplot(caller, appdata, userdata):
    fullfilepath = appdata['file_path_name']
    filefolder, filename = os.path.split(fullfilepath)
    filesplit = filename.split('.')
    savepathname = os.path.join(filefolder, filesplit[0] + '.xlsx')
    df = pd.DataFrame(np.vstack((dataseries_x, dataseries.T)).T)
    df.to_excel(savepathname, index=False, header=['time']+labels)

def startplot(caller, appdata, userdata):
    global data_on
    if(comport_connected):
        if(not data_on):
            mythread.start_data()
            data_on = True
            dpg.configure_item("start_btn", label="Stop")
        else:
            mythread.stop_data()
            data_on = False
            dpg.configure_item("start_btn", label="Start")

def create_ui():
    global series_uuids
    with(dpg.window(label="Plots", tag = "plot_window")):
        with dpg.child_window(tag="plot_child", height= dpg.get_item_height("plot_window")-60):
            with dpg.plot(label="Motor Data", height=400, width=600, tag="main_plot"):
                dpg.add_plot_legend(location=dpg.mvPlot_Location_South,horizontal=True, outside=True)
                # REQUIRED: create x and y axes
                dpg.add_plot_axis(dpg.mvXAxis, label="t (seconds)")
                dpg.add_plot_axis(dpg.mvYAxis, label="y", tag="y_axis")
                series_uuids += [dpg.generate_uuid() for _ in labels]
                # add line series
                for uuid, label, i in zip(series_uuids, labels, range(len(labels))):
                    dpg.add_line_series(dataseries_x.tolist(), dataseries[:,i].tolist(), label=label, parent="y_axis", tag=uuid)
        with dpg.child_window(tag="plot_buttons_child", height=50):
            with dpg.group(horizontal=True):
                dpg.add_button(label="Serial Port", tag="serial_button", height=30, callback=show_serial_chooser)
                dpg.add_button(label="Start", tag="start_btn", height=30, callback = startplot)
                dpg.add_button(label="Save", tag="save_btn", height=30, callback = lambda: dpg.show_item('file_dialog_id'))
    with dpg.item_handler_registry(tag="plot_win_registry"):
        dpg.add_item_resize_handler(callback = plot_resize_cb)
    dpg.bind_item_handler_registry("plot_window","plot_win_registry")
    dpg.set_primary_window("plot_window", True)

    # file picker for the save button. not shown until save is clicked
    with dpg.file_dialog(tag='file_dialog_id', show=False, callback=saveplot, cancel_callback=plotcancel,
                        width=700, height=400, directory_selector=False, modal=True):
        dpg.add_file_extension("Excel (.xlsx){.xlsx}")

def plot_resize_cb():
    winsize = dpg.get_item_rect_size("plot_child")
    dpg.set_item_height("main_plot", winsize[1] - 40)
    dpg.set_item_width("main_plot", winsize[0] - 20)

def update_plot_data():
    for uuid, i in zip(series_uuids, range(len(labels))):
        dpg.set_value(uuid, [dataseries_x.tolist(), dataseries[:,i].tolist()])

def new_data_received(newdata):
    global dataseries
    # should be a 10 member tuple
    # first member is the timestamp. we can ignore it for now
    dataseries = np.roll(dataseries, axis=0, shift=-1)
    dataseries[-1,:] = np.asarray(newdata[1:]).T

def serial_chooser_ui():
    with(dpg.window(label="Serial Port", tag = "serial_window", show=False, modal= True, width=400)):
        dpg.add_text("No comport connected", tag="serial_info")
        dpg.add_listbox(tag="serial_listbox", callback=serial_listbox_cb)
        dpg.add_button(label="Connect", tag="serial_connect_btn", callback = serial_connect_cb)

def serial_listbox_cb(sender, appdata, userdata):
    global selected_comport
    # read all the values currently in the listbox
    allitems = dpg.get_item_configuration(sender)['items']
    for count, item in enumerate(allitems):
        if(item == appdata):
            #print('item #{} was chosen'.format(count))
            selected_comport = count

def serial_connect_cb(sender, appdata, userdata):
    global comport_connected
    global flatmcu
    global mythread
    global data_on
    #print('connecting to {}'.format(all_comports[selected_comport]))

    if(not comport_connected):
        try:
            flatmcu = serial.Serial(all_comports[selected_comport])
            mythread = CobsReceiver()
            mythread.set_port(flatmcu)
            mythread.set_data_callback(new_data_received)
            mythread.start()
            comport_connected = True
            dpg.configure_item("serial_connect_btn", label="Disconnect")
            dpg.configure_item("start_btn", label="Stop")
            data_on = True
            dpg.set_value("serial_info", "Connected to {}".format(all_comports[selected_comport]))
        except serial.SerialException:
            dpg.set_value("serial_info", "Could not connect to {}".format(all_comports[selected_comport]))
    else:
        mythread.stop()
        flatmcu.close()
        comport_connected = False
        dpg.configure_item("serial_connect_btn", label="Connect")
        dpg.set_value("serial_info", "No comport connected")
        dpg.configure_item("start_btn", label="Start")
        data_on = False

def show_serial_chooser():
    global all_comports
    dpg.show_item("serial_window")
    serial_ports = serial.tools.list_ports.comports()
    all_comports = [port.name for port in serial_ports]
    all_comport_desc = [port.description for port in serial_ports]
    dpg.configure_item("serial_listbox", items=list(map(lambda a: a[0]+" "+a[1], zip(all_comports, all_comport_desc))))

def set_plot_length(caller, appdata, userdata):
    global dataseries_x
    global dataseries
    #dpg.get_item_configuration("plot_length_slider")
    #print(dpg.get_value("plot_length_slider"))
    new_x_series = np.arange(0, dpg.get_value("plot_length_slider"), data_period)
    if(new_x_series.size != dataseries_x.size):
        if(new_x_series.size < dataseries_x.size):
            dataseries = dataseries[-new_x_series.size:, :]
            dataseries_x = new_x_series
        else:
            dataseries = np.vstack((np.zeros((new_x_series.size - dataseries_x.size,dataseries.shape[1])), dataseries ))
            dataseries_x = new_x_series

def plot_config_ui():
    with dpg.window(label="Plot Config", tag="plot_config_window", show=False, modal=True, autosize=True):
        dpg.add_slider_int(label="Plot length (seconds)", tag="plot_length_slider", min_value=1, max_value=10, default_value=5)
        dpg.add_button(label="Set Plot Length", callback=set_plot_length)

def show_plot_configuration():
    dpg.show_item("plot_config_window")

def main():
    #flatmcu = serial.Serial("COM3")
    #mythread = CobsReceiver()
    #mythread.set_port(flatmcu)
    #mythread.set_data_callback(new_data_received)

    dpg.create_context()

    create_ui()
    serial_chooser_ui()
    plot_config_ui()

    dpg.create_viewport(title='Motor Plot', width=800, height=600)
    with dpg.viewport_menu_bar():
        with dpg.menu(label="Plot"):
            dpg.add_menu_item(label="Configure plot length", callback = show_plot_configuration)
        with dpg.menu(label="Serial"):
            dpg.add_menu_item(label="Select Serial Port", callback = show_serial_chooser)
    dpg.setup_dearpygui()
    dpg.show_viewport()
    #mythread.start()
    while(dpg.is_dearpygui_running()):
        time.sleep(1.0/FRAME_RATE)
        update_plot_data()
        dpg.render_dearpygui_frame()

    if(mythread.is_running()):
        mythread.stop()
    if(flatmcu.is_open):
        flatmcu.close()

    dpg.destroy_context()

if __name__ == '__main__':
    main()