#ifndef __Capsule__
#define __Capsule__

enum CapsuleColor
{
  CAPSULE_GREEN = 0,
  CAPSULE_BLUE = 1
};


class Capsule
{
  public:

    // constructor
    Capsule (int X, int Y );
    // Destructor
    ~Capsule();

    // getters methods
    int X() const;
    int Y() const;
    bool State() const;
    CapsuleColor Color() const;


    // setters methods
    void X(int ChangeX);
    void Y(int ChangeY);
    void State(bool ChangeState);
    void Color(CapsuleColor ChangeColor);

    // Methods
    void Display();
    void Move(int X, int Y);


  private:

    int m_X;                // X coordinate
    int m_Y;                // Y coordinate
    bool m_State;           // Active (0) or Inactive (1)
    CapsuleColor m_Color;   // Capsule color


};
#endif
