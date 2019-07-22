#ifndef __GAMEIMAGE__
#define __GAMEIMAGE__
#include <Gamebuino-Meta.h>

const uint16_t SPACESHIPLIFEData[] =
{
  5,// Longueur
  5,// Largeur
  1,// nombre d'image
  1,// nombre image seconde
  0xf81f, // couleur de transparence
  0,
  0xf81f, 0x7bae, 0xeefb, 0x7bae, 0xf81f,
  0xf81f, 0xeefb, 0x071b, 0xeefb, 0xf81f,
  0x7bae, 0xeefb, 0x071b, 0xeefb, 0x7bae,
  0xeefb, 0xeefb, 0xeefb, 0xeefb, 0xeefb,
  0xeefb, 0x7bae, 0xf81f, 0x7bae, 0xeefb
};
const uint16_t GAME_DATA[] = 
{
  44,     // frame width
  10,     // frame height
  1,      // number of frames
  1,      // animation speed
  0xf81f, // transparent color
  0,      // RGB565 color mode
  0xf81f, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0,
  0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0,
  0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f,
  0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f,
  0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f,
  0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f,
  0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f,
  0xf81f, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0,
  0xf81f, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0,
  0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f
};


const uint16_t OVER_DATA[] = {
  44,     // frame width
  10,     // frame height
  1,      // number of frames
  1,      // animation speed
  0xf81f, // transparent color
  0,      // RGB565 color mode
  // frame 1/1
  0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 
  0xf81f, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 
  0xf81f, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 
  0xf81f, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 
  0xf81f, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 
  0xf81f, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 
  0xf81f, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 
  0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 
  0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 0xf81f, 0x07e0, 0x07e0, 0x07e0, 0xf81f, 0xf81f, 
  0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f, 0xf81f
};


Image IMG_SPACESHIPLIFE = Image(SPACESHIPLIFEData);
Image IMG_GAME = Image(GAME_DATA);
Image IMG_OVER = Image(OVER_DATA);

#endif
