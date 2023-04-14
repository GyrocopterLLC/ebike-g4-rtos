#ifndef UTIL_HPP_
#define UTIL_HPP_

#pragma once

namespace EbikeLib {

class DelayTimer {
public:
	static DelayTimer & instance();
	void delay_us(uint16_t us);


private:
	DelayTimer(); // Construct is private, only the Meyer's singleton function "instance" can initialize

};

} // namespace EbikeLib

#endif /* UTIL_HPP_ */
