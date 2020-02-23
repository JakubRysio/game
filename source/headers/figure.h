#ifndef GAME_FIGURE_H
#define GAME_FIGURE_H

#include <SDL_render.h>
#include <string>

class Figure {
public:
    Figure();
    Figure(const char *texturePath,int x , int y, int w, int h, int animFrames, float walkSpeed);
    ~Figure();

    void update();
    void render();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void rotate(int x, int y);

    float angle;
    float xPos, yPos;
protected:
    void animation();

    SDL_Rect srcR{}, desR{};
    SDL_Texture* texture;
    int w,h;
    double currentFrame;
    int animFrame;

    float walkSpeed;
};
#endif
