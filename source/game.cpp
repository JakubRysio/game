#include <SDL.h>
#include <SDL_image.h>
#include "../headers/Game.h"

SDL_Renderer* Game::renderer= nullptr;

Game::Game() {

}

Game::Game(const char *title, int x, int y, int width, int height, bool fullscreen) {
    this->w=width;
    this->h=height;
    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        //Subsystems initialised

        this->window = SDL_CreateWindow(title, x, y, width, height, flags);
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
    enemies = new Enemy*[maxE];
    for(int i=0; i<maxE; i++){
        enemies[i] = new Enemy();
        enemies[i] = nullptr;
    }
    enemies[0] = new Enemy("../../sprites/enemy.png",PositionF{1000,300},30,15, 3, 1, 500);
}

Game::~Game() {

}

void Game::handleEvents() {
    input->beginNewFrame();
    while (SDL_PollEvent(&event)) {
        SDL_GetMouseState(&mPos.x, &mPos.y);
        if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
            input->keyDownEvent(event);
        } else if (event.type == SDL_KEYUP) {
            input->keyUpEvent(event);
        }
        if (event.type == SDL_QUIT) {
            this->isRunning = false;
        }
    }
    if (input->isKeyHeld(SDL_SCANCODE_W)) {
        if (player->pos.y > 0)
            this->player->moveUp();
    } else if (input->isKeyHeld(SDL_SCANCODE_S)) {
        if (player->pos.y < (720 - 2 * player->h))
            this->player->moveDown();
    }
    if (input->isKeyHeld(SDL_SCANCODE_A)) {
        if (player->pos.x > (-player->w))
            this->player->moveLeft();
    } else if (input->isKeyHeld(SDL_SCANCODE_D)) {
        if (player->pos.x < (1280 - 2 * player->w))
            this->player->moveRight();
    }
}

void Game::update(){
    player->update();
    for(int i=0; i<(sizeof(enemies)/sizeof(*enemies)); i++) {
        if(enemies[i]!=0) enemies[i]->update(&player->pos);
    }
}

void Game::render(){
    SDL_RenderClear(renderer);
    map->drawMap();

    player->render();
    player->rotate(mPos);

    for(int i=0; i<(sizeof(enemies)/sizeof(*enemies)); i++) {
        if (enemies[i] != 0) {
            enemies[i]->render();
            enemies[i]->rotate(player->pos);
        }
    }
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

Game *game = nullptr;
int main(int argc, char *argv[]) {

    const int FPS=60;
    const int frameDelay = 1000/FPS;

    Uint32 frameStart;
    int frameTime;

    game = new Game("Game",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1280,720,false);

    while (game->running()) {

        frameStart=SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks()-frameStart;

        if(frameDelay > frameTime){
            SDL_Delay(frameDelay-frameTime);
        }
    }

    game->clean();
    return 0;
}


