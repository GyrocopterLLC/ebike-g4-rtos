/*
 * Buffer.hpp
 *
 *  Functions for communication buffers
 */

#ifndef BUFFER_HPP_
#define BUFFER_HPP_
#include <cstdint>


template <typename T>
void buffer_append(uint8_t* buffer, uint32_t &pointer, T* data) {
	memcpy(&(buffer[pointer]), data, sizeof(T));
	pointer += sizeof(T);
}



#endif /* BUFFER_HPP_ */
