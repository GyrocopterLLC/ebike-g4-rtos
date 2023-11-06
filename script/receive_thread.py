import struct
import serial
from cobs import cobs
from threading import Thread

class CobsReceiver:

    def __init__(self):
        self.quitting_now = False
        self.rxport = None
        self.cback = None

    def stop(self):
        self.quitting_now = True
        if(hasattr(self,'mythread')):
            if(self.mythread.is_alive()):
                self.mythread.join()

    def set_port(self, comport:serial.Serial):
        self.rxport = comport

    def set_data_callback(self, callback_fcn):
        self.cback = callback_fcn

    def start(self):
        self.mythread = Thread(target=self._run, daemon=True)
        self.mythread.start()

    def is_running(self):
        return self.mythread.is_alive() if hasattr(self,'mythread') else False        
        #return self.mythread.is_alive()
    
    def start_data(self):
        self.rxport.write(b'D')

    def stop_data(self):
        self.rxport.write(b'd')

    def _run(self):
        #print('thread started')
        self.quitting_now = False
        if(self.rxport is None):
            return
        buff = bytearray()
        # send the start command
        self.rxport.write(b'D')
        while(not self.quitting_now):

            if(self.rxport.in_waiting > 0):
                buff.extend(self.rxport.read(self.rxport.in_waiting))
                ### TODO:
                #   This needs to loop as long as valid COBS frames are in the
                #   buffer. Right now, if the buffer has backed up with COBS
                #   frames, only one will be removed at a time. This could
                #   end up with a big backlog of frames in the buffer.
            if(buff.find(b'\x00')):
                try:
                    decoded = cobs.decode(bytes(buff[:buff.find(b'\x00')]))
                    # Check tag
                    if(decoded[0] == 1):
                        # check length 
                        if(decoded[1] == (len(decoded) - 2)):
                            outs = struct.unpack('<IfBfffffffffff',decoded[2:])
                            #fil.write('{}, {:.3f}, {}, {:.3f}, {:.3f}, {:.3f}, {:.3f}, {:.3f}, {:.3f}, {:.3f},'.format(*outs))
                            #fil.write('0x'+' 0x'.join(['{:02X}'.format(bb) for bb in buff[:buff.find(b'\x00')]]))
                            #fil.write(',\n')
                            #listcount = listcount + 1
                            #if(listcount == 4000):
                            #    done = True
                            if(self.cback):
                                self.cback(outs)
                    buff = buff[1+buff.find(b'\x00'):] # remove that frame
                except:
                    # discard it 
                    buff = buff[1+buff.find(b'\x00'):]
        # send the stop command
        self.rxport.write(b'd')
        #print('thread finished')