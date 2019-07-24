#include "HighScore.h"
#include "HighScoreImage.h"
#include <Gamebuino-Meta.h>

HS::HS () :
   m_LetterPosition(0),
   m_LetterColumn(0),
   m_NewScore(0),
   m_SaveScore(1),
   m_Mode(0)
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
   gb.save.set(0,100000);
   gb.save.set(1,10000);
   gb.save.set(2,1000);
   gb.save.set(3,100);
   gb.save.set(4,10);
   gb.save.set(5,5);
   */
   /*
   gb.save.set(6,"SAN");
   gb.save.set(7,"LAU");
   gb.save.set(8,"COC");
   gb.save.set(9,"CLE");
   gb.save.set(10,"DOD");
   gb.save.set(11,"PTR");
   */
}
//----------------------------------------------------------------------
//           Getters functions        
//----------------------------------------------------------------------

int HS::Mode()
{
   return(m_Mode);
}

//----------------------------------------------------------------------
//          Setters Methods  
//----------------------------------------------------------------------
void HS::Mode(int ChangeMode)
{
  m_Mode = ChangeMode;
}



void HS::Display(unsigned long Time,unsigned int Score)
{ 
   // erase the lights
   gb.lights.clear();
   // display title
   Title(Time);
   if ( m_SaveScore == true)
   {
      // read the scores
         Read();
      // compare the new score
         Compare(Score);
      // save the new score
         ChooseLetter(Score); 
   }
   else
   {
      // exit the high scores
      if (gb.buttons.pressed(BUTTON_A) or gb.buttons.pressed(BUTTON_B) )
      {
         m_Mode = -1;
         gb.sound.playTick();
      }
   }
   gb.display.setColor(BLUE);
   gb.display.setCursor(5, 15);	
   gb.display.println("RANK  NAME  SCORE");
   for (unsigned int row = 0; row < 6; row++)
   {
      if (m_NewScore != row or m_SaveScore == false)
      {
         gb.display.setColor(DARKBLUE);
         // RANK
         gb.display.setCursor(12, 24+(row*6));	
         gb.display.print(row+1);
         // NAME
         gb.display.setCursor(30, 24+(row*6));
         char temp1[3];
         gb.save.get(row+6, temp1, 3);
         gb.display.print(temp1);
         // SCORE
         gb.display.setCursor(51, 24+(row*6));
         gb.display.print(m_Score[row]); 
      }
      else
      {
         gb.display.setColor(RED);
         // RANK
         gb.display.setCursor(12, 24+(row*6));	
         gb.display.print(row+1);
         // NEW SCORE
         gb.display.setCursor(51, 24+(row*6));
         gb.display.print(Score); 
      }
   }
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
   for (int rang = 0; rang < 6; rang++)
   {
      m_Score[rang]=gb.save.get(rang);
   }
}

void HS::ChooseLetter(unsigned int Score)
{
   // Display letter 
   gb.display.setColor(GRAY);
   gb.display.fillRect(29+(m_LetterColumn*4), 23+(m_NewScore*6), 5, 7);
   gb.display.setColor(RED);
   gb.display.setCursor(30+(m_LetterColumn*4), 24+(m_NewScore*6));
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
         gb.display.setCursor(30+(column*4), 24+(m_NewScore*6));
         gb.display.print(m_Name[column]);
      }
   
   }
   m_Name[m_LetterColumn]=m_Alphabet[m_LetterPosition];
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
      strcpy(temp1,m_Name);
      gb.save.set(m_NewScore+6, temp1);
      // save the score du new player
      gb.save.set(m_NewScore, Score);
      m_SaveScore = 0;
      gb.sound.playTick();
   }
   //gb.display.print(m_NewScore);
}
//----------------------------------------------------------------------
//    Method that compares the new score with the scores recorded
//----------------------------------------------------------------------

void HS::Compare(unsigned int Score)
{
   // test rang 6
   if (Score > m_Score[5])
   {  
      // test rang 5
      if (Score > m_Score[4])
      {
         // test rang 4
         if (Score > m_Score[3])
         {
            // test rang 3
            if (Score > m_Score[2])
            {
               // test rang 2
               if (Score > m_Score[1])
               {
                  // test rang 1
                  if (Score > m_Score[0])
                  {
                     m_NewScore = 0;
                  }    
                  else
                  {
                     m_NewScore = 1;
                  }               
               }    
               else
               {
                  m_NewScore = 2;
               }    
            }    
            else
            {
               m_NewScore = 3;
            }
         }
         else
         {
            m_NewScore = 4;
         }
      }
      else
      {
         m_NewScore = 5;
      }
   }
   else
   {
      // score lower than all others   
      m_SaveScore = 0;
   }
}

