#include "HighScore.h"
#include "HighScoreImage.h"

#include <Gamebuino-Meta.h>

//----------------------------------------------------------------------
//              CONSTRUCTOR
//----------------------------------------------------------------------

HS::HS () :
  m_SDcard(1),
  m_LetterPosition(0),
  m_LetterColumn(0),
  m_NewScore(10),
  m_SaveScore(1),
  m_Mode(0),
  m_CurrentTime(0),
  m_StateBreakTimeImage(1),
  m_BreakTimeImage(0),
  m_NumberImage(0)
{
  for (int rang = 0; rang == 5; rang++)
  {
    m_Score[rang] = 0;
    if ( gb.save.get(rang) == 0)
    {
      gb.save.set(rang, m_Score[rang]);
    }
  }
  // test save

    int test=0;
    gb.save.set(0,test);
    gb.save.set(1,test);
    gb.save.set(2,test);
    gb.save.set(3,test);
    gb.save.set(4,test);



    gb.save.set(5,"---");
    gb.save.set(6,"---");
    gb.save.set(7,"---");
    gb.save.set(8,"---");
    gb.save.set(9,"---");

  m_Space = new Space();
}

//----------------------------------------------------------------------
//              DESTRUCTOR
//----------------------------------------------------------------------

HS::~HS()
{
  delete m_Space;
}

//----------------------------------------------------------------------
//           Getters functions
//----------------------------------------------------------------------

int HS::Mode()
{
  return (m_Mode);
}

//----------------------------------------------------------------------
//          Setters Methods
//----------------------------------------------------------------------
void HS::Mode(int ChangeMode)
{
  m_Mode = ChangeMode;
}



void HS::Display(unsigned long Time, unsigned int Score)
{
  // erase the lights
  gb.lights.clear();
  // animate background
  m_Space->Display();
  // display title
  Title(Time);
  if (m_SDcard)
  {
    // read the scores
    Read();
    // compare the new score
    Compare(Score);
    // disable access SDcard
    m_SDcard = 0;
  }
  if ( m_SaveScore == true)
  {
    // save the new score
    ChooseLetter(Score);
  }
  else
  {
    // exit the high scores
    if (gb.buttons.pressed(BUTTON_A) or gb.buttons.pressed(BUTTON_B) )
    {
      m_Mode = -1;
      m_SDcard = 1;
      gb.sound.playTick();
    }
  }
  gb.display.setColor(BLUE);
  gb.display.setCursor(5, 15);
  gb.display.println("RANK  NAME  SCORE");
  for (unsigned int row = 0; row < 5; row++)
  {
    if (m_NewScore != row or m_SaveScore == false)
    {
      gb.display.setColor(DARKBLUE);
      // RANK
      gb.display.setCursor(12, 24 + (row * 6));
      gb.display.print(row + 1);
      // NAME
      gb.display.setCursor(30, 24 + (row * 6));
      char temp1[3];
      gb.save.get(row + 5, temp1, 3);
      gb.display.print(temp1);
      // SCORE
      gb.display.setCursor(51, 24 + (row * 6));
      gb.display.print(m_Score[row]);
    }
    else
    {
      gb.display.setColor(RED);
      // RANK
      gb.display.setCursor(12, 24 + (row * 6));
      gb.display.print(row + 1);
      // NEW SCORE
      gb.display.setCursor(51, 24 + (row * 6));
      gb.display.print(Score);
    }
  }

}

