#include <SDL.h>
#include <SDL_image.h>
#include "headers/game.h"
#include "headers/figure.h"

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
    player=Figure(renderer,"../../media/sprites/mChar.png",200,170,30,15, 3);
}


void Game::handleEvents(){
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        SDL_GetMouseState(&player.mX, &player.mY);
        switch (event.type) {
            case SDL_QUIT:
                this->isRunning = false;
                break;
        }
    }
}

void Game::update(){
    player.update();
}

void Game::render(){
    SDL_RenderClear(renderer);
//there I can add things to render;
    player.render();
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
