#include "Capsule.h"
#include "CapsuleImage.h"

#include <Gamebuino-Meta.h>

//----------------------------------------------------------------------
//                          CONSTRUCTOR
//----------------------------------------------------------------------
Capsule::Capsule (int X, int Y ) :
  m_State(false)
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


//----------------------------------------------------------------------
//                          Method Drawing 
//----------------------------------------------------------------------
void Capsule::Display()
{ 
  if ( m_State == true )
  {
    gb.display.drawImage(m_X, m_Y, IMG_CAPSULE_LIFE);
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


