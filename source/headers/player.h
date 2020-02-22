#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include "figure.h"

class Player: public Figure {
public:
    Player();
    Player(const char *texturePath,int x , int y, int w, int h, int animFrames);
    ~Player();
    void update();
protected:
    void rotate();
};

#endif
