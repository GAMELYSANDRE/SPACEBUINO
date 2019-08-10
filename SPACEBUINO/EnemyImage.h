#ifndef __ENEMYIMAGE__
#define __ENEMYIMAGE__

#include <Gamebuino-Meta.h>

const uint16_t CRABData[] =
{
  6,
  6,
  2,
  10,
  0x0000,
  0,
  //----          FIRST IMAGE             ----//
  0xffa0, 0x0000, 0x0000, 0x0000, 0x0000, 0xffa0,
  0x0000, 0xffa0, 0x0000, 0x0000, 0xffa0, 0x0000,
  0x0000, 0xfd40, 0xfd40, 0xfd40, 0xfd40, 0x0000,
  0xfd40, 0xfa60, 0xfd40, 0xfd40, 0xfa60, 0xfd40,
  0xfd40, 0xfd40, 0xfd40, 0xfd40, 0xfd40, 0xfd40,
  0x0000, 0xfd40, 0xfa60, 0xfa60, 0xfd40, 0x0000,
  //----          SECOND IMAGE            ----//
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
  0xffa0, 0xffa0, 0x0000, 0x0000, 0xffa0, 0xffa0,
  0x0000, 0xfd40, 0xfd40, 0xfd40, 0xfd40, 0x0000,
  0xfd40, 0xfa60, 0xfd40, 0xfd40, 0xfa60, 0xfd40,
  0xfd40, 0xfd40, 0xfd40, 0xfd40, 0xfd40, 0xfd40,
  0x0000, 0xfd40, 0xfd40, 0xfd40, 0xfd40, 0x0000
};
const uint16_t CRABREDData[] =
{
  6,
  6,
  2,
  10,
  0x0000,
  0,
  //----          FIRST IMAGE             ----//
  0xffa0, 0x0000, 0x0000, 0x0000, 0x0000, 0xffa0,
  0x0000, 0xffa0, 0x0000, 0x0000, 0xffa0, 0x0000,
  0x0000, 0x9AD6, 0x9AD6, 0x9AD6, 0x9AD6, 0x0000,
  0x9AD6, 0xfa60, 0x9AD6, 0x9AD6, 0xfa60, 0x9AD6,
  0x9AD6, 0x9AD6, 0x9AD6, 0x9AD6, 0x9AD6, 0x9AD6,
  0x0000, 0x9AD6, 0xfa60, 0xfa60, 0x9AD6, 0x0000,
  //----          SECOND IMAGE            ----//
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
  0xffa0, 0xffa0, 0x0000, 0x0000, 0xffa0, 0xffa0,
  0x0000, 0x9AD6, 0x9AD6, 0x9AD6, 0x9AD6, 0x0000,
  0x9AD6, 0xfa60, 0x9AD6, 0x9AD6, 0xfa60, 0x9AD6,
  0x9AD6, 0x9AD6, 0x9AD6, 0x9AD6, 0x9AD6, 0x9AD6,
  0x0000, 0x9AD6, 0x9AD6, 0x9AD6, 0x9AD6, 0x0000
};
const uint16_t SQUIDData[] =
{
  6,// LENGTH
  6,// WIDTH
  2,// NUMBER OF IMAGES
  10,// NUMBER OF IMAGES PER SECOND
  0x0000, // TRANSPARENCY COLOR
  0,
  //----          FIRST IMAGE             ----//
  0x0000, 0x0000, 0xAE40, 0xAE40, 0x0000, 0x0000,
  0x0000, 0xAE40, 0xAE40, 0xAE40, 0xAE40, 0x0000,
  0xAE40, 0xfa60, 0xAE40, 0xAE40, 0xfa60, 0xAE40,
  0xAE40, 0xAE40, 0xAE40, 0xAE40, 0xAE40, 0xAE40,
  0x0000, 0x3400, 0x3400, 0x3400, 0x3400, 0x0000,
  0x0000, 0x3400, 0x0000, 0x0000, 0x3400, 0x0000,
  //----          SECOND IMAGE            ----//
  0x0000, 0x0000, 0xAE40, 0xAE40, 0x0000, 0x0000,
  0x0000, 0xAE40, 0xAE40, 0xAE40, 0xAE40, 0x0000,
  0xAE40, 0xfa60, 0xAE40, 0xAE40, 0xfa60, 0xAE40,
  0xAE40, 0xAE40, 0xAE40, 0xAE40, 0xAE40, 0xAE40,
  0x0000, 0x3400, 0x3400, 0x3400, 0x3400, 0x0000,
  0x3400, 0x0000, 0x3400, 0x3400, 0x0000, 0x3400
};
const uint16_t SQUIDREDData[] =
{
  6,// LENGTH
  6,// WIDTH
  2,// NUMBER OF IMAGES
  10,// NUMBER OF IMAGES PER SECOND
  0x0000, // TRANSPARENCY COLOR
  0,
  //----          FIRST IMAGE             ----//
  0x0000, 0x0000, 0x9AD6, 0x9AD6, 0x0000, 0x0000,
  0x0000, 0x9AD6, 0x9AD6, 0x9AD6, 0x9AD6, 0x0000,
  0x9AD6, 0xfa60, 0x9AD6, 0x9AD6, 0xfa60, 0x9AD6,
  0x9AD6, 0x9AD6, 0x9AD6, 0x9AD6, 0x9AD6, 0x9AD6,
  0x0000, 0x3400, 0x3400, 0x3400, 0x3400, 0x0000,
  0x0000, 0x3400, 0x0000, 0x0000, 0x3400, 0x0000,
  //----          SECOND IMAGE            ----//
  0x0000, 0x0000, 0x9AD6, 0x9AD6, 0x0000, 0x0000,
  0x0000, 0x9AD6, 0x9AD6, 0x9AD6, 0x9AD6, 0x0000,
  0x9AD6, 0xfa60, 0x9AD6, 0x9AD6, 0xfa60, 0x9AD6,
  0x9AD6, 0x9AD6, 0x9AD6, 0x9AD6, 0x9AD6, 0x9AD6,
  0x0000, 0x3400, 0x3400, 0x3400, 0x3400, 0x0000,
  0x3400, 0x0000, 0x3400, 0x3400, 0x0000, 0x3400
};
const uint16_t SQUIDHITData[] =
{
  6,// LENGTH
  6,// WIDTH
  2,// NUMBER OF IMAGES
  10,// NUMBER OF IMAGES PER SECOND
  0x0000, // TRANSPARENCY COLOR
  0,
  //----          FIRST IMAGE             ----//
  0x0000, 0x0000, 0xF800, 0xF800, 0x0000, 0x0000,
  0x0000, 0xF800, 0xF800, 0xF800, 0xF800, 0x0000,
  0xF800, 0xfa60, 0xF800, 0xF800, 0xfa60, 0xF800,
  0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800,
  0x0000, 0x3400, 0x3400, 0x3400, 0x3400, 0x0000,
  0x0000, 0x3400, 0x0000, 0x0000, 0x3400, 0x0000,
  //----          SECOND IMAGE            ----//
  0x0000, 0x0000, 0xF800, 0xF800, 0x0000, 0x0000,
  0x0000, 0xF800, 0xF800, 0xF800, 0xF800, 0x0000,
  0xF800, 0xfa60, 0xF800, 0xF800, 0xfa60, 0xF800,
  0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800,
  0x0000, 0x3400, 0x3400, 0x3400, 0x3400, 0x0000,
  0x3400, 0x0000, 0x3400, 0x3400, 0x0000, 0x3400
};
const uint16_t OCTOPUSData[] =
{
  6,
  6,
  2,
  10,
  0x0000,
  0,
  //----          FIRST IMAGE             ----//
  0x0000, 0xCBBF, 0xCBBF, 0xCBBF, 0xCBBF, 0x0000,
  0xCBBF, 0xCBBF, 0xCBBF, 0xCBBF, 0xCBBF, 0xCBBF,
  0xCBBF, 0xfa60, 0xCBBF, 0xCBBF, 0xfa60, 0xCBBF,
  0xCBBF, 0xCBBF, 0xCBBF, 0xCBBF, 0xCBBF, 0xCBBF,
  0x0000, 0xb01a, 0xb01a, 0xb01a, 0xb01a, 0x0000,
  0xb01a, 0x0000, 0xb01a, 0xb01a, 0x0000, 0xb01a,
  //----          SECOND IMAGE            ----//
  0x0000, 0xCBBF, 0xCBBF, 0xCBBF, 0xCBBF, 0x0000,
  0xCBBF, 0xCBBF, 0xCBBF, 0xCBBF, 0xCBBF, 0xCBBF,
  0xCBBF, 0xfa60, 0xCBBF, 0xCBBF, 0xfa60, 0xCBBF,
  0xCBBF, 0xCBBF, 0xCBBF, 0xCBBF, 0xCBBF, 0xCBBF,
  0x0000, 0xb01a, 0xb01a, 0xb01a, 0xb01a, 0x0000,
  0x0000, 0xb01a, 0x0000, 0x0000, 0xb01a, 0x0000
};

