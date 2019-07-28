#include "Star.h"
#include <Gamebuino-Meta.h>

/*-------------------------------------*/
/*              CONSTRUCTOR            */
/*-------------------------------------*/
Star::Star(int X, int Y, int Speed) : m_X(0), m_Y(0), m_Speed(1)
{
  m_X = X;
  m_Y = Y;
  m_Speed = Speed;
}

void Star::Display()
{
  gb.display.setColor(WHITE);
  gb.display.drawPixel(m_X, m_Y);
}

void Star::Move()
{
  if ( m_X < 0 )
  {
    m_Y = random(0, 60);
    m_X = 90;
  }
  else
  {
    m_X = m_X - m_Speed;
  }
}
