#ifndef __Credit__
#define __Credit__

#include "Space.h"

class Credit
{

  public:

    // constructors
    Credit ();
    ~Credit ();

    // getters methods
    int Mode();

    // setters methods
    void Mode(int ChangeMode);

    // methods
    void Display();

  private:
    Space *m_Space;               // pointer on the space
    int m_Mode;
};

#endif
