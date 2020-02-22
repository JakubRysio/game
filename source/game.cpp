#include <SDL.h>
#include <SDL_image.h>
#include "headers/game.h"

SDL_Renderer* Game::renderer= nullptr;

Game::Game() {}
Game::~Game() {}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {

    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        //Subsystems initialised

        this->window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window) {
        //Window created
        }

        this->renderer = SDL_CreateRenderer(this->window, -1, 0);
        if (this->renderer) {
            SDL_SetRenderDrawColor(renderer, 255,255,255,255);
//Renderer created
        }

        this->isRunning = true;
    }
    player = new Player("../../media/sprites/mChar.png",200,170,30,15, 3);
    map = new Map();
}

void Game::handleEvents(){
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        SDL_GetMouseState(&player->mX, &player->mY);
        switch (event.type) {
            case SDL_QUIT:
                this->isRunning = false;
                break;
        }
    }
}

void Game::update(){
    player->update();
}

void Game::render(){
    SDL_RenderClear(renderer);
    map->drawMap();
    player->render();
    SDL_RenderPresent(renderer);
}

void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    //game cleaned
}

bool Game::running() {
    return this->isRunning;
}

SDL_Texture *Game::loadTexture(const char *filename) {
    SDL_Surface* tmpSurface = IMG_Load(filename);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    return tex;
}

void Game::simpleDraw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest) {
    SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}