const uint16_t OCTOPUSREDData[] =
{
  6,
  6,
  2,
  10,
  0x0000,
  0,
  //----          FIRST IMAGE             ----//
  0x0000, 0x9AD6, 0x9AD6, 0x9AD6, 0x9AD6, 0x0000,
  0x9AD6, 0x9AD6, 0x9AD6, 0x9AD6, 0x9AD6, 0x9AD6,
  0x9AD6, 0xfa60, 0x9AD6, 0x9AD6, 0xfa60, 0x9AD6,
  0x9AD6, 0x9AD6, 0x9AD6, 0x9AD6, 0x9AD6, 0x9AD6,
  0x0000, 0xb01a, 0xb01a, 0xb01a, 0xb01a, 0x0000,
  0xb01a, 0x0000, 0xb01a, 0xb01a, 0x0000, 0xb01a,
  //----          SECOND IMAGE            ----//
  0x0000, 0x9AD6, 0x9AD6, 0x9AD6, 0x9AD6, 0x0000,
  0x9AD6, 0x9AD6, 0x9AD6, 0x9AD6, 0x9AD6, 0x9AD6,
  0x9AD6, 0xfa60, 0x9AD6, 0x9AD6, 0xfa60, 0x9AD6,
  0x9AD6, 0x9AD6, 0x9AD6, 0x9AD6, 0x9AD6, 0x9AD6,
  0x0000, 0xb01a, 0xb01a, 0xb01a, 0xb01a, 0x0000,
  0x0000, 0xb01a, 0x0000, 0x0000, 0xb01a, 0x0000
};

