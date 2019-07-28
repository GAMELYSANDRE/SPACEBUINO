#ifndef __Enemy__
#define __Enemy__
#include <stdint.h>

enum Type
{
  EMPTY = 0,
  CRAB = 1,
  SQUID = 2,
  OCTO = 3,
  LAZE,
  EXPLOSE
};

class Enemy
{

  public:

    // constructors
    Enemy ();
    Enemy (int X, int Y, Type TypeEnemy, int Point);

    // getters methods
    int X() const;
    int Y() const;
    bool State() const;
    bool Direction() const;
    int Point() const;
    int Angry() const;
    Type TypeEnemy() const;

    // setters methods
    void X(int ChangeX);
    void Y(int ChangeY);
    void State(bool ChangeState);
    void Direction(bool ChangeDirection);
    void Point(int ChangePoint);
    void Angry(bool ChangeAngry);

    // movement function
    void Move (int X, int Y);

    // drawing function
    void Draw () const;

    // function changes the type of enemy
    void Change (Type TypeEnemy);

  private:

    int m_X;            // X coordinate
    int m_Y;            // Y coordinate
    bool m_State;       // dead (0) or alive (1)
    int m_Point;        // point value
    bool m_Direction;   // Left (0) or Right (1)
    bool m_Angry;       // Quiet (0) or Angry (1)
    Type m_TypeEnemy;   // Enemy type according to the list Type


};

#endif
