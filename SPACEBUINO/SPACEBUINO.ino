/*
  SPACEBUINO.ino

  Copyright 2019 Laurent Meurillon <gamelysandre@gmail.com>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
  MA 02110-1301, USA.


*/
#include <Gamebuino-Meta.h>
#include "Game.h"
#include "Menu.h"
#include "HighScore.h"
#include "Space.h"
#include "Level.h"
#include "Credit.h"



unsigned long TimeGame;
int Mode = -1;
int Music = -1;
bool isPlaying = false;

void playMusic();
void stopMusic();

Game *SpaceBuino;
Menu *MainMenu;
HS *HighScore;
Level *LevelMenu;
Credit *CreditMenu;

const char *MainMenuText[] =
{
  "PLAY",
  "LEVELS",
  "HIGH SCORES",
  "CREDITS"
};
# define MENU -1
# define PLAY 0
# define LEVEL 1
# define HIGHSCORES 2
# define CREDITS 3

void setup()
{
  // initialize the Gamebuino object
  gb.begin();
  // test level save
  //int Save = 0;
  //gb.save.set(10,Save);
  // test save HIGHSCORES
  /*
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
  */
  gb.sound.playOK();
  SpaceBuino = new Game;
  MainMenu = new Menu(MainMenuText, 4);
  HighScore = new HS();
  LevelMenu = new Level();
  CreditMenu = new Credit();
}


void loop()
{
  TimeGame = millis();
  gb.waitForUpdate();
  gb.display.clear();
  // standardizes the Mode variable in all classes
  MainMenu->Mode(Mode);
  LevelMenu->Mode(Mode);
  HighScore->Mode(Mode);
  CreditMenu->Mode(Mode);
  switch (Mode)
  {
//----------------------------------------------------------------------
//                            MAIN MENU
//----------------------------------------------------------------------
    case MENU :
      // play sound
      if (!isPlaying)
      {
        playMusic();
      }
      MainMenu->DisplayMenu(TimeGame);
      Mode = MainMenu->Mode();
      SpaceBuino->Reset();
      break;
//----------------------------------------------------------------------
//                            PLAY
//----------------------------------------------------------------------
    case PLAY :
      if (SpaceBuino->GameOver())
      {
        if (!isPlaying)
        {
          playMusic();
        }
        HighScore->Display(TimeGame, SpaceBuino->PlayerScore());
        Mode = HighScore->Mode();
      }
      else
      {
        if (isPlaying)
        {
          stopMusic();
        }
        if (SpaceBuino->Play())
        {
          SpaceBuino->Start(TimeGame);
        }
        else
        {
          SpaceBuino->HomepageLevel();
        }
      }
      break;
//----------------------------------------------------------------------
//                            LEVELS
//----------------------------------------------------------------------
    case LEVEL :
      LevelMenu->Display(TimeGame);
      Mode = LevelMenu->Mode();
      SpaceBuino->Level(LevelMenu->LevelGame());
      break;
//----------------------------------------------------------------------
//                            HIGHSCORES
//----------------------------------------------------------------------
    case HIGHSCORES :
      HighScore->Display(TimeGame, 0);
      Mode = HighScore->Mode();
      break;
//----------------------------------------------------------------------
//                            CREDITS
//----------------------------------------------------------------------
    case CREDITS:
      CreditMenu->Display();
      Mode = CreditMenu->Mode();
      break;
  }

}


void playMusic()
{
  Music = gb.sound.play("Space.WAV", true);
  isPlaying = true;
}
void stopMusic()
{
  gb.sound.stop(Music);
  isPlaying = false;
}
