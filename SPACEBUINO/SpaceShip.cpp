#include "SpaceShip.h"
#include "SpaceShipImage.h"
#include <Gamebuino-Meta.h>

/*------------------------------------*/
/*          Constructors              */
/*------------------------------------*/
SpaceShip::SpaceShip () : 
 m_X(0), 
 m_Y(0), 
 m_State(1), 
 m_Position(1), 
 m_Life(3),
 m_Protection(0),
 m_ProtectionDuration(2)
{

}
SpaceShip::SpaceShip  (int X, int Y ) : 
  m_X(0), 
  m_Y(0), 
  m_State(1), 
  m_Position(1), 
  m_Life(3),
  m_Protection(0),
  m_ProtectionDuration(2)
{
  m_X = X;
  m_Y = Y;
}

//----------------------------------------------------------------------
//                       Getters functions
//----------------------------------------------------------------------
int SpaceShip::X() const
{
  return (m_X);
}
int SpaceShip::Y() const
{
  return (m_Y);
}
bool SpaceShip::State() const
{
  return (m_State);
}
int SpaceShip::Life() const
{
  return (m_Life);
}
bool SpaceShip::Protection() const
{
  return (m_Protection);
}
int SpaceShip::ProtectionDuration() const
{
  return (m_ProtectionDuration);
}

//----------------------------------------------------------------------
//                        Setters methods
//----------------------------------------------------------------------
void SpaceShip::X(int ChangeX)
{
  m_X = ChangeX;
}
void SpaceShip::Y(int ChangeY)
{
  m_Y = ChangeY;
}
void SpaceShip::State(bool ChangeState)
{
  m_State = ChangeState;
}
void SpaceShip::Position(int ChangePosition)
{
  m_Position = ChangePosition;
}
void SpaceShip::Life(int ChangeLife)
{
  m_Life = ChangeLife;
}
void SpaceShip::Protection(bool ChangeProtection)
{
  m_Protection = ChangeProtection;
}
void SpaceShip::ProtectionDuration(int ChangeProtectionDuration)
{
  m_ProtectionDuration = ChangeProtectionDuration;
}

//----------------------------------------------------------------------
//                       reset default settings
//----------------------------------------------------------------------

void SpaceShip::Reset()
{
  m_X = 0;
  m_Y = 0;
  m_State = 1;
  m_Position = 1;
  m_Life = 3;
  m_Protection = 0;
  m_ProtectionDuration = 2;
}

//----------------------------------------------------------------------
//            method that draws the ship following the states
//----------------------------------------------------------------------
void SpaceShip::Draw()
{
  if (m_State == 1)
  {
    switch (m_Position)
    {
      case 0:
        if( m_Protection == false)
        {
          gb.display.drawImage(m_X, m_Y, IMG_SPACESHIPLEFT);
        }
        else
        {
          gb.display.drawImage(m_X, m_Y, IMG_SPACESHIPPROTECTLEFT);
        }
        m_Position = 1;
        break;
      case 1:
        if( m_Protection == false)
        {
          gb.display.drawImage(m_X, m_Y, IMG_SPACESHIP);
        }
        else
        {
          gb.display.drawImage(m_X, m_Y, IMG_SPACESHIPPROTECT);
        }
        break;
      case 2:
        if( m_Protection == false) 
        {
          gb.display.drawImage(m_X, m_Y, IMG_SPACESHIPRIGHT);
        }
        else
        {
          gb.display.drawImage(m_X, m_Y, IMG_SPACESHIPPROTECTRIGHT);
        }
        m_Position = 1;
        break;
      case 3:
        gb.display.drawImage(m_X, m_Y, IMG_SPACESHIPEXPLODE);
        gb.sound.play("explosion_2.wav");
        break;
    }
  }
}

void SpaceShip::Move()
{
  if (gb.buttons.repeat(BUTTON_RIGHT , 0))
  {
    if (m_X <= 72 )
    {
      m_X = m_X + 2;
    }
    // change the type of sprite according to the movements
    m_Position = 2;
  }
  if (gb.buttons.repeat(BUTTON_LEFT, 0 ))
  {
    if (m_X >= 2 )
    {
      m_X = m_X - 2;
    }
    // change the type of sprite according to the movements
    m_Position = 0;
  }
}
