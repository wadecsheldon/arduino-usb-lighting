#ifndef USBLIGHTINGDEFS_H
#define USBLIGHTINGDEFS_H

// Report IDs
#define LampArrayAttributesReportID		0x01
#define LampAttributeRequestReportID	0x02
#define LampAttributesReponseReportID	0x03
#define LampMultiUpdateReportID			0x04
#define LampRangeUpdateReportID			0x05
#define LampArrayControlReportID		0x06

// Report lengths
#define LampArrayAttributesReportID		0x01
#define LampAttributeRequestReportID	0x02
#define LampAttributesReponseReportID	0x03
#define LampMultiUpdateReportID			0x04
#define LampRangeUpdateReportID			0x05
#define LampArrayControlReportID		0x06

// Report descriptor for HID Lighting and Illumination
static const uint8_t _hidReportDescriptorLighting[] PROGMEM = {
    0x05, 0x59,					// USAGE_PAGE (LightingAndIllumination)
    0x09, 0x01,					// USAGE (LampArray)
    0xA1, 0x01,					// COLLECTION (Application)
	
	0x85, 0x01,						// REPORT_ID (1)
    0x09, 0x02,						// USAGE (LampArrayAttributesReport)
    0xA1, 0x02,						// COLLECTION (Logical)
	0x09, 0x03,							// USAGE (LampCount)
	0x15, 0x00,							// LOGICAL_MINIMUM (0)
	0x27, 0xFF, 0xFF, 0x00, 0x00,		// LOGICAL_MAXIMUM (65535)
	0x75, 0x10,							// REPORT_SIZE (16)
	0x95, 0x01,							// REPORT_COUNT (1)
	0xB1, 0x03,							// FEATURE (Cnst, Var, Abs)
	0x09, 0x04,							// USAGE (BoundingBoxWidthInMicrometers)
	0x09, 0x05,							// USAGE (BoundingBoxHeightInMicrometers)
	0x09, 0x06,							// USAGE (BoundingBoxDepthInMicrometers)
	0x09, 0x07,							// USAGE (LampArrayKind)
	0x09, 0x08,							// USAGE (MinUpdateIntervalInMicroseconds)
	0x15, 0x00,							// LOGICAL_MINIMUM (0)
	0x27, 0xff, 0xff, 0xff, 0x7f,		// LOGICAL_MAXIMUM (2147483647)
	0x75, 0x20,							// REPORT_SIZE (32)
	0x95, 0x05,							// REPORT_COUNT (5)
	0xb1, 0x03,							// FEATURE (Cnst,Var,Abs)
	0xc0,							// END_COLLECTION
	
	0x85, 0x02,						// REPORT_ID (2)
	0x09, 0x20,						// USAGE (LampAttributesRequestReport)
	0xa1, 0x02,						// COLLECTION (Logical)
	0x09, 0x21,							// USAGE (LampId)
	0x15, 0x00,							// LOGICAL_MINIMUM (0)
	0x27, 0xff, 0xff, 0x00, 0x00,		// LOGICAL_MAXIMUM (65535)
	0x75, 0x10,							// REPORT_SIZE (16)
	0x95, 0x01,							// REPORT_COUNT (1)
	0xb1, 0x02,							// FEATURE (Data,Var,Abs)
	0xc0,							// END_COLLECTION
	
	0x85, 0x03,						// REPORT_ID (3)
	0x09, 0x22,						// USAGE (LampAttributesReponseReport)
	0xa1, 0x02,						// COLLECTION (Logical)
	0x09, 0x21,							// USAGE (LampId)
	0x15, 0x00,							// LOGICAL_MINIMUM (0)
	0x27, 0xff, 0xff, 0x00, 0x00,		// LOGICAL_MAXIMUM (65535)
	0x75, 0x10,							// REPORT_SIZE (16)
	0x95, 0x01,							// REPORT_COUNT (1)
	0xb1, 0x02,							// FEATURE (Data,Var,Abs)
	0x09, 0x23,							// USAGE (PositionXInMicrometers)
	0x09, 0x24,							// USAGE (PositionYInMicrometers)
	0x09, 0x25,							// USAGE (PositionZInMicrometers)
	0x09, 0x27,							// USAGE (UpdateLatencyInMicroseconds)
	0x09, 0x26,							// USAGE (LampPurposes)
	0x15, 0x00,							// LOGICAL_MINIMUM (0)
	0x27, 0xff, 0xff, 0xff, 0x7f,		// LOGICAL_MAXIMUM (2147483647)
	0x75, 0x20,							// REPORT_SIZE (32)
	0x95, 0x05,							// REPORT_COUNT (5)
	0xb1, 0x02,							// FEATURE (Data,Var,Abs)
	0x09, 0x28,							// USAGE (RedLevelCount)
	0x09, 0x29,							// USAGE (GreenLevelCount)
	0x09, 0x2a,							// USAGE (BlueLevelCount)
	0x09, 0x2b,							// USAGE (IntensityLevelCount)
	0x09, 0x2c,							// USAGE (IsProgrammable)
	0x09, 0x2d,							// USAGE (InputBinding)
	0x15, 0x00,							// LOGICAL_MINIMUM (0)
	0x26, 0xff, 0x00,					// LOGICAL_MAXIMUM (255)
	0x75, 0x08,							// REPORT_SIZE (8)
	0x95, 0x06,							// REPORT_COUNT (6)
	0xb1, 0x02,							// FEATURE (Data,Var,Abs)
	0xc0,							// END_COLLECTION
	
	0x85, 0x04,						// REPORT_ID (4)
	0x09, 0x50,						// USAGE (LampMultiUpdateReport)
	0xa1, 0x02,						// COLLECTION (Logical)
	0x09, 0x03,							// USAGE (LampCount)
	0x09, 0x55,							// USAGE (LampUpdateFlags)
	0x15, 0x00,							// LOGICAL_MINIMUM (0)
	0x25, 0x08,							// LOGICAL_MAXIMUM (8)
	0x75, 0x08,							// REPORT_SIZE (8)
	0x95, 0x02, 						// REPORT_COUNT (2)
	0xb1, 0x02, 						// FEATURE (Data,Var,Abs)
	0x09, 0x21, 						// USAGE (LampId)
	0x15, 0x00, 						// LOGICAL_MINIMUM (0)
	0x27, 0xff, 0xff, 0x00, 0x00, 		// LOGICAL_MAXIMUM (65535)
	0x75, 0x10, 						// REPORT_SIZE (16)
	0x95, 0x08, 						// REPORT_COUNT (8)
	0xb1, 0x02, 						// FEATURE (Data,Var,Abs)
	0x09, 0x51, 						// USAGE (RedUpdateChannel)
	0x09, 0x52, 						// USAGE (GreenUpdateChannel)
	0x09, 0x53, 						// USAGE (BlueUpdateChannel)
	0x09, 0x54, 						// USAGE (IntensityUpdateChannel)
	0x09, 0x51, 						// USAGE (RedUpdateChannel)
	0x09, 0x52, 						// USAGE (GreenUpdateChannel)
	0x09, 0x53, 						// USAGE (BlueUpdateChannel)
	0x09, 0x54, 						// USAGE (IntensityUpdateChannel)
	0x09, 0x51, 						// USAGE (RedUpdateChannel)
	0x09, 0x52, 						// USAGE (GreenUpdateChannel)
	0x09, 0x53, 						// USAGE (BlueUpdateChannel)
	0x09, 0x54, 						// USAGE (IntensityUpdateChannel)
	0x09, 0x51, 						// USAGE (RedUpdateChannel)
	0x09, 0x52, 						// USAGE (GreenUpdateChannel)
	0x09, 0x53, 						// USAGE (BlueUpdateChannel)
	0x09, 0x54, 						// USAGE (IntensityUpdateChannel)
	0x09, 0x51, 						// USAGE (RedUpdateChannel)
	0x09, 0x52, 						// USAGE (GreenUpdateChannel)
	0x09, 0x53, 						// USAGE (BlueUpdateChannel)
	0x09, 0x54, 						// USAGE (IntensityUpdateChannel)
	0x09, 0x51, 						// USAGE (RedUpdateChannel)
	0x09, 0x52, 						// USAGE (GreenUpdateChannel)
	0x09, 0x53, 						// USAGE (BlueUpdateChannel)
	0x09, 0x54, 						// USAGE (IntensityUpdateChannel)
	0x09, 0x51, 						// USAGE (RedUpdateChannel)
	0x09, 0x52, 						// USAGE (GreenUpdateChannel)
	0x09, 0x53, 						// USAGE (BlueUpdateChannel)
	0x09, 0x54, 						// USAGE (IntensityUpdateChannel)
	0x09, 0x51, 						// USAGE (RedUpdateChannel)
	0x09, 0x52, 						// USAGE (GreenUpdateChannel)
	0x09, 0x53, 						// USAGE (BlueUpdateChannel)
	0x09, 0x54, 						// USAGE (IntensityUpdateChannel)
	0x15, 0x00, 						// LOGICAL_MINIMUM (0)
	0x26, 0xff, 0x00, 					// LOGICAL_MAXIMUM (255)
	0x75, 0x08, 						// REPORT_SIZE (8)
	0x95, 0x20, 						// REPORT_COUNT (32)
	0xb1, 0x02, 						// FEATURE (Data,Var,Abs)
	0xc0, 							// END_COLLECTION
	
	0x85, 0x05, 					// REPORT_ID (5)
	0x09, 0x60, 					// USAGE (LampRangeUpdateReport)
	0xa1, 0x02, 					// COLLECTION (Logical)
	0x09, 0x55, 						// USAGE (LampUpdateFlags)
	0x15, 0x00, 						// LOGICAL_MINIMUM (0)
	0x25, 0x08, 						// LOGICAL_MAXIMUM (8)
	0x75, 0x08, 						// REPORT_SIZE (8)
	0x95, 0x01, 						// REPORT_COUNT (1)
	0xb1, 0x02, 						// FEATURE (Data,Var,Abs)
	0x09, 0x61, 						// USAGE (LampIdStart)
	0x09, 0x62, 						// USAGE (LampIdEnd)
	0x15, 0x00, 						// LOGICAL_MINIMUM (0)
	0x27, 0xff, 0xff, 0x00, 0x00, 		// LOGICAL_MAXIMUM (65535)
	0x75, 0x10, 						// REPORT_SIZE (16)
	0x95, 0x02, 						// REPORT_COUNT (2)
	0xb1, 0x02, 						// FEATURE (Data,Var,Abs)
	0x09, 0x51, 						// USAGE (RedUpdateChannel)
	0x09, 0x52, 						// USAGE (GreenUpdateChannel)
	0x09, 0x53, 						// USAGE (BlueUpdateChannel)
	0x09, 0x54, 						// USAGE (IntensityUpdateChannel)
	0x15, 0x00, 						// LOGICAL_MINIMUM (0)
	0x26, 0xff, 0x00, 					// LOGICAL_MAXIMUM (255)
	0x75, 0x08, 						// REPORT_SIZE (8)
	0x95, 0x04, 						// REPORT_COUNT (4)
	0xb1, 0x02, 						// FEATURE (Data,Var,Abs)
	0xc0, 							// END_COLLECTION
	
    0x85, 0x06,         			// REPORT_ID (6)
    0x09, 0x70,         			// USAGE (LampArrayControlReport)
    0xA1, 0x02,         			// COLLECTION (Logical)
    0x09, 0x71,           				// USAGE (AutonomousMode)
    0x15, 0x00,           				// LOGICAL_MINIMUM (0)
    0x25, 0x01,           				// LOGICAL_MAXIMUM (1)
    0x75, 0x08,           				// REPORT_SIZE (8)
    0x95, 0x01,           				// REPORT_COUNT (1)
    0xB1, 0x02,           				// FEATURE (Data, Var, Abs)
    0xC0,               			// END_COLLECTION
	
    0xC0              			// END_COLLECTION
};

#endif