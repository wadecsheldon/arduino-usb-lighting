#include "USBLighting.h"
#include "USBLightingDefinitions.h"
#include "HID.h"

USBLighting_::USBLighting_(void) : PluggableUSBModule(1, 1, epType) {
  epType[0] = USB_ENDPOINT_TYPE_INTERRUPT;
  PluggableUSB().plug(this);
}


int USBLighting_::getInterface(uint8_t* interfaceNum) {
  *interfaceNum += 1; // uses 1
  HIDDescriptor hidInterface = {
	D_INTERFACE(pluggedInterface, 1, USB_DEVICE_CLASS_HUMAN_INTERFACE, HID_SUBCLASS_NONE, HID_PROTOCOL_NONE),
	D_HIDREPORT(sizeof(_hidReportDescriptorLighting)),
	D_ENDPOINT(USB_ENDPOINT_IN(pluggedEndpoint), USB_ENDPOINT_TYPE_INTERRUPT, EP_BUF_SIZE, 0x01)
  };
  return USBSendControl(0, &hidInterface, sizeof(hidInterface));
}


int USBLighting_::getDescriptor(USBSetup& setup) {
  // Check if this is a HID Class Descriptor request
  if (setup.bmRequestType != REQUEST_DEVICETOHOST_STANDARD_INTERFACE) { return 0; }
  if (setup.wValueH != HID_REPORT_DESCRIPTOR_TYPE) { return 0; }

  // In a HID Class Descriptor wIndex cointains the interface number
  if (setup.wIndex != pluggedInterface) { return 0; }

  // Reset the protocol on reenumeration. Normally the host should not assume the state of the protocol
  // due to the USB specs, but Windows and Linux just assumes its in report mode.
  //protocol = HID_REPORT_PROTOCOL;

  return USBSendControl(TRANSFER_PGM, _hidReportDescriptorLighting, sizeof(_hidReportDescriptorLighting));
}


uint8_t USBLighting_::getShortName(char* name) {
	name[0] = 'L';
	name[1] = 'I';
	return 2;
}


bool USBLighting_::setup(USBSetup& setup) {
  if (pluggedInterface != setup.wIndex) {
	return false;
  }

  uint8_t request = setup.bRequest;
  uint8_t requestType = setup.bmRequestType;

  if (requestType == REQUEST_DEVICETOHOST_CLASS_INTERFACE)
  {
	if (request == HID_GET_REPORT) {
	  // TODO: HID_GetReport();
	  return true;
	}
	if (request == HID_GET_PROTOCOL) {
	  // TODO: Send8(protocol);
	  return true;
	}
  }

  if (requestType == REQUEST_HOSTTODEVICE_CLASS_INTERFACE)
  {
	if (request == HID_SET_PROTOCOL) {
	  protocol = setup.wValueL;
	  return true;
	}
	if (request == HID_SET_IDLE) {
	  idle = setup.wValueL;
	  return true;
	}
	if (request == HID_SET_REPORT)
	{
	  // Check if data has the correct length
	  uint8_t data[64];
	  if ((setup.wLength > 0) and (setup.wLength <= 64)) {
		report_len = USBRecvControl(&data, setup.wLength) - 1;
		report_id = data[0];
		state = data[1];
		updated = true;
		return true;
	  }
	}
  }
  return false;
}


uint8_t USBLighting_::getState(void) {
  return state;
}

LightingReport USBLighting_::getReport(void) {
  while (!updated) { delay(1); }
  updated = false;
  return {report_id, report_len};
}

	
	
USBLighting_ USBLighting;