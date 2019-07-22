#ifndef __HIGHSCORE__
#define __HIGHSCORE__

class HS
{
  public:
    // constructor
    HS ();
    
    //display the high scores
     void Display(unsigned long Time);
 
  private:
    //----------------------------------------
    //               Variables 
    //----------------------------------------
    int m_Score[5];
    char m_Alphabet[27]=
    {
    // 1   2   3   4   5   6   7   8   9   10
      'A','B','C','D','E','F','G','H','I','J',
      'K','L','M','N','O','P','Q','R','S','T',
      'U','V','W','X','Y','Z','\0'
    };
    char m_Name[4]={'0','0','0','\0'};
    //char m_fox[4] = {'_','_','_','\0'};
    int m_LetterPosition;
    int m_LetterColumn;

    
    //----------------------------------------
    //                 Methods
    //----------------------------------------  
    void Title(unsigned long Time);
    void Read();
    void ChooseLetter();
};

#endif
