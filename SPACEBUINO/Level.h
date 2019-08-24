#ifndef __LEVEL__
#define __LEVEL__

#include "Space.h"

class Level
{
  public:
    // constructor
    Level ();
    // destructor
    ~Level();

    // getters Methods
    int Mode();
    int LevelGame();   

    // setters methods
    void Mode(int ChangeMode);
    
    //------------------------------------------------------------------
    //                 Methods
    //------------------------------------------------------------------    
    //display the high scores
    void Display(unsigned long Time);

  private:
    //------------------------------------------------------------------
    //               Variables
    //------------------------------------------------------------------
    Space *m_Space;               // pointer on the spac
    int m_Level;
    int m_LevelSave;              // Save level
    bool m_Direction;             // Direction animate Right(1) Left(0)
    int m_Mode;                   // Variable main menu
        
    //------------------------------------------------------------------
    //        variable time management for the flashing Image
    //------------------------------------------------------------------
    unsigned long m_CurrentTime;      // current time
    bool m_StateBreakTimeImage;       // active(1) or inactive(0) pause
    unsigned long m_BreakTimeImage;   // duration of the break
    int m_NumberImage;                // compteur d'image

    //------------------------------------------------------------------
    //      variable time management for the animate image level
    //------------------------------------------------------------------
    bool m_StateBreakTimeLevel;       // active(1) or inactive(0) pause
    unsigned long m_BreakTimeLevel;   // duration of the break
    int m_MoveX;                      // Movement X image level
    bool m_Animate;
    
    //------------------------------------------------------------------
    //                 Methods
    //------------------------------------------------------------------
    void Title(unsigned long Time);
    void SelectLevel(unsigned long Time);
    void Animate(unsigned long Time);


};
#endif
