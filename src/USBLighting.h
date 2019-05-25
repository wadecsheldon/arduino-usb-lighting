#ifndef USBLIGHTING_H	//include guard
#define USBLIGHTING_H

#include "USBCommon.h"

typedef struct {
	uint8_t id;
	uint16_t len;
} LightingReport;

class USBLighting_ : public PluggableUSBModule {
	protected:
		EPTYPE_DESC_SIZE epType[1];
		uint8_t idle;
		uint8_t protocol;
		uint8_t state = 0;
		uint8_t report_id = 0;
		uint16_t report_len = 0;
		bool updated = false;
		
		int getInterface(uint8_t* interfaceNum);
		int getDescriptor(USBSetup& setup);
		uint8_t getShortName(char* name);
		bool setup(USBSetup& setup);

	public:
		USBLighting_(void);
		uint8_t getState(void);
		LightingReport getReport(void);
};

extern USBLighting_ USBLighting;


#endif	//include guard