void HS::Title(unsigned long Time)
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
  // HIGH
  gb.display.drawImage(0, 2, IMG_HIGHSCORES, 0, 0, 7, 10);
  gb.display.drawImage(8, 2, IMG_HIGHSCORES, 0, 10, 7, 10);
  gb.display.drawImage(15, 2, IMG_HIGHSCORES, 0, 20, 7, 10);
  gb.display.drawImage(23, 2, IMG_HIGHSCORES, 0, 0, 7, 10);
  // SCORES
  gb.display.drawImage(33, 2, IMG_HIGHSCORES, 0, 30, 7, 10);
  gb.display.drawImage(41, 2, IMG_HIGHSCORES, 0, 40, 7, 10);
  gb.display.drawImage(49, 2, IMG_HIGHSCORES, 0, 50, 7, 10);
  gb.display.drawImage(57, 2, IMG_HIGHSCORES, 0, 60, 7, 10);
  gb.display.drawImage(65, 2, IMG_HIGHSCORES, 0, 70, 7, 10);
  gb.display.drawImage(73, 2, IMG_HIGHSCORES, 0, 30, 7, 10);
  switch ( m_NumberImage)
  {
    case 1:
      gb.display.drawImage(0, 2, IMG_HIGHSCORES, 0, 80, 7, 10);
      gb.lights.drawPixel(0, 0, GRAY);
      gb.lights.drawPixel(1, 0, GRAY);
      break;
    case 2:
      gb.display.drawImage(0, 2, IMG_HIGHSCORES, 0, 90, 7, 10);
      gb.lights.drawPixel(0, 0, BLUE);
      gb.lights.drawPixel(1, 0, BLUE);
      break;
    case 3:
      gb.display.drawImage(8, 2, IMG_HIGHSCORES, 0, 100, 7, 10);
      gb.lights.drawPixel(0, 0, DARKBLUE);
      gb.lights.drawPixel(1, 0, DARKBLUE);
      break;
    case 4:
      gb.display.drawImage(15, 2, IMG_HIGHSCORES, 0, 110, 7, 10);
      gb.lights.drawPixel(0, 1, GRAY);
      gb.lights.drawPixel(1, 1, GRAY);
      break;
    case 5:
      gb.display.drawImage(15, 2, IMG_HIGHSCORES, 0, 120, 7, 10);
      gb.lights.drawPixel(0, 1, BLUE);
      gb.lights.drawPixel(1, 1, BLUE);
      break;
    case 6:
      gb.display.drawImage(23, 2, IMG_HIGHSCORES, 0, 80, 7, 10);
      gb.lights.drawPixel(0, 1, DARKBLUE);
      gb.lights.drawPixel(1, 1, DARKBLUE);
      break;
    case 7:
      gb.display.drawImage(23, 2, IMG_HIGHSCORES, 0, 90, 7, 10);
      gb.lights.drawPixel(0, 2, GRAY);
      gb.lights.drawPixel(1, 2, GRAY);
      break;
    case 8:
      gb.display.drawImage(33, 2, IMG_HIGHSCORES, 0, 130, 7, 10);
      gb.lights.drawPixel(0, 2, BLUE);
      gb.lights.drawPixel(1, 2, BLUE);
      break;
    case 9:
      gb.display.drawImage(33, 2, IMG_HIGHSCORES, 0, 140, 7, 10);
      gb.lights.drawPixel(0, 2, DARKBLUE);
      gb.lights.drawPixel(1, 2, DARKBLUE);
      break;
    case 10:
      gb.display.drawImage(41, 2, IMG_HIGHSCORES, 0, 150, 7, 10);
      gb.lights.drawPixel(0, 3, WHITE);
      gb.lights.drawPixel(1, 3, WHITE);
      break;
    case 11:
      gb.display.drawImage(41, 2, IMG_HIGHSCORES, 0, 160, 7, 10);
      gb.lights.drawPixel(0, 3, GRAY);
      gb.lights.drawPixel(1, 3, GRAY);
      break;
    case 12:
      gb.display.drawImage(49, 2, IMG_HIGHSCORES, 0, 170, 7, 10);
      gb.lights.drawPixel(0, 3, BLUE);
      gb.lights.drawPixel(1, 3, BLUE);
      break;
    case 13:
      gb.display.drawImage(49, 2, IMG_HIGHSCORES, 0, 180, 7, 10);
      break;
    case 14:
      gb.display.drawImage(57, 2, IMG_HIGHSCORES, 0, 190, 7, 10);
      break;
    case 15:
      gb.display.drawImage(57, 2, IMG_HIGHSCORES, 0, 200, 7, 10);
      break;
    case 16:
      gb.display.drawImage(65, 2, IMG_HIGHSCORES, 0, 210, 7, 10);
      break;
    case 17:
      gb.display.drawImage(65, 2, IMG_HIGHSCORES, 0, 220, 7, 10);
      break;
    case 18:
      gb.display.drawImage(73, 2, IMG_HIGHSCORES, 0, 130, 7, 10);
      break;
    case 19:
      gb.display.drawImage(73, 2, IMG_HIGHSCORES, 0, 140, 7, 10);
      break;
    case 20:
      m_NumberImage = 0;
      break;
  }
}

