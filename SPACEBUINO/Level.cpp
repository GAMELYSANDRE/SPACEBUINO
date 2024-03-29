#include "Level.h"
#include "LevelImage.h"

#include <Gamebuino-Meta.h>

#define PosX 25
#define PosXArrow 35

//----------------------------------------------------------------------
//              CONSTRUCTOR
//----------------------------------------------------------------------
Level::Level () :
  m_Level(1),
  m_Direction(1),
  m_Mode(1),
  m_CurrentTime(0),
  m_StateBreakTimeImage(1),
  m_BreakTimeImage(0),
  m_NumberImage(0),
  m_StateBreakTimeLevel(1),
  m_BreakTimeLevel(0),
  m_MoveX(25),
  m_Animate(0)
{
  m_Space = new Space();
}

//----------------------------------------------------------------------
//              DESTRUCTOR
//----------------------------------------------------------------------

Level::~Level()
{
  delete m_Space;
}

//----------------------------------------------------------------------
//           Getters Methods
//----------------------------------------------------------------------

int Level::Mode()
{
  return (m_Mode);
}

int Level::LevelGame()
{
  return (m_Level);
}

//----------------------------------------------------------------------
//          Setters Methods
//----------------------------------------------------------------------
void Level::Mode(int ChangeMode)
{
  m_Mode = ChangeMode;
}


void Level::Display(unsigned long Time)
{
  gb.display.clear();
  // animate background
  m_Space->Display();
  // display title
  Title(Time);
  // view image level
  SelectLevel(Time);
}

void Level::Title(unsigned long Time)
{
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
  // LEVEL
  gb.display.drawImage(18, 2, IMG_LETTER, 0, 0, 7, 10);
  gb.display.drawImage(27, 2, IMG_LETTER, 0, 10, 7, 10);
  gb.display.drawImage(36, 2, IMG_LETTER, 0, 20, 7, 10);
  gb.display.drawImage(45, 2, IMG_LETTER, 0, 10, 7, 10);
  gb.display.drawImage(54, 2, IMG_LETTER, 0, 0, 7, 10);
  switch ( m_NumberImage)
  {
    case 1:
      gb.display.drawImage(18, 2, IMG_LETTER, 0, 30, 7, 10);
      break;
    case 2:
      gb.display.drawImage(18, 2, IMG_LETTER, 0, 40, 7, 10);
      break;
    case 3:
      gb.display.drawImage(27, 2, IMG_LETTER, 0, 50, 7, 10);
      break;
    case 4:
      gb.display.drawImage(27, 2, IMG_LETTER, 0, 60, 7, 10);
      break;
    case 5:
      gb.display.drawImage(36, 2, IMG_LETTER, 0, 70, 7, 10);
      break;
    case 6:
      gb.display.drawImage(36, 2, IMG_LETTER, 0, 80, 7, 10);
      break;
    case 7:
      gb.display.drawImage(45, 2, IMG_LETTER, 0, 50, 7, 10);
      break;
    case 8:
      gb.display.drawImage(45, 2, IMG_LETTER, 0, 60, 7, 10);
      break;
    case 9:
      gb.display.drawImage(54, 2, IMG_LETTER, 0, 30, 7, 10);
      break;
    case 10:
      gb.display.drawImage(54, 2, IMG_LETTER, 0, 40, 7, 10);
      break;
    case 11:
      m_NumberImage = 0;
      break;
  }
}

