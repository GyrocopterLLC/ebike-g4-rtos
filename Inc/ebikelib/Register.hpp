#ifndef REGISTER_HPP_
#define REGISTER_HPP_

#pragma once

#include <cstdint>
#include <type_traits>
#include <string>

using device_register = uint32_t volatile;
using device_register16 = uint16_t volatile;
using device_register8 = uint8_t volatile;

namespace Register {

	template<bool tf>
	constexpr uint32_t _bit(){
		if constexpr(tf) return 1;
		else return 0;
	}

	template<typename rtype, uint8_t bit_offset, bool tf>
	struct Combo_Bit {
		static const uint32_t mask = (static_cast<uint32_t>(1u) << bit_offset);
		static const uint32_t value = (_bit<tf>() << bit_offset);
		static const rtype regtype;
	};

	template<typename rtype, uint8_t bit_offset, uint8_t bit_length, typename fieldtype, fieldtype newval>
	struct Combo_Bitfield {
		static const uint32_t mask = (((static_cast<uint32_t>(1u) << bit_length) - 1u) << bit_offset);
		static const uint32_t value = (static_cast<uint32_t>(newval) << bit_offset);
		static const rtype regtype;
	};

	template<typename rtype, uint32_t register_address>
	class Register{
	public:
		template<typename rctype>
		static constexpr bool check_type() {
			return std::is_same<const rtype, rctype>::value;
		}

		template<typename A, typename... As>
		constexpr uint32_t get_bits() {
			static_assert(check_type<decltype(A::regtype)>());
			if constexpr(sizeof...(As) > 0) {
				return A::value + get_bits<As...>();
			} else {
				return A::value;
			}
		}

		template<typename A, typename... As>
		constexpr uint32_t get_mask() {
			static_assert(check_type<decltype(A::regtype)>());
			if constexpr(sizeof...(As) > 0) {
				return A::mask + get_mask<As...>();
			} else {
				return A::mask;
			}
		}


		template<typename... As>
		void apply() {
			auto mask = get_mask<As...>();
			auto bits = get_bits<As...>();
			device_register* devreg = reinterpret_cast<device_register*>(register_address);
			uint32_t tempreg = *devreg & (~mask);
			if(bits != 0) {
				tempreg = tempreg | bits;
			}
			*devreg = tempreg;
		}

		uint32_t get() {
			return *reinterpret_cast<uint32_t*>(register_address);
		}

		void set(uint32_t newval) {
			device_register* devreg = reinterpret_cast<device_register*>(register_address);
			*devreg = newval;
		}
	};

	template<typename rtype, uint32_t register_address>
	class Register16{
	public:
		template<typename rctype>
		static constexpr bool check_type() {
			return std::is_same<const rtype, rctype>::value;
		}

		template<typename A, typename... As>
		constexpr uint16_t get_bits() {
			static_assert(check_type<decltype(A::regtype)>());
			if constexpr(sizeof...(As) > 0) {
				return A::value + get_bits<As...>();
			} else {
				return A::value;
			}
		}

		template<typename A, typename... As>
		constexpr uint16_t get_mask() {
			static_assert(check_type<decltype(A::regtype)>());
			if constexpr(sizeof...(As) > 0) {
				return A::mask + get_mask<As...>();
			} else {
				return A::mask;
			}
		}


		template<typename... As>
		void apply() {
			auto mask = get_mask<As...>();
			auto bits = get_bits<As...>();
			device_register16* devreg = reinterpret_cast<device_register16*>(register_address);
			uint16_t tempreg = *devreg & (~mask);
			if(bits != 0) {
				tempreg = tempreg | bits;
			}
			*devreg = tempreg;
		}

		uint16_t get() {
			return *reinterpret_cast<uint16_t*>(register_address);
		}

		void set(uint16_t newval) {
			device_register16* devreg = reinterpret_cast<device_register16*>(register_address);
			*devreg = newval;
		}
	};

	template<typename rtype, uint32_t register_address>
	class Register8{
	public:
		template<typename rctype>
		static constexpr bool check_type() {
			return std::is_same<const rtype, rctype>::value;
		}

		template<typename A, typename... As>
		constexpr uint8_t get_bits() {
			static_assert(check_type<decltype(A::regtype)>());
			if constexpr(sizeof...(As) > 0) {
				return A::value + get_bits<As...>();
			} else {
				return A::value;
			}
		}

		template<typename A, typename... As>
		constexpr uint8_t get_mask() {
			static_assert(check_type<decltype(A::regtype)>());
			if constexpr(sizeof...(As) > 0) {
				return A::mask + get_mask<As...>();
			} else {
				return A::mask;
			}
		}


		template<typename... As>
		void apply() {
			auto mask = get_mask<As...>();
			auto bits = get_bits<As...>();
			device_register8* devreg = reinterpret_cast<device_register8*>(register_address);
			uint8_t tempreg = *devreg & (~mask);
			if(bits != 0) {
				tempreg = tempreg | bits;
			}
			*devreg = tempreg;
		}

		uint8_t get() {
			return *reinterpret_cast<uint8_t*>(register_address);
		}

		void set(uint8_t newval) {
			device_register8* devreg = reinterpret_cast<device_register8*>(register_address);
			*devreg = newval;
		}
	};

	template<uint32_t register_address, uint8_t bit_offset>
	class Bit {
	public:
		Bit() = default;

		bool get() {
			device_register* devreg = reinterpret_cast<device_register*>(register_address);
			return ((*devreg) & (static_cast<uint32_t>(1u) << bit_offset)) != 0;
		}

		void set(bool tf) {
			device_register* devreg = reinterpret_cast<device_register*>(register_address);
			if(tf) {
				*devreg = *devreg | (static_cast<uint32_t>(1u) << bit_offset);
			} else {
				*devreg = *devreg & (~(static_cast<uint32_t>(1u) << bit_offset));
			}
		}
	};

	// bit_offset is the position of the lowest bit in the field
	template<uint32_t register_address, uint8_t bit_offset, uint8_t bit_length, typename T>
	class Bitfield {
	public:
		Bitfield() = default;

		T get() {
			device_register* devreg = reinterpret_cast<device_register*>(register_address);
			if constexpr (bit_length == 32) { // specialize for full register
				return static_cast<T>(*devreg);
			} else {

				uint32_t bit_mask = (static_cast<uint32_t>(1u) << bit_length) - 1u;

				return static_cast<T>(((*devreg) & (bit_mask << bit_offset)) >> bit_offset);
			}
		}

		void set(T newval) {
			device_register* devreg = reinterpret_cast<device_register*>(register_address);
			if constexpr (bit_length == 32) {
				*devreg = static_cast<uint32_t>(newval);
			} else {
				uint32_t bit_mask = (static_cast<uint32_t>(1u) << bit_length) - 1u;

				uint32_t tempreg = *devreg;
				tempreg = tempreg & (~(bit_mask << bit_offset)); // clear the field
				tempreg = tempreg | (static_cast<uint32_t>(newval) << bit_offset);
				*devreg = tempreg;
			}
		}
	};

} // namespace Register
#endif // REGISTER_HPP_
