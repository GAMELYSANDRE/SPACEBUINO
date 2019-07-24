#include "Game.h"
#include "GameImage.h"
#include "Data.h"
#include <Gamebuino-Meta.h>

#define CRAB_PT  10
#define CRAB_ANGRY_PT  20
#define SQUID_PT  25
#define SQUID_ANGRY_PT  35
#define OCTO_PT  40
#define OCTO_ANGRY_PT  45
#define LAZE_PT  50
#define LAZE_ANGRY_PT  55



//----------------------------------------------------------------------
//              CONSTRUCTOR
//----------------------------------------------------------------------
Game::Game ():
  m_ShootColumnEnemy(0),
  m_ShootLineEnemy(0),
  m_CurrentTime(0),
  m_StateBreakTimeEnemy(1),
  m_BreakTimeEnemy(0),
  m_StateBreakTimeSpaceShip(1),
  m_BreakTimeSpaceShip(0),
  j_Save(0),
  i_Save(0),
  m_Level(1),
  m_PlayerScore(0),
  m_Play(0),
  m_GameOver(0),
  m_AnimateTextGame(-10),
  m_AnimateTextOver(70),
  m_PlayMusic(0),
  m_TimePlayMusic(0)
{
  // initialize base
  for (int row = 0 ; row < 4 ; row++)
  {
    for (int i = 0 ; i < 8 ; i++)
    {
      GridEnemy[row][i] = new Enemy(10 + (i * 8), 10 + (row * 8), LAZE, 10);
    }
  }
  m_ShootEnemy = new Shoot(8, 1); // Color and Speed
  Enterprise = new SpaceShip(20, 56); // X and Y
  m_ShootSpaceShip = new Shoot(10, 3); // Color and Speed
  m_Space = new Space();
  m_TypeEnemy = new Enemy();
}

Game::~Game()
{
  for (int j = 0 ; j < 4 ; j++)
  {
    for (int i = 0 ; i < 8 ; i++)
    {
      delete GridEnemy[j][i];
    }
  }
  delete m_ShootEnemy;
  delete Enterprise;
  delete m_ShootSpaceShip;
  delete m_Space;
}

void Game::Reset()
{
  m_ShootColumnEnemy = 0;
  m_ShootLineEnemy = 0;
  m_CurrentTime = 0;
  m_StateBreakTimeEnemy = 1;
  m_BreakTimeEnemy = 0;
  m_StateBreakTimeSpaceShip = 1;
  m_BreakTimeSpaceShip = 0;
  j_Save = 0;
  i_Save = 0;
  m_Level = 1;
  m_PlayerScore = 0;
  m_Play = 0;
  m_GameOver = 0;
  m_AnimateTextGame = -10;
  m_AnimateTextOver = 70;
  m_PlayMusic = 0;
  m_TimePlayMusic = 0;
  Enterprise->Reset();
}

//----------------------------------------------------------------------
//           Getters Methods
//----------------------------------------------------------------------
bool Game::Play() const
{
  return (m_Play);
}
bool Game::GameOver() const
{
  return (m_GameOver);
}

//----------------------------------------------------------------------
//          Setters Methods  
//----------------------------------------------------------------------
void Game::GameOver(bool ChangeGameOver)
{
  m_GameOver = ChangeGameOver;
}

//----------------------------------------------------------------------
//           Main Method
//----------------------------------------------------------------------

void Game::Start(unsigned long Time)
{
  // animate background
  m_Space->Display();
  if (gb.buttons.pressed(BUTTON_A) and Enterprise->State() == 1 )
  {
    if (m_ShootSpaceShip->State())
    {

    }
    else
    {
      m_ShootSpaceShip->Position(Enterprise->X() + 2, Enterprise->Y());
      m_ShootSpaceShip->State(1);
      gb.sound.play("laser.wav");
    }
  }
  // affiche 
  Score();
  m_ShootSpaceShip->Move(UP);
  Enterprise->Move();
  Enterprise->Draw();
  MoveEnemy();
  if ( EnemyAllDestroy() == 1 )
  {
    SpaceShipAnimate(Time);
  }
  if (Enterprise->Life() == 0 )
  {
    Enterprise->State(0);
    GameOverAnimate(Time);
  }
}

//--------------------------------------------
//  method of modifying the array of enemies
//--------------------------------------------

