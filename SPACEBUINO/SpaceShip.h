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
    bool Protection() const;
    int ProtectionDuration() const;

    // setters methods
    void X(int ChangeX);
    void Y(int ChangeY);
    void State(bool ChangeState);
    void Position(int ChangePosition);
    void Life(int ChangeLife);
    void Protection(bool ChangeProtection);
    void ProtectionDuration(int ChangeProtectionDuration);

    void Reset();
    void Draw ();
    void Move();

  private:

    int m_X;
    int m_Y;
    bool m_State;               // destroyed (0) or not destroyed (1)
    int m_Position;             // change image spaceship for right and left
    int m_Life;                 // number of life
    bool m_Protection;          // protect shots for a while
    int m_ProtectionDuration;   // number of shots
};

#endif
