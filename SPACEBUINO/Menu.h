#ifndef __Menu__
#define __Menu__
#include "Space.h"

class Menu
{

  public:
    // constructor
    Menu (const char *MenuTextList[], int MenuSize);
    // Destructor
    ~Menu();
    // getters Methods
    int Position() const;
    int Mode() const;   // Method for the main menu

    // setters methods
    void Mode(int ChangeMode);



    void DisplayMenu (unsigned long Time);

  private:
    char** m_MenuTextList;        // table 2 dimensions to save strings of characters
    int m_MenuSize;               // size menu
    int* m_MenuTextSize;          // size of the menu texts
    int m_MenuPosition;           // Position in the menu
    int m_MenuPositionPressed;    // Save the position in the menu when pressing the A button
    Space *m_Space;               // pointer on the space
    int m_Mode;                   // Variable main menu

    //------------------------------------------------------------------
    //        variable time management for the flashing Text
    //------------------------------------------------------------------

    unsigned long m_CurrentTime;      // current time
    bool m_StateBreakTime;            // active(1) or inactive(0) pause
    unsigned long m_BreakTimeON;      // duration of the break ON
    unsigned long m_BreakTimeOFF;     // duration of the break OFF
    int m_DelayFlashingText;          // duration of the flashing texte

    //------------------------------------------------------------------
    //        variable time management for the flashing Image
    //------------------------------------------------------------------

    bool m_StateBreakTimeImage;       // active(1) or inactive(0) pause
    unsigned long m_BreakTimeImage;   // duration of the break
    int m_NumberImage;                // compteur d'image


    void DisplayText (int RowText, bool ActivFlashing);
    void DisplayImage (unsigned long Time);
    void MoveText ();
};


#endif
