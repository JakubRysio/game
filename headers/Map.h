#ifndef GAME_MAP_H
#define GAME_MAP_H

#include <SDL_rect.h>
#include <SDL_render.h>
#include "Figure.h"

class Map {
public:
    Map();
    ~Map();
    void loadMap(int arr[18][32]);
    void drawMap();
private:
    SDL_Rect src{}, dest{};
    SDL_Texture *dirt, *grass, *water;
    int matrix[18][32]{};
};


#endif
