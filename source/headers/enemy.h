#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H

#include "figure.h"
#include "player.h"

class Enemy: public Figure{
public:
    Enemy();
    Enemy(const char *texturePath,int x , int y, int w, int h, int animFrames, float walkSpeed);
    ~Enemy();
    void update(Player* player);
};

#endif
