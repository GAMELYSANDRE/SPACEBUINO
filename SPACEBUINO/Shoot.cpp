#include "Shoot.h"
#include <Gamebuino-Meta.h>
/*------------------------------------*/
/*          Constructors              */
/*------------------------------------*/

Shoot::Shoot () : m_X(0), m_Y(0),m_Color(8),m_Speed(2), m_State(0)
{

}
Shoot::Shoot (int Color, int Speed) : m_X(0), m_Y(0),m_Color(8),m_Speed(2), m_State(0)
{
  m_Color = Color;
  m_Speed = Speed;
}

/*------------------------------------*/
/*           Getters functions        */
/*------------------------------------*/

int Shoot::X() const
{
  return (m_X);
}
int Shoot::Y() const
{
  return (m_Y);
}
bool Shoot::State ()
{
  return (m_State);
}

/*------------------------------------*/
/*          Setters functions         */
/*------------------------------------*/
void Shoot::Position (int X, int Y)
{
  m_X = X;
  m_Y = Y;
}
void Shoot::State (bool StateShoot)
{
  m_State = StateShoot;
}
void Shoot::Speed(int ChangeSpeed)
{
  m_Speed = ChangeSpeed;
}

void Shoot::Draw()
{
  gb.display.setColor(m_Color);
  gb.display.fillRect(m_X, m_Y, 2, 4);
}


void Shoot::Move(Direction DirectionShooting )
{
  if (m_State)
  {
    if (DirectionShooting == UP)
    {
      m_Y = m_Y - m_Speed;
    }
    if (DirectionShooting == DOWN)
    {
      m_Y = m_Y + m_Speed;
    }
    Draw();
  }
  if (m_Y < 0 or m_Y > 60 )
  {
    m_State = 0;
  }
}
