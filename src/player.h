#ifndef PLAYER_H
#define PLAYER_H

#include "map.h"
#include "object.h"

class Player : public Object {
  Player(int x, int y) : Object(x, y) {}
};

#endif // PLAYER_H