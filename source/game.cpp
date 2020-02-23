#include <SDL.h>
#include <SDL_image.h>
#include "headers/game.h"

SDL_Renderer* Game::renderer= nullptr;

Game::Game() = default;
Game::~Game() = default;

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

        Game::renderer = SDL_CreateRenderer(this->window, -1, 0);
        if (Game::renderer) {
            SDL_SetRenderDrawColor(renderer, 255,255,255,255);
//Renderer created
        }

        this->isRunning = true;
    }
    input = new Input();
    player = new Player();
    map = new Map();
    enemy = new Enemy("../../media/sprites/enemy.png",1000,300,30,15, 3, 1);
}

void Game::handleEvents() {
    input->beginNewFrame();
    while (SDL_PollEvent(&event)) {
        SDL_GetMouseState(&mX, &mY);
        if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
            input->keyDownEvent(event);
        } else if (event.type == SDL_KEYUP) {
            input->keyUpEvent(event);
        }
        if (event.type == SDL_QUIT) {
            this->isRunning = false;
        }
    }
    if(input->isKeyHeld(SDL_SCANCODE_W)){
        this->player->moveUp();
    }else if(input->isKeyHeld(SDL_SCANCODE_S)){
        this->player->moveDown();
    }
    if(input->isKeyHeld(SDL_SCANCODE_A)){
        this->player->moveLeft();
    }else if(input->isKeyHeld(SDL_SCANCODE_D)){
        this->player->moveRight();
    }
}

void Game::update(){
    player->update();
    enemy->update(player);
}

void Game::render(){
    SDL_RenderClear(renderer);
    map->drawMap();

    player->render();
    player->rotate(mX,mY);

    enemy->render();
    enemy->rotate(player->xPos,player->yPos);

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
