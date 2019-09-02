#include "Capsule.h"
#include "CapsuleImage.h"

#include <Gamebuino-Meta.h>

//----------------------------------------------------------------------
//                          CONSTRUCTOR
//----------------------------------------------------------------------
Capsule::Capsule (int X, int Y ) :
  m_State(false),
  m_Color(CAPSULE_GREEN)
{


}

//----------------------------------------------------------------------
//                            DESTRUCTOR
//----------------------------------------------------------------------

Capsule::~Capsule()
{

}
//----------------------------------------------------------------------
//                        Getters Methods
//----------------------------------------------------------------------
int Capsule::X() const
{
  return (m_X);
}
int Capsule::Y() const
{
  return (m_Y);
}
bool Capsule::State() const
{
  return (m_State);
}
CapsuleColor Capsule::Color() const
{
  return (m_Color);
}

//----------------------------------------------------------------------
//                          Setters Methods
//----------------------------------------------------------------------
void Capsule::X(int ChangeX)
{
  m_X = ChangeX;
}
void Capsule::Y(int ChangeY)
{
  m_Y = ChangeY;
}
void Capsule::State(bool ChangeState)
{
  m_State = ChangeState;
}
void Capsule::Color(CapsuleColor ChangeColor)
{
  m_Color = ChangeColor;
}

//----------------------------------------------------------------------
//                          Method Drawing
//----------------------------------------------------------------------
void Capsule::Display()
{
  if ( m_State == true )
  {
    switch (m_Color)
    {
      case CAPSULE_GREEN:
        gb.display.drawImage(m_X, m_Y, IMG_CAPSULE_LIFE);
        break;
      case CAPSULE_BLUE:
        gb.display.drawImage(m_X, m_Y, IMG_CAPSULE_PROTECT);
        break;
    }
  }
}

//----------------------------------------------------------------------
//                          Method Move X et Y
//----------------------------------------------------------------------
void Capsule::Move(int X, int Y)
{
  m_X = X;
  m_Y = Y;
}
