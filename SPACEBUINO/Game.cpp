#include "Game.h"
#include "GameImage.h"
#include "Data.h"
#include <Gamebuino-Meta.h>

// Point of the enemies
#define CRAB_PT  10
#define CRAB_ANGRY_PT  20
#define SQUID_PT  20
#define SQUID_ANGRY_PT  30
#define OCTO_PT  40
#define OCTO_ANGRY_PT  50
#define LAZE_PT  60
#define LAZE_ANGRY_PT  80

// game configuration variable
#define SPEED_DESCENT_ENEMIES 600 // DEFAULT 600

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
  m_PlayerScore(0),
  m_Level(1),
  j_Save(0),
  i_Save(0),
  m_Play(0),
  m_GameOver(0),
  m_AnimateTextGame(-10),
  m_AnimateTextOver(70),
  m_PlayMusic(1),
  m_TimePlayMusic(0),
  m_CountTurn(0),
  m_EnemySpeed(1),
  m_CounterEndGame(0),
  m_Firework_X(0),
  m_Firework_Y(0) 
{
  // initialize base
  for (int row = 0 ; row < 4 ; row++)
  {
    for (int column = 0 ; column < 8 ; column++)
    {
      GridEnemy[row][column] = new Enemy(10 + (column * 8), 10 + (row * 8), LAZE, 10);
    }
  }
  m_ShootEnemy = new Shoot(8, 1); // Color RED and Speed
  Enterprise = new SpaceShip(20, 56); // X and Y
  m_ShootSpaceShip = new Shoot(10, 3); // Color YELLOW and Speed
  m_Space = new Space();
  m_TypeEnemy = new Enemy();
  m_Extra = new Capsule(20, 20);
}

//----------------------------------------------------------------------
//                           DESTRUCTOR
//----------------------------------------------------------------------

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
  delete m_TypeEnemy;
  delete m_Extra;
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
  m_PlayMusic = 1;
  m_TimePlayMusic = 0;
  m_CountTurn = 0;
  m_EnemySpeed = 1;
  m_CounterEndGame = 0;
  m_Firework_X = 0;
  m_Firework_Y = 0;  
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
unsigned int Game::PlayerScore() const
{
  return (m_PlayerScore);
}

//----------------------------------------------------------------------
//          Setters Methods
//----------------------------------------------------------------------
void Game::GameOver(bool ChangeGameOver)
{
  m_GameOver = ChangeGameOver;
}
void Game::Level(int ChangeLevel)
{
  m_Level = ChangeLevel;
}


//----------------------------------------------------------------------
//                          Main Method
//----------------------------------------------------------------------

void Game::Start(unsigned long Time)
{
  // animate background
  m_Space->Display();
  // Shoot spaceship
  if (gb.buttons.pressed(BUTTON_A) and Enterprise->State() == 1 and m_StateBreakTimeEnemy == 1)
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
  // Display
  Score();
  m_ShootSpaceShip->Move(UP);
  EnemyExplosion(Time);
  // disable the movements of the spaceship during the explosion
  if ( m_CurrentTime > m_BreakTimeSpaceShip )
  {
    Enterprise->Move();
  }
  Enterprise->Draw();
  EnemyMove(Time);
  EnemyShot();
  VerifyStateSpaceShip();
  // next level if all enemies are destroyed and speed enemies
  if ( EnemyAllDestroy() == 32 )
  {
    // verify the end game
    if( m_Level == 20)
    {
      EndGame(Time);
    }
    else
    {
      SpaceShipAnimate(Time);
      m_EnemySpeed = 1;
    }
  }
  else if ( EnemyAllDestroy() == 16 )
  {
    m_EnemySpeed = 2;
  }
  else if ( EnemyAllDestroy() == 30 )
  {
    m_EnemySpeed = 3;
  }
  else if ( EnemyAllDestroy() == 31 )
  {
    m_EnemySpeed = 3;
  }
  if (Enterprise->Life() == 0 )
  {
    Enterprise->State(0);
    GameOverAnimate(Time);
    // Saves progress levels
    int LevelSave = gb.save.get(10);
    if ( m_Level > LevelSave )
    {
      gb.save.set(10, m_Level);
    }
  }
  // activate a capsule
  if ( m_Extra->State() == true )
  {
    m_Extra->Display();
    m_Extra->Y( m_Extra->Y() + 1 );
    CapsuleCollision();
    // deactivates the capsule touches the ground
    if ( m_Extra->Y() > 70 )
    {
      m_Extra->State(false);
    }
  }
  else
  {
    gb.lights.clear();
  }
}

