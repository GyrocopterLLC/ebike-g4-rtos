#ifndef USB_INFO_H_
#define USB_INFO_H_

#pragma once

#include <cstdint>

namespace EbikeLib {

class USB_Info
{
public:
	USB_Info(void* pbuf, uint32_t maxlen)
		: packet_buffer(pbuf), buffer_length(maxlen), current_length(0) {};
	bool add_data(void* new_data, uint32_t data_len);
	void send();

private:
	void* packet_buffer;
	uint32_t buffer_length;
	uint32_t current_length;

};

} // namespace EbikeLib

#endif /* USB_INFO_H_ */
