#ifndef __LEVELIMAGE__
#define __LEVELIMAGE__

#include <Gamebuino-Meta.h>

const uint16_t BLUECAPSULEData[] = 
{
	5,      // frame width
	2,      // frame height
	2,      // number of frames
	10,      // animation speed
	0x0000, // transparent color
	0,      // RGB565 color mode
	// frame 1/2
	0x03df, 0x201f, 0x201f, 0x201f, 0x03df, 
	0x03df, 0x201f, 0x201f, 0x201f, 0x03df, 
	// frame 2/2
	0x0000, 0x201f, 0x201f, 0x201f, 0x0000, 
	0x0000, 0x201f, 0x201f, 0x201f, 0x0000
};

// Give a life
const uint16_t GREENCAPSULEData[] = 
{
	5,      // frame width
	2,      // frame height
	2,      // number of frames
	10,      // animation speed
	0x0000, // transparent color
	0,      // RGB565 color mode
	// frame 1/2
	0x07F2, 0x0641, 0x0641, 0x0641, 0x07F2, 
	0x07F2, 0x0641, 0x0641, 0x0641, 0x07F2, 
	// frame 2/2
	0x0000, 0x0641, 0x0641, 0x0641, 0x0000, 
	0x0000, 0x0641, 0x0641, 0x0641, 0x0000
};



Image IMG_CAPSULE_PROTECT = Image(BLUECAPSULEData);
Image IMG_CAPSULE_LIFE = Image(GREENCAPSULEData);

#endif