const uint16_t OCTOPUSHITData[] =
{
  6,
  6,
  2,
  10,
  0x0000,
  0,
  //----          FIRST IMAGE             ----//
  0x0000, 0xF800, 0xF800, 0xF800, 0xF800, 0x0000,
  0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800,
  0xF800, 0xfa60, 0xF800, 0xF800, 0xfa60, 0xF800,
  0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800,
  0x0000, 0xb01a, 0xb01a, 0xb01a, 0xb01a, 0x0000,
  0xb01a, 0x0000, 0xb01a, 0xb01a, 0x0000, 0xb01a,
  //----          SECOND IMAGE            ----//
  0x0000, 0xF800, 0xF800, 0xF800, 0xF800, 0x0000,
  0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800,
  0xF800, 0xfa60, 0xF800, 0xF800, 0xfa60, 0xF800,
  0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800,
  0x0000, 0xb01a, 0xb01a, 0xb01a, 0xb01a, 0x0000,
  0x0000, 0xb01a, 0x0000, 0x0000, 0xb01a, 0x0000
};
const uint16_t LAZEData[] =
{
  6,
  6,
  2,
  10,
  0x0000,
  0,
  //----          FIRST IMAGE             ----//
  0x0000, 0x0211, 0x0211, 0x0211, 0x0211, 0x0000,
  0x0211, 0x0211, 0x0211, 0x0211, 0x0211, 0x0211,
  0x0211, 0xb81f, 0x075f, 0x075f, 0xb81f, 0x0211,
  0x0211, 0x0211, 0x0211, 0x0211, 0x0211, 0x0211,
  0x0211, 0x0b1a, 0x0b1a, 0x0b1a, 0x0b1a, 0x0211,
  0x0000, 0x0b1a, 0x0000, 0x0000, 0x0b1a, 0x0000,
  0x0000, 0x0211, 0x0211, 0x0211, 0x0211, 0x0000,
  0x0211, 0x0211, 0x0211, 0x0211, 0x0211, 0x0211,
  0x0211, 0x075f, 0xb81f, 0xb81f, 0x075f, 0x0211,
  0x0211, 0x0211, 0x0211, 0x0211, 0x0211, 0x0211,
  0x0211, 0x0b1a, 0x0b1a, 0x0b1a, 0x0b1a, 0x0211,
  0x0b1a, 0x0000, 0x0000, 0x0000, 0x0000, 0x0b1a

};

