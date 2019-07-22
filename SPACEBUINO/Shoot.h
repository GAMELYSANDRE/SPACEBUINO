#ifndef __Shoot__
#define __Shoot__

enum Direction
{
  UP = 1,
  DOWN = 0
};

class Shoot
{
  public:

    // constructors
    Shoot ();
    Shoot (int X, int Y);

    // getters methods
    int X() const;
    int Y() const;
    // setters methods
    void Speed(int ChangeSpeed);

    void Draw ();
    void Position (int X, int Y);
    bool State ();
    void State (bool StateShoot);
    void Move(Direction DirectionShooting );


  private:

    int m_X;        // X coordinate
    int m_Y;        // Y coordinate
    int m_Color;    // Color
    int m_Speed;    // Vitesse
    int m_State;    // Erase (0) Display (1)
};

#endif
