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


unsigned long TimeGame;
int Mode = -1;
int Music = -1;
bool isPlaying = false;

void playMusic();
void stopMusic();

Game *SpaceBuino;
Menu *MainMenu;
HS *HighScore;

const char *MainMenuText[] = {"PLAY", "LEVEL", "SCORES", "CREDITS"};

void setup()
{
  // initialize the Gamebuino object
  gb.begin();
  gb.sound.playOK();
  SpaceBuino = new Game;
  MainMenu = new Menu(MainMenuText, 4);
  HighScore = new HS();
}


void loop()
{
  TimeGame = millis();
  gb.waitForUpdate();
  gb.display.clear();
  switch (Mode)
  {
    case -1:
      // play sound
      if (!isPlaying) playMusic();
      MainMenu->DisplayMenu(TimeGame);
      Mode = MainMenu->MoveText();
      break;
    case 0:
      if (isPlaying) stopMusic();
      HighScore->Display(TimeGame);
      /*
      if (SpaceBuino->GameOver())
      {
        SaveMenu->DisplaySave(TimeGame);
      }
      else
      {
        if (SpaceBuino->Play())
        {
          SpaceBuino->Start(TimeGame);
          SpaceBuino->Hit(TimeGame);
          
          SpaceBuino->EnemyShot();
          SpaceBuino->VerifyStateSpaceShip();
        }
        else
        {
          SpaceBuino->HomepageLevel();
        }
      }
      */
      break;
    case 1:
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