//----------------------------------------------------------------------
//             Method of modifying the array of enemies
//----------------------------------------------------------------------

void Game::EnemyTableModif()
{
  for (int row = 0 ; row < 4 ; row++)
  {
    for (int column = 0 ; column < 8 ; column++)
    {
      GridEnemy[row][column]->X(10 + (column * 8));
      GridEnemy[row][column]->Y(10 + (row * 8));
      GridEnemy[row][column]->Change(LevelEnemy[row + ((m_Level - 1) * 4)][column]);
      GridEnemy[row][column]->HitChange(LevelEnemy[row + ((m_Level - 1) * 4)][column]);
      GridEnemy[row][column]->Point(LevelEnemyPoint[row + ((m_Level - 1) * 4)][column]);
      GridEnemy[row][column]->State(1);
      GridEnemy[row][column]->Angry(0);
      switch (GridEnemy[row][column]->TypeEnemy())
      {
        case CRAB:
          GridEnemy[row][column]->Resistance(1);
          break;
        case SQUID:
          GridEnemy[row][column]->Resistance(2);
          break;
        case OCTO:
          GridEnemy[row][column]->Resistance(3);
          break;
        case LAZE:
          GridEnemy[row][column]->Resistance(4);
          break;
      }
    }
  }
}

//----------------------------------------------------------------------
//        Method of controlling the destruction of all enemies
//----------------------------------------------------------------------

int Game::EnemyAllDestroy()
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
  return (counter);
}

//----------------------------------------------------------------------
//               Method for the movement of enemies
//----------------------------------------------------------------------

void Game::EnemyMove(unsigned long Time)
{
  int PosEnemyLeft = 0;
  int PosEnemyRight = 0;
  int PosEnemyY = 0;
  bool EnemyState = 1;
  // check if the enemies are dead or alive
  for (int c = 0 ; c < 8 ; c++) // column
  {
    for (int r = 0 ; r < 4 ; r++) // row
    {
      if (GridEnemy[r][c]->State() == 1)
      {
        PosEnemyLeft = GridEnemy[r][c]->X();
        break;
      }
    }
    if (PosEnemyLeft != 0)
    {
      break;
    }
  }
  for (int c = 7 ; c > -1 ; c--) // column
  {
    for (int r = 0 ; r < 4 ; r++) // row
    {
      if (GridEnemy[r][c]->State() == 1)
      {
        PosEnemyRight = GridEnemy[r][c]->X();
        break;
      }
    }
    if (PosEnemyRight != 0)
    {
      break;
    }
  }
  // enemy movement
  for (int r = 0 ; r < 4 ; r++) // row
  {
    for (int c = 0 ; c < 8 ; c++) // column
    {
      int PosEnemyX = GridEnemy[r][c]->X();
      if (GridEnemy[r][c]->Direction() == 0 and PosEnemyLeft >= 2 )
      {
        GridEnemy[r][c]->X(PosEnemyX - m_EnemySpeed);
      }
      if (GridEnemy[r][c]->Direction() == 1 and PosEnemyRight <= 72 )
      {
        GridEnemy[r][c]->X(PosEnemyX + m_EnemySpeed);
      }
      // change the left right direction
      if ( PosEnemyLeft <= 2 )
      {
        GridEnemy[r][c]->Direction(1);
        m_CountTurn++;
      }
      if ( PosEnemyRight >= 72 )
      {
        GridEnemy[r][c]->Direction(0);
        m_CountTurn++;
      }
      // delay for the descent of the enemies
      if ( m_CountTurn == SPEED_DESCENT_ENEMIES and Enterprise->Life() != 0 )
      {
        for (int row = 0 ; row < 4 ; row++)
        {
          for (int column = 0 ; column < 8 ; column++)
          {
            PosEnemyY = GridEnemy[row][column]->Y();
            EnemyState = GridEnemy[row][column]->State();
            GridEnemy[row][column]->Y(PosEnemyY + 1);
            // check if the enemies hit the ground
            if (PosEnemyY > 50 and EnemyState == 1 )
            {
              Enterprise->Life(0);
            }
          }
        }
        m_CountTurn = 0;
      }
      GridEnemy[r][c]->Draw();
    }
  }
}

