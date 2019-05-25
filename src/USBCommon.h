#ifndef USBCOMMON_H
#define USBCOMMON_H

/*
	Common includes, constants, and functions to help remove the inconsistencies of the builtin USB libraries.
*/

#if defined(ARDUINO_ARCH_AVR)

	#include "PluggableUSB.h"
	
	#define EPTYPE_DESC_SIZE uint8_t
	#define EP_BUF_SIZE USB_EP_SIZE
	#define CTRL_BUF_SIZE USB_EP_SIZE
	
	enum class EndpointType: EPTYPE_DESC_SIZE
	{
		kInterruptIn = EP_TYPE_INTERRUPT_IN,
		kInterruptOut = EP_TYPE_INTERRUPT_OUT,
		kBulkIn = EP_TYPE_BULK_IN,
		kBulkOut = EP_TYPE_BULK_OUT,
		kIsochronousIn = EP_TYPE_ISOCHRONOUS_IN,
		kIsochronousOut = EP_TYPE_ISOCHRONOUS_OUT
	};
	
	inline int USBSendControl(uint8_t flags, const void* data, uint32_t length) { return USB_SendControl(flags, data, static_cast<int>(length)); }
	inline int USBRecvControl(void* data, uint32_t length) { return USB_RecvControl(data, length); }
	inline int USBAvailable(uint32_t endpoint) { return USB_Available(static_cast<uint8_t>(endpoint & 0xFF)); }
	inline int USBSend(uint32_t endpoint, const void* data, uint32_t length) { return USB_Send(static_cast<uint8_t>(endpoint & 0xFF), data, static_cast<int>(length)); }
	inline int USBRecv(uint32_t endpoint, void* data, uint32_t length) { return USB_Recv(static_cast<uint8_t>(endpoint & 0xFF), data, static_cast<int>(length)); }
	inline int USBRecv(uint32_t endpoint) { return USB_Recv(static_cast<uint8_t>(endpoint & 0xFF)); }
	inline void USBFlush(uint32_t endpoint) { USB_Flush(static_cast<uint8_t>(endpoint & 0xFF)); }
	


#elif defined(ARDUINO_ARCH_SAM)

	#include "USB/PluggableUSB.h"
	
	#define EPTYPE_DESC_SIZE uint32_t
	#define EP_BUF_SIZE EPX_SIZE
	#define CTRL_BUF_SIZE EP0_SIZE
	
	// Transfer flags copied from AVR for code compatability, ultimately ignored
	#define TRANSFER_PGM		0x80
	#define TRANSFER_RELEASE	0x40
	#define TRANSFER_ZERO		0x20
	
	enum class EndpointType: EPTYPE_DESC_SIZE
	{
		kInterruptIn = EP_TYPE_INTERRUPT_IN,
		kInterruptOut = EP_TYPE_INTERRUPT_OUT,
		kBulkIn = EP_TYPE_BULK_IN,
		kBulkOut = EP_TYPE_BULK_OUT,
		kIsochronousIn = EP_TYPE_ISOCHRONOUS_IN,
		kIsochronousOut = EP_TYPE_ISOCHRONOUS_OUT
	};
	
	inline int USBSendControl(uint8_t flags, const void* data, uint32_t length) { return USBD_SendControl(flags, data, length); }
	inline int USBRecvControl(void* data, uint32_t length) { return USBD_RecvControl(data, length); }
	inline int USBAvailable(uint32_t endpoint) { return static_cast<int>(USBD_Available(endpoint)); }
	inline int USBSend(uint32_t endpoint, const void* data, uint32_t length) { return static_cast<int>(USBD_Send(endpoint, data, length)); }
	inline int USBRecv(uint32_t endpoint, void* data, uint32_t length) { return static_cast<int>(USBD_Recv(endpoint, data, length)); }
	inline int USBRecv(uint32_t endpoint) { return static_cast<int>(USBD_Recv(endpoint)); }
	inline void USBFlush(uint32_t endpoint) { USBD_Flush(endpoint); }


#elif defined(ARDUINO_ARCH_SAMD)

	#include "USB/PluggableUSB.h"
	
	#define EPTYPE_DESC_SIZE uint32_t
	#define EP_BUF_SIZE EPX_SIZE
	#define CTRL_BUF_SIZE EPX_SIZE
	
	// Transfer flags copied from AVR for code compatability, ultimately ignored
	#define TRANSFER_PGM		0x80
	#define TRANSFER_RELEASE	0x40
	#define TRANSFER_ZERO		0x20
	
	enum class EndpointType: EPTYPE_DESC_SIZE
	{
		kInterruptIn = USB_ENDPOINT_TYPE_INTERRUPT | USB_ENDPOINT_IN(0),
		kInterruptOut = USB_ENDPOINT_TYPE_INTERRUPT | USB_ENDPOINT_OUT(0),
		kBulkIn = USB_ENDPOINT_TYPE_BULK | USB_ENDPOINT_IN(0),
		kBulkOut = USB_ENDPOINT_TYPE_BULK | USB_ENDPOINT_OUT(0),
		kIsochronousIn = USB_ENDPOINT_TYPE_ISOCHRONOUS | USB_ENDPOINT_IN(0),
		kIsochronousOut = USB_ENDPOINT_TYPE_ISOCHRONOUS | USB_ENDPOINT_OUT(0)
	};
	
	inline int USBSendControl(uint8_t /* flags */, const void* data, uint32_t length) { return static_cast<int>(USBDevice.sendControl(data, length)); }
	inline int USBRecvControl(void* data, uint32_t length) { return static_cast<int>(USBDevice.recvControl(data, length)); }
	inline int USBAvailable(uint32_t endpoint) { return static_cast<int>(USBDevice.available(endpoint)); }
	inline int USBSend(uint32_t endpoint, const void* data, uint32_t length) { return static_cast<int>(USBDevice.send(endpoint, data, length)); }
	inline int USBRecv(uint32_t endpoint, void* data, uint32_t length) { return static_cast<int>(USBDevice.recv(endpoint, data, length)); }
	inline int USBRecv(uint32_t endpoint) { return static_cast<int>(USBDevice.recv(endpoint)); }
	inline void USBFlush(uint32_t endpoint) { USBDevice.flush(endpoint); }


#else
	#error "Unsupported architecture"
#endif

#endif // End include guard