void Game::EnemyTableModif()
{
  for (int row = 0 ; row < 4 ; row++)
  {
    for (int column = 0 ; column < 8 ; column++)
    {
      GridEnemy[row][column]->Change(LevelEnemy[row + ((m_Level - 1) * 4)][column]);
      GridEnemy[row][column]->Point(LevelEnemyPoint[row + ((m_Level - 1) * 4)][column]);
      GridEnemy[row][column]->State(1);
      GridEnemy[row][column]->Angry(0);
    }
  }
}

//--------------------------------------------------------
//  method of controlling the destruction of all enemies
//--------------------------------------------------------

bool Game::EnemyAllDestroy()
{
  int counter = 0;
  // increments the counter
  for (int row = 0 ; row < 4 ; row++)
  {
    for (int column = 0 ; column < 8 ; column++)
    {
      if ( GridEnemy[row][column]->State() == 0 )
      {
        counter++;
      }
    }
  }
  // control the counter
  if ( counter == 32 )
  {
    return (true);
  }
  return (false);
}

//-----------------------------------------
// method for the movement of enemies
//-----------------------------------------

void Game::MoveEnemy()
{
  int PosEnemyLeft = 0;
  int PosEnemyRight = 0;
  for (int j = 0 ; j < 4 ; j++)
  {
    for (int i = 0 ; i < 8 ; i++)
    {
      if (GridEnemy[j][i]->State() == 1)
      {
        PosEnemyLeft = GridEnemy[j][i]->X();
        break;
      }
    }
    if (PosEnemyLeft != 0)
    {
      break;
    }
  }
  for (int j = 0 ; j < 4 ; j++)
  {
    for (int i = 7 ; i > -1 ; i--)
    {
      if (GridEnemy[j][i]->State() == 1)
      {
        PosEnemyRight = GridEnemy[j][i]->X();
        break;
      }
    }
    if (PosEnemyRight != 0)
    {
      break;
    }
  }

  for (int j = 0 ; j < 4 ; j++)
  {
    for (int i = 0 ; i < 8 ; i++)
    {
      int PosEnemyX = GridEnemy[j][i]->X();
      if (GridEnemy[j][i]->Direction() == 0 and PosEnemyLeft >= 2 )
      {
        GridEnemy[j][i]->X(PosEnemyX - 1);
      }
      if (GridEnemy[j][i]->Direction() == 1 and PosEnemyRight <= 72 )
      {
        GridEnemy[j][i]->X(PosEnemyX + 1);
      }
      GridEnemy[j][i]->Draw();

      if ( PosEnemyLeft <= 2 )
      {
        GridEnemy[j][i]->Direction(1);
      }
      if ( PosEnemyRight >= 72 )
      {
        GridEnemy[j][i]->Direction(0);
      }

    }
  }
}


void Game::Hit(unsigned long Time)
{
  m_CurrentTime = Time;
  for (int j = 0 ; j < 4 ; j++)
  {
    for (int i = 0 ; i < 8 ; i++)
    {
      if
      (
        m_ShootSpaceShip->X() >= GridEnemy[j][i]->X()
        and m_ShootSpaceShip->X() <= (GridEnemy[j][i]->X()) + 6
      )
      {
        if (m_ShootSpaceShip->Y() <= (GridEnemy[j][i]->Y()) + 6 and m_ShootSpaceShip->Y() >= GridEnemy[j][i]->Y())
        {
          if ( m_StateBreakTimeEnemy == 1 and GridEnemy[j][i]->State() == 1 )
          {
            GridEnemy[j][i]->Change(EXPLOSE);
            GridEnemy[j][i]->Draw();
            m_BreakTimeEnemy = m_CurrentTime + 300;
            m_StateBreakTimeEnemy = 0;
            m_ShootSpaceShip->State(0);
            m_ShootSpaceShip->Position(0, 0);
            j_Save = j;
            i_Save = i;
            m_PlayerScore = m_PlayerScore + GridEnemy[j][i]->Point();
          }
        }
      }
    }
  }
  if (m_CurrentTime > m_BreakTimeEnemy and m_StateBreakTimeEnemy == false)
  {
    GridEnemy[j_Save][i_Save]->State(0);
    m_StateBreakTimeEnemy = 1;
  }
}
//----------------------------------------------------------------------
//  Method Display Score and Life
//----------------------------------------------------------------------

void Game::Score()
{
  gb.display.setCursor(5, 2);
  gb.display.setColor(WHITE);
  gb.display.print(m_PlayerScore);
  gb.display.setCursor(60, 2);
  gb.display.print(Enterprise->Life());
  gb.display.print(" X");
  gb.display.drawImage(74, 2, IMG_SPACESHIPLIFE);
}

