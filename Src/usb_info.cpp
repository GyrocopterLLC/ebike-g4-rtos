#include "tusb.h"
#include "usb_info.h"
#include <cstdint>
#include <cstring>

/**
 * Create a usb info packet by adding fields of data, then calling send
 *
 */

using namespace EbikeLib;

bool USB_Info::add_data(void* new_data, uint32_t data_len) {
	if((data_len + current_length) <= buffer_length) {
		void* mybufstart = reinterpret_cast<void*>(reinterpret_cast<uint32_t>(packet_buffer) + current_length);
		memcpy(mybufstart, new_data, data_len);
		current_length += data_len;
		return true;
	} else { return false; }
}

void USB_Info::send() {
	tud_cdc_write(packet_buffer, current_length);
	//tud_cdc_write_flush(); // check if this is needed
	current_length = 0;
}
