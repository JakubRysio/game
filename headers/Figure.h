#ifndef GAME_FIGURE_H
#define GAME_FIGURE_H

#include <SDL_render.h>
#include <string>
struct Position{
    int x;
    int y;
};
struct PositionF{
    float x;
    float y;
};

class Figure {
public:
    Figure();
    Figure(const char *texturePath, PositionF f, int w, int h, int animFrames, float walkSpeed);
    ~Figure();

    void update();
    void render();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void rotate(Position otPos);

    float angle;
    Position pos;
    int w,h;
    float walkSpeed;
protected:
    void animation();

    SDL_Rect srcR{}, desR{};
    SDL_Texture* texture;
    double currentFrame;
    int animFrame;

};
#endif
