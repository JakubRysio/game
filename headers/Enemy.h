#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H

#include "Figure.h"
#include "Player.h"

class Enemy: public Figure{
public:
    Enemy();
    Enemy(const char *texturePath,PositionF pos, int w, int h, int animFrames, float walkSpeed, int hp);
    ~Enemy();
    void update(Position* player);
};

#endif
