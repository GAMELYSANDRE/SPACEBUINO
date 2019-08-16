#ifndef __Game__
#define __Game__
#include "Enemy.h"
#include "SpaceShip.h"
#include "Shoot.h"
#include "Space.h"

class Game
{
  public:

    // constructor
    Game ();
    // Destructor
    ~Game();
    //------------------------------------------------------------------
    //     Variables Game
    //------------------------------------------------------------------

    // getters functions
    bool Play() const;
    bool GameOver() const;
    unsigned int PlayerScore() const;

    // setters methods
    void Level(int ChangeLevel);
    void GameOver(bool ChangeGameOver);

    void Reset();
    void Start(unsigned long Time);
    
    void Score();

    void HomepageLevel();
    void SpaceShipAnimate(unsigned long Time);

  private:

    //------------------------------------------------------------------
    //   Variables SpaceShip
    //------------------------------------------------------------------
    SpaceShip *Enterprise;   // pointer on the space ship
    Shoot *m_ShootSpaceShip; // pointer on the shooting of the spaceship

    //------------------------------------------------------------------
    //     Variables Enemy
    //------------------------------------------------------------------
    Enemy *GridEnemy[4][8];  // pointer on a grid of enemies
    Shoot *m_ShootEnemy;     // pointer on the shooting of the enemy
    int m_ShootColumnEnemy;  // save the position of the column (0 to 7)
    int m_ShootLineEnemy;    // save the position of the line (0 to 3)
    int m_CountTurn;         // count the number of enemies turn to go down

    //------------------------------------------------------------------
    //     Variables Game
    //------------------------------------------------------------------

    // classical variables
    unsigned int m_PlayerScore;
    int m_Level;
    bool m_Play;                  // play the game
    bool m_GameOver;              // end the game
    int m_AnimateTextGame;        // to animate the text game
    int m_AnimateTextOver;        // to animate the text over
    bool m_PlayMusic;             // play the music
    unsigned long m_TimePlayMusic;// delay play the music
    Space *m_Space;               // pointer on the space
    Enemy *m_TypeEnemy;           // shows the type of enemy



    //------------------------------------------------------------------
    //  variable time management for the animation of the explosion
    //------------------------------------------------------------------
    unsigned long m_CurrentTime;       // current time
    bool m_StateBreakTimeEnemy;        // active(1) or inactive(0) pause
    unsigned long m_BreakTimeEnemy;    // duration of the break
    
    //------------------------------------------------------------------
    //  variable time management for the animation of the starship
    //------------------------------------------------------------------
    bool m_StateBreakTimeSpaceShip;    // active(1) or inactive(0) pause
    unsigned long m_BreakTimeSpaceShip;// duration of the break

    //------------------------------------------------------------------
    //             save the variable j and i to change state        
    //             of the enemy at the end of the time elapse       
    //------------------------------------------------------------------
    int j_Save;                 // j -> first column in the enemy grid
    int i_Save;                 // i -> Second column in the enemy grid

    //------------------------------------------------------------------
    //     Methods SpaceShip
    //------------------------------------------------------------------
    void VerifyStateSpaceShip();

    //------------------------------------------------------------------
    //       Methods Enemy
    //------------------------------------------------------------------
    void EnemyShot();
    void EnemyTableModif();
    void EnemyMove(unsigned long Time);
    bool EnemyAllDestroy();
    void EnemyExplosion(unsigned long Time);

    //---------------------------
    //       Methods Game
    //---------------------------
    void GameOverAnimate(unsigned long Time);

};

#endif