//----------------------------------------------------------------------
//  Method that manages the random shooting of enemies
//----------------------------------------------------------------------

void Game::EnemyShot()
{
  // check if the ship is destroyed
  if (m_ShootEnemy->State() and Enterprise->State() == 1 )
  {
    m_ShootEnemy->Move(DOWN);
  }
  else
  {
    m_ShootColumnEnemy = random(0, 8);
    for (int j = 3 ; j > -1 ; j--)
    {
      m_ShootLineEnemy = j;
      if (GridEnemy[j][m_ShootColumnEnemy]->State() == 1)
      {
        m_ShootEnemy->Position(12 + (m_ShootColumnEnemy * 8), 14 + (m_ShootLineEnemy * 8));
        m_ShootEnemy->State(1);
        GridEnemy[j][m_ShootColumnEnemy]->Angry(1);
        GridEnemy[j][m_ShootColumnEnemy]->Point(CRAB_ANGRY_PT);
        // speed and type shoot
        switch (GridEnemy[j][m_ShootColumnEnemy]->TypeEnemy())
        {
          case CRAB:
            m_ShootEnemy->Speed(1);
            break;
          case SQUID:
            m_ShootEnemy->Speed(2);
            break;
          case OCTO:

            break;
          case LAZE:

            break;
        }
        break;
      }
    }
  }

}

void Game::VerifyStateSpaceShip()
{
  if  (m_ShootEnemy->X() >= Enterprise->X() and m_ShootEnemy->X() <= (Enterprise->X()) + 6  )
  {
    if (m_ShootEnemy->Y() <= (Enterprise->Y()) + 6 and m_ShootEnemy->Y() >= Enterprise->Y())
    {
      Enterprise->Position(3);
      Enterprise->Draw();
      if ( m_StateBreakTimeSpaceShip == 1 and Enterprise->State() == 1 )
      {
        m_BreakTimeSpaceShip = m_CurrentTime + 500;
        m_StateBreakTimeSpaceShip = 0;
        m_ShootEnemy->Position(0, 0);
        Enterprise->Life(Enterprise->Life() - 1);
      }
    }
  }
  if (m_CurrentTime > m_BreakTimeSpaceShip and m_StateBreakTimeSpaceShip == false)
  {
    Enterprise->Position(1);
    m_StateBreakTimeSpaceShip = 1;

  }
}

//---------------------------------------------
//         home page levels
//---------------------------------------------

void Game::HomepageLevel()
{
  // Voice level
  //gb.sound.play("level_1.WAV", true);
  // desactive light
  gb.lights.clear();
  // animate background
  m_Space->Display();
  // text title
  gb.display.setCursor(21, 3);
  gb.display.setColor(80, 80, 80);
  gb.display.print("- LEVEL ");
  gb.display.print(m_Level);
  gb.display.print(" -");
  gb.display.setCursor(20, 3);
  gb.display.setColor(119, 181, 254);
  gb.display.print("- LEVEL ");
  gb.display.print(m_Level);
  gb.display.print(" -");
  // show the value of the enemies
  for (int i = 0; i < 4; i++)
  {
    if (LevelHomepage[m_Level - 1][i] == EMPTY)
    {

    }
    else
    {
      m_TypeEnemy->X(23);
      m_TypeEnemy->Y(13 + (8 * i));
      m_TypeEnemy->Change(LevelHomepage[m_Level - 1][i]);
      m_TypeEnemy->Angry(0);
      m_TypeEnemy->Draw();
      m_TypeEnemy->Angry(1);
      m_TypeEnemy->X(53);
      m_TypeEnemy->Draw();
      switch (LevelHomepage[m_Level - 1][i])
      {
        case CRAB:
          gb.display.setColor(255, 169, 0);
          gb.display.setCursor(1, 14 + (8 * i));
          gb.display.print("CRAB");
          gb.display.setCursor(32, 14 + (8 * i));
          gb.display.print(CRAB_PT);
          gb.display.print("pt");
          gb.display.setCursor(62, 14 + (8 * i));
          gb.display.setColor(147, 0, 172);
          gb.display.print(CRAB_ANGRY_PT);
          gb.display.print("pt");
          break;
        case SQUID:
          gb.display.setColor(0, 174, 64);
          gb.display.setCursor(1, 14 + (8 * i));
          gb.display.print("SQUID");
          gb.display.setCursor(32, 14 + (8 * i));
          gb.display.print(SQUID_PT);
          gb.display.print("pt");
          gb.display.setCursor(62, 14 + (8 * i));
          gb.display.setColor(147, 0, 172);
          gb.display.print(SQUID_ANGRY_PT);
          gb.display.print("pt");
          break;
        case OCTO:
          gb.display.setColor(147, 0, 172);
          gb.display.setCursor(1, 14 + (8 * i));
          gb.display.print("OCTO");
          gb.display.setCursor(32, 14 + (8 * i));
          gb.display.print(OCTO_PT);
          gb.display.print("pt");
          gb.display.setCursor(62, 14 + (8 * i));
          gb.display.setColor(147, 0, 172);
          gb.display.print(OCTO_ANGRY_PT);
          gb.display.print("pt");
          break;
        case LAZE:
          gb.display.setColor(6, 64, 141);
          gb.display.setCursor(1, 14 + (8 * i));
          gb.display.print("LAZE");
          gb.display.setCursor(32, 14 + (8 * i));
          gb.display.print(LAZE_PT);
          gb.display.print("pt");
          gb.display.setCursor(62, 14 + (8 * i));
          gb.display.setColor(147, 0, 172);
          gb.display.print(LAZE_ANGRY_PT);
          gb.display.print("pt");
          break;
      }
      //gb.display.print(" pt");
    }
  }
  gb.display.setColor(WHITE);
  gb.display.setCursor(14, 54);
  gb.display.print("PRESS BUTTON A");
  if (gb.buttons.pressed(BUTTON_A) )
  {
    m_Play = 1;
    EnemyTableModif();
    Enterprise->X(20);
    Enterprise->Y(56);
  }
}