const uint16_t EXPLOSEData[] =
{
  6,
  6,
  6,
  2,
  0x0000,
  0,
  //----          FIRST IMAGE             ----//
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
  0x0000, 0x0000, 0xe2e0, 0xe2e0, 0x0000, 0x0000,
  0x0000, 0xe2e0, 0xfc20, 0xfc20, 0xe2e0, 0x0000,
  0x0000, 0xe2e0, 0xfc20, 0xfc20, 0xe2e0, 0x0000,
  0x0000, 0x0000, 0xe2e0, 0xe2e0, 0x0000, 0x0000,
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
  //----          SECOND IMAGE            ----//
  0xe2e0, 0x0000, 0xe2e0, 0xe2e0, 0x0000, 0xe2e0,
  0x0000, 0xe2e0, 0xfc20, 0xfc20, 0xe2e0, 0x0000,
  0xe2e0, 0xfc20, 0xfc20, 0xfc20, 0xfc20, 0xe2e0,
  0xe2e0, 0xfc20, 0xfc20, 0xfc20, 0xfc20, 0xe2e0,
  0x0000, 0xe2e0, 0xfc20, 0xfc20, 0xe2e0, 0x0000,
  0xe2e0, 0x0000, 0xe2e0, 0xe2e0, 0x0000, 0xe2e0,
  //----          THIRD IMAGE             ----//
  0xe2e0, 0xe2e0, 0xfc20, 0xfc20, 0xe2e0, 0xe2e0,
  0xe2e0, 0xfc20, 0xfc20, 0xfc20, 0xfc20, 0xe2e0,
  0xfc20, 0xfc20, 0xe560, 0xe560, 0xfc20, 0xfc20,
  0xfc20, 0xfc20, 0xe560, 0xe560, 0xfc20, 0xfc20,
  0xe2e0, 0xfc20, 0xfc20, 0xfc20, 0xfc20, 0xe2e0,
  0xe2e0, 0xe2e0, 0xfc20, 0xfc20, 0xe2e0, 0xe2e0,
  //----          FOURTH IMAGE            ----//
  0xe2e0, 0xe2e0, 0xe560, 0xe560, 0xe2e0, 0xe2e0,
  0xe2e0, 0xe560, 0xe560, 0xe560, 0xe560, 0xe2e0,
  0xe560, 0xe560, 0xffff, 0xffff, 0xe560, 0xe560,
  0xe560, 0xe560, 0xffff, 0xffff, 0xe560, 0xe560,
  0xe2e0, 0xe560, 0xe560, 0xe560, 0xe560, 0xe2e0,
  0xe2e0, 0xe2e0, 0xe560, 0xe560, 0xe2e0, 0xe2e0,
  //----          FIFTH IMAGE             ----//
  0xe560, 0xe560, 0xe560, 0xe560, 0xe560, 0xe560,
  0xe560, 0xffff, 0xffff, 0xffff, 0xffff, 0xe560,
  0xe560, 0xffff, 0x0000, 0x0000, 0xffff, 0xe560,
  0xe560, 0xffff, 0x0000, 0x0000, 0xffff, 0xe560,
  0xe560, 0xffff, 0xffff, 0xffff, 0xffff, 0xe560,
  0xe560, 0xe560, 0xe560, 0xe560, 0xe560, 0xe560,
  //----          SIXTH IMAGE             ----//
  0xe560, 0xe560, 0xe560, 0xe560, 0xe560, 0xe560,
  0xe560, 0x0000, 0x0000, 0x0000, 0x0000, 0xe560,
  0xe560, 0x0000, 0x0000, 0x0000, 0x0000, 0xe560,
  0xe560, 0x0000, 0x0000, 0x0000, 0x0000, 0xe560,
  0xe560, 0x0000, 0x0000, 0x0000, 0x0000, 0xe560,
  0xe560, 0xe560, 0xe560, 0xe560, 0xe560, 0xe560
};

Image IMG_CRAB = Image(CRABData);
Image IMG_SQUID = Image(SQUIDData);
Image IMG_OCTOPUS = Image(OCTOPUSData);
Image IMG_LAZE = Image(LAZEData);
Image IMG_EXPLOSE = Image(EXPLOSEData);

// ANGRY ENEMY
Image IMG_CRAB_RED = Image(CRABREDData);
Image IMG_SQUID_RED = Image(SQUIDREDData);
Image IMG_OCTO_RED = Image(OCTOPUSREDData);

// HIT
Image IMG_SQUID_HIT = Image(SQUIDHITData);
Image IMG_OCTO_HIT = Image(OCTOPUSHITData);

#endif
