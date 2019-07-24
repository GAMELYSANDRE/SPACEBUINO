#ifndef __HIGHSCORE__
#define __HIGHSCORE__

class HS
{
  public:
    // constructor
    HS ();
    
    // getters Methods
    int Mode();   // Method for the main menu
    
    // setters methods
    void Mode(int ChangeMode);
    
    //display the high scores
     void Display(unsigned long Time, unsigned int Score);
 
  private:
    //------------------------------------------------------------------
    //               Variables 
    //------------------------------------------------------------------
    unsigned int m_Score[6];
    char m_Alphabet[27]=
    {
    // 1   2   3   4   5   6   7   8   9   10
      'A','B','C','D','E','F','G','H','I','J',
      'K','L','M','N','O','P','Q','R','S','T',
      'U','V','W','X','Y','Z','\0'
    };
    char m_Name[4]={'0','0','0','\0'};
    int m_LetterPosition;
    int m_LetterColumn;
    unsigned int m_NewScore;       // save the new rank
    bool m_SaveScore;              // Save activate = 1 or disable = 0
    int m_Mode;                    // Variable main menu

    
    //------------------------------------------------------------------
    //                 Methods
    //------------------------------------------------------------------  
    void Title(unsigned long Time);
    void Read();
    void ChooseLetter(unsigned int Score);
    void Compare(unsigned int Score);
};

#endif