//----------------------------------------------------------------------
// Method check if an enemy is hit and create an explosion or to touch
//----------------------------------------------------------------------

void Game::EnemyExplosion(unsigned long Time)
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
        if
        (
          m_ShootSpaceShip->Y() <= (GridEnemy[j][i]->Y()) + 6
          and m_ShootSpaceShip->Y() >= GridEnemy[j][i]->Y()
        )
        {
          if ( m_StateBreakTimeEnemy == 1 and GridEnemy[j][i]->State() == 1 )
          {
            int Resistance = GridEnemy[j][i]->Resistance();
            Resistance--;
            GridEnemy[j][i]->Resistance(Resistance);
            if ( Resistance == 0 )
            {
              GridEnemy[j][i]->Change(EXPLOSE);
              // to make appear or not a capsule
              CapsuleChance(GridEnemy[j][i]->X(), GridEnemy[j][i]->Y());
            }
            else
            {
              GridEnemy[j][i]->Change(HIT);
            }
            GridEnemy[j][i]->Draw();
            m_BreakTimeEnemy = m_CurrentTime + 200;
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
    if ( GridEnemy[j_Save][i_Save]->Resistance() == 0 )
    {
      GridEnemy[j_Save][i_Save]->State(0);
    }
    else
    {
      GridEnemy[j_Save][i_Save]->Change(LevelEnemy[j_Save + ((m_Level - 1) * 4)][i_Save]);
    }
    m_StateBreakTimeEnemy = 1;
  }
}
//----------------------------------------------------------------------
//                  Method that manages the capsules
//----------------------------------------------------------------------
void Game::CapsuleChance(int EnemyCoorX, int EnemyCoorY)
{
  // chance of showing a capsule
  int ChanceShowCapsule = 0;
  if (m_Level < 6)
  {
    ChanceShowCapsule = random(0, 20);
  }
  else if ( m_Level < 11 and m_Level > 5 )
  {
    ChanceShowCapsule = random(0, 10);
  }
  else if ( m_Level < 16 and m_Level > 10 )
  {
    ChanceShowCapsule = random(0, 5);
  }
  else if ( m_Level < 21 and m_Level > 15 )
  {
    ChanceShowCapsule = random(0, 2);
  }
  int TypeCapsule = random(0, 2);
  // check if the protection is not active
  if ( Enterprise->Protection() == true and TypeCapsule == 1)
  {
    TypeCapsule = 0;  
  }
  // check number life
  if ( Enterprise->Life() == 4 and TypeCapsule == 0)
  {
    TypeCapsule = 2;
  }
  if ( ChanceShowCapsule == 1 and m_Extra->State() == false )
  {
    switch (TypeCapsule)
    {
      case 0:
        m_Extra->Color(CAPSULE_GREEN);
        break;
      case 1:
        m_Extra->Color(CAPSULE_BLUE);
        break;
      case 2:
        break;
    }
    if ( TypeCapsule != 2)
    {
      m_Extra->State(true);
      m_Extra->Move(EnemyCoorX , EnemyCoorY + 6 );
    }
  }
}

void Game::CapsuleCollision ()
{
  if (
    ( Enterprise->X() < m_Extra->X() and (Enterprise->X() + 6 ) > m_Extra->X() )
    or
    ( Enterprise->X() < ( m_Extra->X() + 5 ) and (Enterprise->X() + 6 ) > m_Extra->X() )
  )
  {
    if ( m_Extra->Y() > Enterprise->Y() and m_Extra->Y() < ( Enterprise->Y() + 6 ) )
    {
      switch (m_Extra->Color())
      {
        case CAPSULE_GREEN:
          gb.lights.fill(GREEN);
          gb.sound.play("Life2.wav");
          Enterprise->Life(Enterprise->Life() + 1);
          break;
        case CAPSULE_BLUE:
          gb.lights.fill(BLUE);
          gb.sound.play("Protection2.wav");
          Enterprise->Protection(1);
          break;
      }
      m_Extra->State(false);
    }
  }
}

//----------------------------------------------------------------------
//                 Method Display Score and Life
//----------------------------------------------------------------------

void Game::Score()
{
  gb.display.setCursor(5, 2);
  gb.display.setColor(WHITE);
  gb.display.print(m_PlayerScore);
  gb.display.setColor(GRAY);
  gb.display.setCursor(25, 2);
  gb.display.print("LEVEL ");
  gb.display.print(m_Level);
  gb.display.setColor(WHITE);
  gb.display.setCursor(60, 2);
  gb.display.print(Enterprise->Life());
  gb.display.print(" X");
  gb.display.drawImage(74, 2, IMG_SPACESHIPLIFE);
}

