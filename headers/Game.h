#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <SDL_render.h>
#include "Figure.h"
#include "Player.h"
#include "Map.h"
#include "Input.h"
#include "Enemy.h"

class Game {
public:
    Game();
    ~Game();

    void init(const char* title, int x, int y, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();
    bool running();

    static SDL_Renderer* renderer;
    static SDL_Texture* loadTexture(const char* filename);
    static void simpleDraw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);

    Position mPos;
private:
    SDL_Event event;
    bool isRunning;
    SDL_Window *window;
    Player* player;
    Map* map;
    Input* input;
    Enemy* enemy;
};
#endif