void HS::Read()
{
  for (int rang = 0; rang < 5; rang++)
  {
    m_Score[rang] = gb.save.get(rang);
  }
}

void HS::ChooseLetter(unsigned int Score)
{

  // Display letter
  gb.display.setColor(GRAY);
  gb.display.fillRect(29 + (m_LetterColumn * 4), 23 + (m_NewScore * 6), 5, 7);
  gb.display.setColor(RED);
  gb.display.setCursor(30 + (m_LetterColumn * 4), 24 + (m_NewScore * 6));
  gb.display.print(m_Alphabet[m_LetterPosition]);

  // move the letters with the arrows down and up
  if (gb.buttons.repeat(BUTTON_UP, 6))
  {
    if (m_LetterPosition == 25 )
    {
      m_LetterPosition = 0;
    }
    else
    {
      m_LetterPosition++;
    }
    gb.sound.playOK();
  }
  if (gb.buttons.repeat(BUTTON_DOWN, 6))
  {

    if (m_LetterPosition == 0)
    {
      m_LetterPosition = 25;
    }
    else
    {
      m_LetterPosition--;
    }
    gb.sound.playOK();
  }
  // changes column and reads and saves the previous character
  if (gb.buttons.pressed(BUTTON_RIGHT))
  {
    if (m_LetterColumn == 2)
    {
    }
    else
    {
      m_LetterColumn++;
    }
    if (m_Name[m_LetterColumn] != '0')
    {
      for (int index = 0; index < 26; index++)
      {
        if (m_Name[m_LetterColumn] == m_Alphabet[index])
        {
          m_LetterPosition = index;
        }
      }
    }
    gb.sound.playOK();
  }
  if (gb.buttons.pressed(BUTTON_LEFT))
  {
    if (m_LetterColumn == 0)
    {
    }
    else
    {
      m_LetterColumn--;
    }
    if (m_Name[m_LetterColumn] != '0')
    {
      for (int index = 0; index < 26; index++)
      {
        if (m_Name[m_LetterColumn] == m_Alphabet[index])
        {
          m_LetterPosition = index;
        }
      }
    }
    gb.sound.playOK();
  }
  // displays the 3 characters
  for (unsigned int column = 0; column < (strlen(m_Name)); column++)
  {
    if (m_Name[column] != '0')
    {
      gb.display.setCursor(30 + (column * 4), 24 + (m_NewScore * 6));
      gb.display.print(m_Name[column]);
    }

  }
  m_Name[m_LetterColumn] = m_Alphabet[m_LetterPosition];
  // reset the alphabet
  if (gb.buttons.pressed(BUTTON_A))
  {
    m_LetterPosition = 0;
    gb.sound.playTick();
  }
  // validate the name
  if (gb.buttons.pressed(BUTTON_B))
  {
    // save the name new player
    char temp1[3];
    strcpy(temp1, m_Name);
    gb.save.set(m_NewScore + 5, temp1);
    // save the score du new player
    gb.save.set(m_NewScore, Score);
    //reads the scores one last time
    Read();
    m_SaveScore = false;
    m_NewScore = 10;
    gb.sound.playTick();
  }
}
//----------------------------------------------------------------------
//    Method that compares the new score with the scores recorded
//----------------------------------------------------------------------

void HS::Compare(unsigned int Score)
{
  for (int row = 4; row > -1; row--)
  {
    if (Score > m_Score[row])
    {
      m_NewScore = row;
      m_SaveScore = 1;
    }
  }
  if ( m_NewScore == 10 )
  {
    // score lower than all others
    m_SaveScore = false;
  }
}
