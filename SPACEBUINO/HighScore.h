#ifndef __HIGHSCORE__
#define __HIGHSCORE__

#include "Space.h"

class HS
{
  public:
    // constructor
    HS ();
    // destructor
    ~HS();

    // getters Methods
    int Mode();   

    // setters methods
    void Mode(int ChangeMode);

    //display the high scores
    void Display(unsigned long Time, unsigned int Score);

  private:
    //------------------------------------------------------------------
    //               Variables
    //------------------------------------------------------------------
    unsigned int m_Score[5];
    bool m_SDcard;               // Read SD card= 1 or Stop Read = 0
    char m_Alphabet[27] =
    {
      // 1   2   3   4   5   6   7   8   9   10
      'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
      'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
      'U', 'V', 'W', 'X', 'Y', 'Z', '\0'
    };
    char m_Name[4] = {'0', '0', '0', '\0'};
    int m_LetterPosition;
    int m_LetterColumn;
    unsigned int m_NewScore;      // save the new rank
    bool m_SaveScore;             // Save activate = 1 or disable = 0
    int m_Mode;                   // Variable main menu
    Space *m_Space;               // pointer on the space
    bool m_SwitchHelp;            // swap help

    //------------------------------------------------------------------
    //        variable time management for the flashing Image
    //------------------------------------------------------------------

    unsigned long m_CurrentTime;      // current time
    bool m_StateBreakTimeImage;       // active(1) or inactive(0) pause
    unsigned long m_BreakTimeImage;   // duration of the break
    int m_NumberImage;                // compteur d'image

    //------------------------------------------------------------------
    //                 Methods
    //------------------------------------------------------------------
    void Title(unsigned long Time);
    void Read();
    void ChooseLetter(unsigned int Score);
    void Compare(unsigned int Score);
    void Help(unsigned long Time);
};

#endif