void Level::SelectLevel(unsigned long Time)
{
  // reads the level backup
  m_LevelSave = gb.save.get(10);
  gb.display.setColor(150, 150, 150);
  gb.display.setCursor(27, 18);
  gb.display.print("LEVEL ");
  gb.display.print(m_Level);
  gb.display.setCursor(52, 59);
  gb.display.print("EXIT: B");
  // Validate level
  if (gb.buttons.pressed(BUTTON_A))
  {
    if ( m_Level <= m_LevelSave )
    {
      m_Mode = 0;
    }
    gb.sound.playOK();
  }
  // EXIT
  if (gb.buttons.pressed(BUTTON_B))
  {
    m_Mode = -1;
    gb.sound.playOK();
  }
  // CHOOSE LEVEL
  if (m_Level < 20 )
  {
    if (gb.buttons.pressed(BUTTON_RIGHT))
    {
      m_Direction = 1;
      m_Animate = 1;
      gb.sound.playOK();
    }
  }
  if (m_Level > 1)
  {
    if (gb.buttons.pressed(BUTTON_LEFT))
    {
      m_Direction = 0;
      m_Animate = 1;
      gb.sound.playOK();
    }
  }
  if (m_Animate == true)
  {
    Animate(Time);
  }
  else
  {
    if (m_Level <= m_LevelSave )
    {
      gb.display.drawImage(25, PosX, IMG_LEVEL, 0, (m_Level - 1) * 30, 30, 30);
    }
    else
    {
      gb.display.drawImage(25, PosX, IMG_LEVEL_BW, 0, (m_Level - 1) * 30, 30, 30);
    }
    // Display Arrow Left and Right
    if (m_Level == 1)
    {
      gb.display.drawImage(60, PosXArrow, IMG_ARROW_RIGHT);
    }
    else if ( m_Level == 20 )
    {
      gb.display.drawImage(10, PosXArrow, IMG_ARROW_LEFT);
    }
    else
    {
      gb.display.drawImage(10, PosXArrow, IMG_ARROW_LEFT);
      gb.display.drawImage(60, PosXArrow, IMG_ARROW_RIGHT);
    }
  }
}

void Level::Animate(unsigned long Time)
{
  m_CurrentTime = Time;
  if ( m_CurrentTime > m_BreakTimeLevel and m_StateBreakTimeLevel  == 0 )
  {
    m_BreakTimeLevel  = m_CurrentTime + 5;
    m_StateBreakTimeLevel  = 0;
  }
  if ( m_CurrentTime > m_BreakTimeLevel  and m_StateBreakTimeLevel  == 1)
  {
    m_BreakTimeLevel  = Time + 5;
    m_StateBreakTimeLevel  = 1;
    // Speed Movement
    if ( m_Direction == true )
    {
      m_MoveX = m_MoveX - 3;
    }
    else
    {
      m_MoveX = m_MoveX + 3;
    }
  }
  if (m_Level <= m_LevelSave )
  {
    gb.display.drawImage(m_MoveX, PosX, IMG_LEVEL, 0, (m_Level - 1) * 30, 30, 30);
  }
  else
  {
    gb.display.drawImage(m_MoveX, PosX, IMG_LEVEL_BW, 0, (m_Level - 1) * 30, 30, 30);
  }

  if ( m_Direction == true )
  {
    if (m_Level >= m_LevelSave )
    {
      gb.display.drawImage(m_MoveX + 58, PosX, IMG_LEVEL_BW, 0, m_Level * 30, 30, 30);
    }
    else
    {
      gb.display.drawImage(m_MoveX + 58, PosX, IMG_LEVEL, 0, m_Level * 30, 30, 30);
    }
  }
  else
  {
    if (m_Level - 2 >= m_LevelSave )
    {
      gb.display.drawImage(m_MoveX - 68, PosX, IMG_LEVEL_BW, 0, (m_Level - 2) * 30, 30, 30);
    }
    else
    {
      gb.display.drawImage(m_MoveX - 68, PosX, IMG_LEVEL, 0, (m_Level - 2) * 30, 30, 30);
    }
  }
  // end animate
  if ( m_MoveX < -30 or m_MoveX > 90)
  {
    m_MoveX = 25;
    m_Animate = false;
    if ( m_Direction == true )
    {
      m_Level++;
    }
    else
    {
      m_Level--;
    }
  }
}