//----------------------------------------------------------------------
//         Method that manages the random shooting of enemies
//----------------------------------------------------------------------

void Game::EnemyShot()
{

  // check if the ship is destroyed and the active shoot
  if (m_ShootEnemy->State() and Enterprise->State() == 1 )
  {
    m_ShootEnemy->Move(DOWN);
  }
  // new random shot
  else
  {
    m_ShootColumnEnemy = random(0, 8);
    for (int row = 3 ; row > -1 ; row--)
    {
      m_ShootLineEnemy = row;
      if (GridEnemy[row][m_ShootColumnEnemy]->State() == 1)
      {
        int PosX = GridEnemy[row][m_ShootColumnEnemy]->X();
        int PosY = GridEnemy[row][m_ShootColumnEnemy]->Y();
        int PosXShoot = m_ShootColumnEnemy + PosX;
        int PosYShoot = m_ShootColumnEnemy + PosY;
        //m_ShootEnemy->Position(PosXShoot, 14 + (m_ShootLineEnemy * 8));
        m_ShootEnemy->Position(PosXShoot, PosYShoot);
        m_ShootEnemy->State(1);
        // modif state enemy and point
        GridEnemy[row][m_ShootColumnEnemy]->Angry(1);

        // speed and type shoot
        switch (GridEnemy[row][m_ShootColumnEnemy]->TypeEnemy())
        {
          case CRAB:
            m_ShootEnemy->Speed(1);
            GridEnemy[row][m_ShootColumnEnemy]->Point(CRAB_ANGRY_PT);
            break;
          case SQUID:
            m_ShootEnemy->Speed(1);
            GridEnemy[row][m_ShootColumnEnemy]->Point(SQUID_ANGRY_PT);
            break;
          case OCTO:
            m_ShootEnemy->Speed(2);
            GridEnemy[row][m_ShootColumnEnemy]->Point(SQUID_ANGRY_PT);
            break;
          case LAZE:
            m_ShootEnemy->Speed(3);
            GridEnemy[row][m_ShootColumnEnemy]->Point(LAZE_ANGRY_PT);
            break;
        }
        break;
      }
    }
  }

}

//----------------------------------------------------------------------
//             check if the spaceship is hit by a shot
//----------------------------------------------------------------------

void Game::VerifyStateSpaceShip()
{
  if  (m_ShootEnemy->X() >= Enterprise->X() and m_ShootEnemy->X() <= (Enterprise->X()) + 6  )
  {
    if (m_ShootEnemy->Y() <= (Enterprise->Y()) + 6 and m_ShootEnemy->Y() >= Enterprise->Y())
    {
      // check the protection
      if (Enterprise->Protection() == false )
      {
        Enterprise->Position(3);
        Enterprise->Draw();
        if ( m_StateBreakTimeSpaceShip == 1 and Enterprise->State() == 1 )
        {
          m_BreakTimeSpaceShip = m_CurrentTime + 500;
          m_StateBreakTimeSpaceShip = 0;
          EnemyShot();
          Enterprise->Life(Enterprise->Life() - 1);
          gb.lights.fill(RED);
        }
      }
      // disincrement protection
      else
      {
        // reset shot
        m_ShootEnemy->Position(100, 59);
        // disincrement protection
        Enterprise->ProtectionDuration(Enterprise->ProtectionDuration() - 1);
        gb.lights.fill(BLUE);
        if ( Enterprise->ProtectionDuration() == 0)
        { 
          Enterprise->ProtectionDuration(2);
          Enterprise->Protection(false);
        }
        gb.sound.play("Collect_pt_3.wav");
      }
    }
    
  }
  if (m_CurrentTime > m_BreakTimeSpaceShip and m_StateBreakTimeSpaceShip == false)
  {
    Enterprise->Position(1);
    m_StateBreakTimeSpaceShip = 1;
    // desactive light
    gb.lights.clear();
  }
}

//----------------------------------------------------------------------
//                        Home page levels
//----------------------------------------------------------------------

void Game::HomepageLevel()
{
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
    }
  }
  gb.display.setColor(WHITE);
  gb.display.setCursor(14, 54);
  gb.display.print("PRESS BUTTON A");
  if (gb.buttons.pressed(BUTTON_A) )
  {
    m_Play = 1;
    // activate music
    m_PlayMusic = 1;
    m_TimePlayMusic = 0;
    EnemyTableModif();
    Enterprise->X(20);
    Enterprise->Y(56);
  }
}

