#ifndef GAME_MAP_H
#define GAME_MAP_H

#include <SDL_rect.h>
#include <SDL_render.h>
#include "Figure.h"

class Map {
public:
    Map();
    ~Map();
    void loadMap(int arr[80][45]);
    void drawMap();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

private:
    SDL_Rect src{}, dest{};
    SDL_Texture *dirt, *grass, *water;
    int matrix[80][45]{};
    PositionF moveMap;
    float mSpeed;

    void loadMap();
};


#endif
