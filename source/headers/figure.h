#ifndef GAME_FIGURE_H
#define GAME_FIGURE_H

#include <SDL_render.h>
#include <string>

class Figure {
public:
    Figure();
    Figure(const char *texturePath,int x , int y, int w, int h, int animFrames);
    ~Figure();

    void update();
    void render();
    int angle;
    int mX, mY;
protected:
    void animation();
    SDL_Rect srcR, desR;
    SDL_Texture* texture;
    int xPos, yPos, w,h;
    double currentFrame;
    int animFrame;
    void rotate();
};
#endif