//----------------------------------------------------------------------
//                ship animation at the end of the level
//----------------------------------------------------------------------

void Game::SpaceShipAnimate(unsigned long Time)
{
  m_CurrentTime = Time;
  if ( m_CurrentTime > m_BreakTimeSpaceShip and m_StateBreakTimeSpaceShip  == 0 )
  {
    m_BreakTimeSpaceShip  = m_CurrentTime + 10;
    m_StateBreakTimeSpaceShip  = 0;
  }
  if ( m_CurrentTime > m_BreakTimeSpaceShip  and m_StateBreakTimeSpaceShip  == 1)
  {
    m_BreakTimeSpaceShip  = Time + 10;
    m_StateBreakTimeSpaceShip  = 1;
    Enterprise->Y(Enterprise->Y() - 2);
  }
  gb.display.setColor(YELLOW);
  gb.display.fillRect(Enterprise->X() + 2, Enterprise->Y(), 2, 100);
  Enterprise->Draw();
  if ( Enterprise->Y() < 0 )
  {
    m_Play = 0;
    if ( m_Level !=20 )
    {
      m_Level++;
    }
  }
  if ( m_PlayMusic == 1 )
  {
    gb.sound.play("End1.wav");
    if (m_TimePlayMusic == 0)
    {
      m_TimePlayMusic  = Time + 700;
    }
  }
  if ( m_CurrentTime > m_TimePlayMusic )
  {
    m_PlayMusic = 0;
  }
  m_Extra->State(false);
}

//----------------------------------------------------------------------
//                      animation game over
//----------------------------------------------------------------------

void Game::GameOverAnimate(unsigned long Time)
{
  // desactive light
  gb.lights.clear();
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
    m_BreakTimeSpaceShip  = Time + 20;
    m_StateBreakTimeSpaceShip  = 1;
  }
  gb.display.drawImage(18, m_AnimateTextGame, IMG_GAME);
  gb.display.drawImage(18, m_AnimateTextOver, IMG_OVER);
  gb.lights.drawPixel(0, 2, GREEN);
  gb.lights.drawPixel(1, 2, GREEN);

  if ( m_PlayMusic == 1 )
  {

    gb.sound.play("Game_over.wav");
    if (m_TimePlayMusic == 0)
    {
      m_TimePlayMusic  = Time + 700;
    }
  }
  if ( m_CurrentTime > m_TimePlayMusic )
  {
    m_PlayMusic = 0;
  }
  if (gb.buttons.pressed(BUTTON_A))
  {
    m_GameOver = 1;
  }
  gb.lights.fill(GREEN);
}

//----------------------------------------------------------------------
//                                 END GAME
//----------------------------------------------------------------------

void Game::EndGame(unsigned long Time)
{

  // animate background
  m_Space->Display();
  // animate firawork
  m_CounterEndGame++;
  if (m_CounterEndGame == 1)
  {
    // desactive light
    gb.lights.clear();
    m_Firework_X = random (10,70);
    m_Firework_Y = random (10,50);
  }
  if (m_CounterEndGame < 15)
  {
    gb.display.drawImage(m_Firework_X, m_Firework_Y, IMG_FIREWORK_GREEN);
    gb.lights.drawPixel(m_Firework_X/40, m_Firework_Y/15, GREEN);
    gb.display.setColor(YELLOW);
    gb.display.fillRect(Enterprise->X() + 2, Enterprise->Y(), 2, 100);
  }
  else 
  {
    m_CounterEndGame = 0;
  }  
  // title and spaceship
  gb.display.setColor(54, 255, 175);
  gb.display.setCursor(5, 10);
  gb.display.print("CONGRATULATIONS !");
  Enterprise->Y(27);
  Enterprise->X(37);
  Enterprise->Draw();
  if ( m_PlayMusic == 1 )
  {

    gb.sound.play("Win.wav");
    if (m_TimePlayMusic == 0)
    {
      m_TimePlayMusic  = Time + 4000;
    }
  }
  if ( m_CurrentTime > m_TimePlayMusic )
  {
    m_PlayMusic = 0;
  }
  if (gb.buttons.pressed(BUTTON_A))
  {
    m_GameOver = 1;
  }
};  
