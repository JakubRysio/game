#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H

#include "Figure.h"
#include "Player.h"

class Enemy: public Figure{
public:
    Enemy();
    Enemy(const char *texturePath,float x, float y, int w, int h, int animFrames, float walkSpeed);
    ~Enemy();
    void update(Position<float>* player);
};

#endif
