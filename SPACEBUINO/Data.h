#ifndef __DataGame__
#define __DataGame__

Type LevelHomepage[5][4] =
{
  {EMPTY, CRAB, EMPTY, EMPTY},
  {EMPTY, CRAB, SQUID, EMPTY},
  {EMPTY, CRAB, SQUID, EMPTY},
  {EMPTY, CRAB, SQUID, EMPTY},
  {EMPTY, CRAB, SQUID, EMPTY}
};

Type LevelEnemy[20][8] =
{
  //----              LEVEL 1               ----//
  {CRAB, CRAB, CRAB, CRAB, CRAB, CRAB, CRAB, CRAB},
  {CRAB, CRAB, CRAB, CRAB, CRAB, CRAB, CRAB, CRAB},
  {CRAB, CRAB, CRAB, CRAB, CRAB, CRAB, CRAB, CRAB},
  {CRAB, CRAB, CRAB, CRAB, CRAB, CRAB, CRAB, CRAB},
  //----              LEVEL 2               ----//
  {SQUID, SQUID, SQUID, SQUID, SQUID, SQUID, SQUID, SQUID},
  {CRAB, CRAB, CRAB, CRAB, CRAB, CRAB, CRAB, CRAB},
  {CRAB, CRAB, CRAB, CRAB, CRAB, CRAB, CRAB, CRAB},
  {CRAB, CRAB, CRAB, CRAB, CRAB, CRAB, CRAB, CRAB},
  //----              LEVEL 3               ----//
  {SQUID, SQUID, SQUID, SQUID, SQUID, SQUID, SQUID, SQUID},
  {SQUID, SQUID, SQUID, SQUID, SQUID, SQUID, SQUID, SQUID},
  {CRAB, CRAB, CRAB, CRAB, CRAB, CRAB, CRAB, CRAB},
  {CRAB, CRAB, CRAB, CRAB, CRAB, CRAB, CRAB, CRAB},
  //----              LEVEL 4               ----//
  {SQUID, SQUID, SQUID, SQUID, SQUID, SQUID, SQUID, SQUID},
  {SQUID, SQUID, SQUID, SQUID, SQUID, SQUID, SQUID, SQUID},
  {SQUID, SQUID, SQUID, SQUID, SQUID, SQUID, SQUID, SQUID},
  {CRAB, CRAB, CRAB, CRAB, CRAB, CRAB, CRAB, CRAB},
  //----              LEVEL 5               ----//
  {SQUID, SQUID, SQUID, SQUID, SQUID, SQUID, SQUID, SQUID},
  {SQUID, SQUID, SQUID, SQUID, SQUID, SQUID, SQUID, SQUID},
  {SQUID, SQUID, SQUID, SQUID, SQUID, SQUID, SQUID, SQUID},
  {SQUID, SQUID, SQUID, SQUID, SQUID, SQUID, SQUID, SQUID}

};

int LevelEnemyPoint[20][8] =
{
  //----      LEVEL 1       ----//
  {10, 10, 10, 10, 10, 10, 10, 10},
  {10, 10, 10, 10, 10, 10, 10, 10},
  {10, 10, 10, 10, 10, 10, 10, 10},
  {10, 10, 10, 10, 10, 10, 10, 10},
  //----      LEVEL 2       ----//
  {15, 15, 15, 15, 15, 15, 15, 15},
  {10, 10, 10, 10, 10, 10, 10, 10},
  {10, 10, 10, 10, 10, 10, 10, 10},
  {10, 10, 10, 10, 10, 10, 10, 10},
  //----      LEVEL 3       ----//
  {15, 15, 15, 15, 15, 15, 15, 15},
  {15, 15, 15, 15, 15, 15, 15, 15},
  {10, 10, 10, 10, 10, 10, 10, 10},
  {10, 10, 10, 10, 10, 10, 10, 10},
  //----      LEVEL 4       ----//
  {15, 15, 15, 15, 15, 15, 15, 15},
  {15, 15, 15, 15, 15, 15, 15, 15},
  {15, 15, 15, 15, 15, 15, 15, 15},
  {10, 10, 10, 10, 10, 10, 10, 10},
  //----      LEVEL 5       ----//
  {15, 15, 15, 15, 15, 15, 15, 15},
  {15, 15, 15, 15, 15, 15, 15, 15},
  {15, 15, 15, 15, 15, 15, 15, 15},
  {15, 15, 15, 15, 15, 15, 15, 15}
};
#endif
