#ifndef GAME_BARHP_H
#define GAME_BARHP_H


#include "Figure.h"

class barHP {
public:
    barHP();
    //barHP(Position* position, int value);
    ~barHP();
    bool isAlive();
    void update();
    void render();
    void follow();
    int w,h;

protected:
    int hpVal;
//    Position* followed;
    SDL_Rect srcR{}, desR{};
};


#endif //GAME_BARHP_H
