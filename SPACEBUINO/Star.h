#ifndef __Star__
#define __Star__

class Star
{
  public:
  
    // constructors
    Star (int X, int Y,int Speed);
    
    void Display();
    void Move();
    
  private:
  
    int m_X;            // X coordinate
    int m_Y;            // Y coordinate
    int m_Speed;        // speed star
};


#endif
