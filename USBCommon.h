/*
	Common includes, values, and macros for working with USB on different architectures
*/

#if defined(ARDUINO_ARCH_AVR)

	#include "PluggableUSB.h"
	
	#define EPTYPE_SIZE uint8_t
	#define EP_TYPE_INTERRUPT_IN 


#elif defined(ARDUINO_ARCH_SAM)

	#include "USB/PluggableUSB.h"
	
	#define EPTYPE_SIZE uint32_t


#elif defined(ARDUINO_ARCH_SAMD)

	#include "USB/PluggableUSB.h"
	
	#define EPTYPE_SIZE uint32_t


#else
	#error "Unsupported architecture"
#endif