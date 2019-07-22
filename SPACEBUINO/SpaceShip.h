#ifndef __SpaceShip__
#define __SpaceShip__
#include "Shoot.h"

class SpaceShip
{
  public:

    // constructors
    SpaceShip ();
    SpaceShip (int X, int Y);

    // getters methods
    int X() const;
    int Y() const;
    bool State() const;
    int Life() const;

    // setters methods
    void X(int ChangeX);
    void Y(int ChangeY);
    void State(bool ChangeState);
    void Position(int ChangePosition);
    void Life(int ChangeLife);

    void Draw ();
    void Move();

  private:

    int m_X;
    int m_Y;
    bool m_State;
    int m_Position;
    int m_Life;         // number of life
};

#endif
