#include "Credit.h"
#include "CreditImage.h"
#include <Gamebuino-Meta.h>

//----------------------------------------------------------------------
//                         CONSTRUCTOR
//----------------------------------------------------------------------
Credit::Credit () :
  m_Mode(0)
{
  m_Space = new Space();
}

//----------------------------------------------------------------------
//                           DESTRUCTOR
//----------------------------------------------------------------------

Credit::~Credit()
{
  delete m_Space;
}

//----------------------------------------------------------------------
//           Getters functions
//----------------------------------------------------------------------

int Credit::Mode()
{
  return (m_Mode);
}

//----------------------------------------------------------------------
//          Setters Methods
//----------------------------------------------------------------------
void Credit::Mode(int ChangeMode)
{
  m_Mode = ChangeMode;
}




void Credit::Display()
{
  // animate background
  m_Space->Display();
  gb.lights.clear();
  gb.display.drawImage(23, 2, IMG_LOGO);
  gb.display.setColor(154, 205, 50);
  gb.display.setCursor(8, 32);
  gb.display.println("CODE et GRAPHISME");
  gb.display.setCursor(15, 41);
  gb.display.println("- LYSANDRE -");
  gb.display.setCursor(0, 50);
  gb.display.println("gamelysandre@gmail.com");
  if (gb.buttons.pressed(BUTTON_A))
  {
    m_Mode = -1;
  }
}
