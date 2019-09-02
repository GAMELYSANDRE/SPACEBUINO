#include "Menu.h"
#include "MenuImage.h"
#include <Gamebuino-Meta.h>

//----------------------------------------------------------------------
//          Constructors
//----------------------------------------------------------------------

Menu::Menu (const char *MenuTextList[], int MenuSize):
  m_MenuPosition(0),
  m_Mode(-1),
  m_CurrentTime(0),
  m_StateBreakTime(1),
  m_BreakTimeON(0),
  m_BreakTimeOFF(0),
  m_DelayFlashingText(300),
  m_StateBreakTimeImage(1),
  m_BreakTimeImage(0),
  m_NumberImage(0)
{
  m_MenuSize = MenuSize;
  // Create the array to save string lengths
  m_MenuTextSize = new int[MenuSize];
  // Create row
  m_MenuTextList = new char*[MenuSize];
  // create column according to the string length
  for (int i = 0; i < MenuSize; i++)
  {
    int TextSize = strlen(MenuTextList[i]);
    m_MenuTextSize[i] = TextSize;
    m_MenuTextList[i] = new char[TextSize];
  }
  // copy the string length
  for (int i = 0; i < MenuSize; i++)
  {
    strcpy(m_MenuTextList[i], MenuTextList[i]);
  }
  m_Space = new Space();
}

Menu::~Menu()
{
  for (int i = 0; i < m_MenuSize; i++)
  {
    delete[] m_MenuTextList[i];
  }
  delete[] m_MenuTextList;
  delete m_Space;
}
//----------------------------------------------------------------------
//           Getters Methods
//----------------------------------------------------------------------
int Menu::Position() const
{
  return (m_MenuPosition);
}

int Menu::Mode() const
{
  return (m_Mode);
}


//----------------------------------------------------------------------
//          Setters Methods
//----------------------------------------------------------------------
void Menu::Mode(int ChangeMode)
{
  m_Mode = ChangeMode;
}

void Menu::DisplayText (int RowText, bool ActivFlashing)
{
  if ( ActivFlashing == 1)
  {
    gb.display.setColor(255, 77, 0);
  }
  else
  {
    gb.display.setColor(150, 150, 150);
  }
  gb.display.setCursor((80 - m_MenuTextSize[RowText] * 4) / 2, 26 + (RowText * 9));
  gb.display.print(m_MenuTextList[RowText]);
}

void Menu::DisplayMenu(unsigned long Time)
{
  m_CurrentTime = Time;
  for (int i = 0; i < m_MenuSize; i++)
  {
    if (i != m_MenuPosition)
    {
      DisplayText(i, 0);
    }
    else
    {
      DisplayText(m_MenuPosition, m_StateBreakTime);
    }
  }
  if (m_CurrentTime > m_BreakTimeOFF and m_StateBreakTime == 1 )
  {
    m_BreakTimeON = m_CurrentTime + m_DelayFlashingText;
    m_StateBreakTime = 0;
  }
  if (m_CurrentTime > m_BreakTimeON and m_StateBreakTime == false)
  {
    m_BreakTimeOFF = m_CurrentTime + m_DelayFlashingText;
    m_StateBreakTime = 1;
  }
  DisplayImage(Time);
  MoveText();
}

void Menu::MoveText()
{
  if (gb.buttons.pressed(BUTTON_DOWN))
  {
    if (m_MenuPosition >= (m_MenuSize - 1))
    {
      m_MenuPosition = m_MenuSize - 1;
    }
    else
    {
      m_MenuPosition++;
    }
    gb.sound.playOK();
  }
  if (gb.buttons.pressed(BUTTON_UP))
  {

    if (m_MenuPosition <= 0)
    {
      m_MenuPosition = 0;
    }
    else
    {
      m_MenuPosition--;
    }
    gb.sound.playOK();
  }
  if (gb.buttons.pressed(BUTTON_A))
  {
    m_Mode = m_MenuPosition;
    gb.sound.playTick();
  }
}


