#ifndef __SPACE__
#define __SPACE__

#include "Star.h"

class Space
{
  public:
    // constructors
    Space ();
    void Display();

  private:
    Star *NumberStar[16]; // pointer on a table of star

};




#endif
