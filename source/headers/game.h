#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <SDL_render.h>
#include "figure.h"

class Game {
public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();

    bool running();
private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer* renderer;
    Figure player;
};
#endif