void Menu::DisplayImage(unsigned long Time)
{
  // animate background
  m_Space->Display();
  // animate title
  m_CurrentTime = Time;
  if ( m_CurrentTime > m_BreakTimeImage and m_StateBreakTimeImage == 1 )
  {
    m_BreakTimeImage = Time + 50;
    m_StateBreakTimeImage = 0;
    gb.lights.clear();
  }
  if ( m_CurrentTime > m_BreakTimeImage and m_StateBreakTimeImage == 0)
  {
    m_BreakTimeImage = Time + 50;
    m_StateBreakTimeImage = 1;
    m_NumberImage++;
  }
  gb.display.drawImage(12, 2, IMG_SPACEBUINO, 0, 0, 7, 10);
  gb.display.drawImage(20, 2, IMG_SPACEBUINO, 0, 10, 7, 10);
  gb.display.drawImage(28, 2, IMG_SPACEBUINO, 0, 20, 7, 10);
  gb.display.drawImage(36, 2, IMG_SPACEBUINO, 0, 30, 7, 10);
  gb.display.drawImage(44, 2, IMG_SPACEBUINO, 0, 40, 7, 10);
  gb.display.drawImage(36, 13, IMG_SPACEBUINO, 0, 50, 7, 10);
  gb.display.drawImage(44, 13, IMG_SPACEBUINO, 0, 60, 7, 10);
  gb.display.drawImage(52, 13, IMG_SPACEBUINO, 0, 70, 7, 10);
  gb.display.drawImage(59, 13, IMG_SPACEBUINO, 0, 80, 7, 10);
  gb.display.drawImage(67, 13, IMG_SPACEBUINO, 0, 90, 7, 10);
  switch ( m_NumberImage)
  {
    case 1:
      gb.display.drawImage(12, 2, IMG_SPACEBUINO, 0, 100, 7, 10);
      gb.lights.drawPixel(0, 3, BLUE);
      break;
    case 2:
      gb.display.drawImage(12, 2, IMG_SPACEBUINO, 0, 110, 7, 10);
      gb.lights.drawPixel(0, 3, BLUE);
      gb.lights.drawPixel(0, 2, BLUE);
      break;
    case 3:
      gb.display.drawImage(20, 2, IMG_SPACEBUINO, 0, 120, 7, 10);
      gb.lights.drawPixel(0, 2, BLUE);
      break;
    case 4:
      gb.display.drawImage(20, 2, IMG_SPACEBUINO, 0, 130, 7, 10);
      gb.lights.drawPixel(0, 2, BLUE);
      gb.lights.drawPixel(0, 1, BLUE);
      break;
    case 5:
      gb.display.drawImage(28, 2, IMG_SPACEBUINO, 0, 140, 7, 10);
      gb.lights.drawPixel(0, 1, BLUE);
      break;
    case 6:
      gb.display.drawImage(28, 2, IMG_SPACEBUINO, 0, 150, 7, 10);
      gb.lights.drawPixel(0, 1, BLUE);
      gb.lights.drawPixel(0, 0, BLUE);
      break;
    case 7:
      gb.display.drawImage(36, 2, IMG_SPACEBUINO, 0, 160, 7, 10);
      gb.display.drawImage(36, 13, IMG_SPACEBUINO, 0, 170, 7, 10);
      gb.lights.drawPixel(0, 0, BLUE);
      break;
    case 8:
      gb.display.drawImage(36, 2, IMG_SPACEBUINO, 0, 180, 7, 10);
      gb.display.drawImage(36, 13, IMG_SPACEBUINO, 0, 190, 7, 10);
      gb.lights.drawPixel(0, 0, BLUE);
      break;
    case 9:
      gb.display.drawImage(44, 2, IMG_SPACEBUINO, 0, 200, 7, 10);
      gb.display.drawImage(44, 13, IMG_SPACEBUINO, 0, 210, 7, 10);
      gb.lights.drawPixel(1, 0, BLUE);
      break;
    case 10:
      gb.display.drawImage(44, 2, IMG_SPACEBUINO, 0, 220, 7, 10);
      gb.display.drawImage(44, 13, IMG_SPACEBUINO, 0, 230, 7, 10);
      gb.lights.drawPixel(1, 0, BLUE);
      gb.lights.drawPixel(1, 1, BLUE);
      break;
    case 11:
      gb.display.drawImage(52, 13, IMG_SPACEBUINO, 0, 240, 7, 10);
      gb.lights.drawPixel(1, 1, BLUE);
      break;
    case 12:
      gb.display.drawImage(59, 13, IMG_SPACEBUINO, 0, 250, 7, 10);
      gb.lights.drawPixel(1, 1, BLUE);
      gb.lights.drawPixel(1, 2, BLUE);
      break;
    case 13:
      gb.display.drawImage(59, 13, IMG_SPACEBUINO, 0, 260, 7, 10);
      gb.lights.drawPixel(1, 2, BLUE);
      break;
    case 14:
      gb.display.drawImage(67, 13, IMG_SPACEBUINO, 0, 270, 7, 10);
      gb.lights.drawPixel(1, 2, BLUE);
      gb.lights.drawPixel(1, 3, BLUE);
      break;
    case 15:
      gb.display.drawImage(67, 13, IMG_SPACEBUINO, 0, 280, 7, 10);
      gb.lights.drawPixel(1, 3, BLUE);
      break;
    case 16:
      m_NumberImage = 0;
      break;
  }
}
