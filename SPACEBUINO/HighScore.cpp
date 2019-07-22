#include "HighScore.h"
#include "HighScoreImage.h"
#include <Gamebuino-Meta.h>

HS::HS () :
   m_LetterPosition(0),
   m_LetterColumn(0)
{
   for (int rang = 0; rang==6; rang++)
   {
      m_Score[rang]=0;
      if ( gb.save.get(rang) == 0)
      {
         gb.save.set(rang, m_Score[rang]);
      }
   }
   // test save 
   /*
   gb.save.set(0,5);
   gb.save.set(1,10);
   gb.save.set(2,15);
   gb.save.set(3,20);
   gb.save.set(4,25);
   gb.save.set(5,30);
   */
   gb.save.set(6,"SAN");
   gb.save.set(7,"LAU");
   gb.save.set(8,"COC");
   gb.save.set(9,"CLE");
   gb.save.set(10,"DOD");
   gb.save.set(11,"PTR");
}


void HS::Display(unsigned long Time)
{ 
   // erase the lights
   gb.lights.clear();
   // display title
   Title(Time);
   // read score
   Read();
   gb.display.setColor(BLUE);
   gb.display.setCursor(5, 15);	
   gb.display.println("RANK  NAME  SCORE");
   gb.display.setColor(DARKBLUE);
   for (int row = 0; row < 6; row++)
   {
     // RANK
     gb.display.setCursor(12, 24+(row*6));	
     gb.display.print(row+1);
     // NAME
     gb.display.setCursor(30, 24+(row*6));
     char temp1[3];
     gb.save.get(row+6, temp1, 3);
     //strcpy(m_fox,temp1);
     gb.display.print(temp1);
     // SCORE
     gb.display.setCursor(51, 24+(row*6));
     gb.display.print(gb.save.get(row));   
   }
   //ChooseLetter();
}

void HS::Title(unsigned long Time)
{
   gb.display.drawImage(1, 2, IMG_SAVETITLE, 0, 0, 7, 10);
   gb.display.drawImage(9, 2, IMG_SAVETITLE, 0,10, 7, 10);	
   gb.display.drawImage(16, 2, IMG_SAVETITLE, 0,20, 7, 10);
   gb.display.drawImage(24, 2, IMG_SAVETITLE, 0, 0, 7, 10);	
   gb.display.drawImage(39, 2, IMG_SAVETITLE, 0,30, 7, 10);
   gb.display.drawImage(47, 2, IMG_SAVETITLE, 0,40, 7, 10);	
   gb.display.drawImage(55, 2, IMG_SAVETITLE, 0,50, 7, 10);
   gb.display.drawImage(63, 2, IMG_SAVETITLE, 0,60, 7, 10);			
   gb.display.drawImage(71, 2, IMG_SAVETITLE, 0,70, 7, 10);
   
}   

void HS::Read()
{
   for (int rang = 0; rang==6; rang++)
   {
      m_Score[rang]=gb.save.get(rang);
   }
}

void HS::ChooseLetter()
{
   // Display letter 
   gb.display.setColor(RED);
   gb.display.setCursor(30+(m_LetterColumn*4), 24);
   gb.display.print(m_Alphabet[m_LetterPosition]);
   // move the letters with the arrows down and up
   if (gb.buttons.repeat(BUTTON_UP,8))
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
  if (gb.buttons.repeat(BUTTON_DOWN,8))
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
      for (int index=0; index < 26;index++)
      {
         if (m_Name[m_LetterColumn]==m_Alphabet[index])
         {
            m_LetterPosition=index;
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
      for (int index=0; index < 26;index++)
      {
         if (m_Name[m_LetterColumn]==m_Alphabet[index])
         {
            m_LetterPosition=index;
         }
      }
   } 
    gb.sound.playOK();
  }
   // displays the 3 characters
   for (unsigned int column=0;column<(strlen(m_Name));column++)
   {
      if (m_Name[column] != '0')
      {
         gb.display.setCursor(30+(column*4), 24);
         gb.display.print(m_Name[column]);
      }
   
   }
   m_Name[m_LetterColumn]=m_Alphabet[m_LetterPosition];
   if (gb.buttons.pressed(BUTTON_A))
   {
      gb.display.print("ok");
   }
}
 
