#ifndef USBLIGHTING_H	//include guard
#define USBLIGHTING_H

#include "USBCommon.h"

class USBLighting_ : public PluggableUSBModule {
	protected:
		uint8_t epType[1];
		uint8_t state = 0;
		uint8_t report_id = 0;
		uint8_t report_len = 0;
		
		int getInterface(uint8_t* interfaceNum);
		int getDescriptor(USBSetup& setup);
		uint8_t getShortName(char* name);
		bool setup(USBSetup& setup);

	public:
		USBLighting_(void);
		uint8_t getState(void);
		uint8_t getReportID(void);
		uint8_t getReportLength(void);
};

extern USBLighting_ USBLighting;


#endif	//include guard