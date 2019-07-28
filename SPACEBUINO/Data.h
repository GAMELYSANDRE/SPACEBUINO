#ifndef __DataGame__
#define __DataGame__

#define CRAB_PT  10
#define SQUID_PT  20
#define OCTO_PT  40
#define LAZE_PT  60


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
  {CRAB_PT, CRAB_PT, CRAB_PT, CRAB_PT, CRAB_PT, CRAB_PT, CRAB_PT, CRAB_PT},
  {CRAB_PT, CRAB_PT, CRAB_PT, CRAB_PT, CRAB_PT, CRAB_PT, CRAB_PT, CRAB_PT},
  {CRAB_PT, CRAB_PT, CRAB_PT, CRAB_PT, CRAB_PT, CRAB_PT, CRAB_PT, CRAB_PT},
  {CRAB_PT, CRAB_PT, CRAB_PT, CRAB_PT, CRAB_PT, CRAB_PT, CRAB_PT, CRAB_PT},
  //----      LEVEL 2       ----//
  {15, 15, 15, 15, 15, 15, 15, 15},
  {10, 10, 10, 10, 10, 10, 10, 10},
  {CRAB_PT, CRAB_PT, CRAB_PT, CRAB_PT, CRAB_PT, CRAB_PT, CRAB_PT, CRAB_PT},
  {CRAB_PT, CRAB_PT, CRAB_PT, CRAB_PT, CRAB_PT, CRAB_PT, CRAB_PT, CRAB_PT},
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
