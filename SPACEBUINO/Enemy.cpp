#include "Enemy.h"
#include "EnemyImage.h"
#include <Gamebuino-Meta.h>

//----------------------------------------------------------------------
//                         CONSTRUCTOR
//----------------------------------------------------------------------
Enemy::Enemy () :
  m_X(0),
  m_Y(0),
  m_State(1),
  m_Resistance(1),
  m_TypeEnemy(SQUID),
  m_Direction(0),
  m_Point(0),
  m_Angry(0)
{


}

Enemy::Enemy (int X, int Y, Type TypeEnemy, int Point) :
  m_X(0),
  m_Y(0),
  m_State(1),
  m_Resistance(1),
  m_TypeEnemy(SQUID),
  m_Direction(0),
  m_Point(0),
  m_Angry(0)
{
  m_X = X;
  m_Y = Y;
  m_TypeEnemy = TypeEnemy;
  m_Point = Point;
  m_TypeEnemyHit = TypeEnemy;
}
//----------------------------------------------------------------------
//                           DESTRUCTOR
//----------------------------------------------------------------------


//----------------------------------------------------------------------
//                        Getters Methods
//----------------------------------------------------------------------
int Enemy::X() const
{
  return (m_X);
}
int Enemy::Y() const
{
  return (m_Y);
}
bool Enemy::State() const
{
  return (m_State);
}
int Enemy::Resistance() const
{
  return (m_Resistance);
}
bool Enemy::Direction() const
{
  return (m_Direction);
}
int Enemy::Point() const
{
  return (m_Point);
}
int Enemy::Angry() const
{
  return (m_Angry);
}
Type Enemy::TypeEnemy() const
{
  return (m_TypeEnemy);
}
//----------------------------------------------------------------------
//                          Setters Methods
//----------------------------------------------------------------------
void Enemy::X(int ChangeX)
{
  m_X = ChangeX;
}
void Enemy::Y(int ChangeY)
{
  m_Y = ChangeY;
}
void Enemy::State(bool ChangeState)
{
  m_State = ChangeState;
}
void Enemy::Resistance(int ChangeResistance)
{
  m_Resistance = ChangeResistance;
}
void Enemy::Direction(bool ChangeDirection)
{
  m_Direction = ChangeDirection;
}
void Enemy::Point(int ChangePoint)
{
  m_Point = ChangePoint;
}
void Enemy::Angry(bool ChangeAngry)
{
  m_Angry = ChangeAngry;
}
void Enemy::Change (Type TypeEnemy)
{
  m_TypeEnemy = TypeEnemy;
}
void Enemy::HitChange (Type ChangeType)
{
  m_TypeEnemyHit = ChangeType;
}
//----------------------------------------------------------------------
//                          Method movement 
//----------------------------------------------------------------------
void Enemy::Move (int X, int Y)
{
  m_X = X;
  m_Y = Y;
}
//----------------------------------------------------------------------
//                          Method Drawing 
//----------------------------------------------------------------------
void Enemy::Draw()
{
  // not angry enemy
  if (m_State == 1 and m_Angry == 0) // check dead (0) or alive (1) and not angry (0)
  {
    switch (m_TypeEnemy)
    {
      case (CRAB):
        gb.display.drawImage(m_X, m_Y, IMG_CRAB);
        break;
      case (SQUID):
        gb.display.drawImage(m_X, m_Y, IMG_SQUID);
        break;
      case (OCTO):
        gb.display.drawImage(m_X, m_Y, IMG_OCTOPUS);
        break;
      case (LAZE):
        gb.display.drawImage(m_X, m_Y, IMG_LAZE);
        break;
      case (EXPLOSE):
        gb.display.drawImage(m_X, m_Y, IMG_EXPLOSE);
        gb.sound.play("explosion_1.wav");
        break;
      case (HIT):
        switch (m_TypeEnemyHit)
        {
          case (CRAB):
            break;
          case (SQUID):
            gb.display.drawImage(m_X, m_Y, IMG_SQUID_HIT);
            break;
          case (OCTO):
            gb.display.drawImage(m_X, m_Y, IMG_OCTO_HIT);
            break;
          case (LAZE):
            gb.display.drawImage(m_X, m_Y, IMG_LAZE_HIT);
            break;     
        }
        gb.sound.play("Beep1.wav");
        break;
    }
  }
  // Angry enemy
  if (m_State == 1 and m_Angry == 1) // check dead (0) or alive (1) and angry (1)
  {
    switch (m_TypeEnemy)
    {
      case (CRAB):
        gb.display.drawImage(m_X, m_Y, IMG_CRAB_RED);
        break;
      case (SQUID):
        gb.display.drawImage(m_X, m_Y, IMG_SQUID_RED);
        break;
      case (OCTO):
        gb.display.drawImage(m_X, m_Y, IMG_OCTO_RED);
        break;
      case (LAZE):
        gb.display.drawImage(m_X, m_Y, IMG_LAZE_RED);
        break;
      case (EXPLOSE):
        gb.display.drawImage(m_X, m_Y, IMG_EXPLOSE);
        gb.sound.play("explosion_1.wav");
        break;
      case (HIT):
        switch (m_TypeEnemyHit)
        {
          case (CRAB):
            break;
          case (SQUID):
            gb.display.drawImage(m_X, m_Y, IMG_SQUID_HIT);
            break;
          case (OCTO):
            gb.display.drawImage(m_X, m_Y, IMG_OCTO_HIT);
            break;
          case (LAZE):
            gb.display.drawImage(m_X, m_Y, IMG_LAZE_HIT);
            break;       
        }
        gb.sound.play("Beep1.wav");
        break;
    }
  }
}
