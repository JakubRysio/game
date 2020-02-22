#include <SDL_image.h>
#include "headers/figure.h"
#include "headers/game.h"
#include <cmath>


Figure::Figure() {
}

Figure::Figure( const char *texturePath,int x, int y, int w, int h, int animFrames) {
    texture=Game::loadTexture(texturePath);

    this->animFrame=animFrames;
    this->currentFrame=0;

    this->mX=0;
    this->mY=0;

    this->xPos=x;
    this->yPos=y;

    this->w=w;
    this->h=h;

    this->angle=0;

    this->srcR.w=w;
    this->srcR.h=h;
    this->srcR.x=0;
    this->srcR.y=0;

    desR.w=srcR.w*3;
    desR.h=srcR.h*3;
}

Figure::~Figure() {
    //usuwanie obiektu z jakiegos kontenera na widoczne obiekty itd?
}

void Figure::update() {
    this->animation();

    this->desR.x= xPos;
    this->desR.y= yPos;

    rotate();
}

void Figure::render() {
    SDL_RenderCopyEx(Game::renderer,texture, &srcR, &desR, angle,NULL, SDL_FLIP_NONE);
}

void Figure::animation() {
    currentFrame=currentFrame+0.09;
    if(currentFrame>=animFrame){
        this->currentFrame=0;
    }
    this->srcR.x=30*floor(currentFrame);
}

void Figure::rotate() {

}

