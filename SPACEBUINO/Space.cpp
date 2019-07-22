#include "Space.h"
#include <Gamebuino-Meta.h>


//-------------------------------------
//              CONSTRUCTOR            
//-------------------------------------
Space::Space()
{
  int X=0;
  int Y=0;
  int Speed=0;
  for (int i = 0 ; i < 16 ; i++)
  {
    X = random(80,140);
    Y = random(0,60);
    Speed = random(0,3);
    NumberStar[i] = new Star(X,Y,Speed);
  }
}

//-------------------------------------
//        DRAWING SPACE METHOD             
//-------------------------------------

void Space::Display()
{
  for (int i = 0 ; i < 16 ; i++)
  {
    NumberStar[i]->Move();
    NumberStar[i]->Display();
  }
}