//----------------------------------------------
//    ship animation at the end of the level
//----------------------------------------------

void Game::SpaceShipAnimate(unsigned long Time)
{
  // animate title
  m_CurrentTime = Time;
  if ( m_CurrentTime > m_BreakTimeSpaceShip and m_StateBreakTimeSpaceShip  == 1 )
  {
    m_BreakTimeSpaceShip  = Time + 15;
    m_StateBreakTimeSpaceShip  = 0;
  }
  if ( m_CurrentTime > m_BreakTimeSpaceShip  and m_StateBreakTimeSpaceShip  == 0)
  {
    m_BreakTimeSpaceShip  = Time + 15;
    m_StateBreakTimeSpaceShip  = 1;
    Enterprise->Y(Enterprise->Y() - 3);
  }
  gb.display.setColor(YELLOW);
  gb.display.fillRect(Enterprise->X() + 2, Enterprise->Y(), 2, 100);
  Enterprise->Draw();
  if ( Enterprise->Y() < 0 )
  {
    m_Play = 0;
    m_Level++;
  }
  gb.sound.play("End1.wav");
}

//--------------------------
//    animation game over
//--------------------------

void Game::GameOverAnimate(unsigned long Time)
{
  m_CurrentTime = Time;
  if ( m_CurrentTime > m_BreakTimeSpaceShip and m_StateBreakTimeSpaceShip  == 1 )
  {
    m_BreakTimeSpaceShip  = Time + 5;
    if ( m_AnimateTextGame < 18 )
    {
      m_AnimateTextGame = m_AnimateTextGame + 4;
    }
    if ( m_AnimateTextOver > 32 )
    {
      m_AnimateTextOver = m_AnimateTextOver - 4;
    }
    m_StateBreakTimeSpaceShip  = 0;
  }
  if ( m_CurrentTime > m_BreakTimeSpaceShip  and m_StateBreakTimeSpaceShip  == 0)
  {
    m_BreakTimeSpaceShip  = Time + 5;
    m_StateBreakTimeSpaceShip  = 1;
  }
  gb.display.drawImage(18, m_AnimateTextGame, IMG_GAME);
  gb.display.drawImage(18, m_AnimateTextOver, IMG_OVER);
  gb.lights.drawPixel(0, 2, GREEN);
  gb.lights.drawPixel(1, 2, GREEN);

  if ( m_PlayMusic == 0 )
  {

    gb.sound.play("Game_over.wav");
    if (m_TimePlayMusic == 0)
    {
      m_TimePlayMusic  = Time + 700;
    }
  }
  if ( m_CurrentTime > m_TimePlayMusic )
  {
    m_PlayMusic = 1;
  }
  if (gb.buttons.pressed(BUTTON_A))
  {
    m_GameOver=1;
  }
}
