#include <SDL_image.h>
#include "headers/figure.h"
#include "headers/game.h"
#include <cmath>


Figure::Figure() = default;

Figure::Figure( const char *texturePath,int x, int y, int w, int h, int animFrames, float walkSpeed) {
    texture=Game::loadTexture(texturePath);

    this->animFrame=animFrames;
    this->currentFrame=0;

    this->xPos=x;
    this->yPos=y;

    this->w=w;
    this->h=h;

    this->angle=0;

    this->srcR.w=w;
    this->srcR.h=h;
    this->srcR.x=0;
    this->srcR.y=0;

    this->desR.w=this->srcR.w*3;
    this->desR.h=this->srcR.h*3;

    this->walkSpeed=walkSpeed;
}

Figure::~Figure() = default; //usuwanie obiektu z jakiegos kontenera na widoczne obiekty itd?

void Figure::update() {

    this->desR.x= xPos;
    this->desR.y= yPos;
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

void Figure::rotate(int x, int y) {
    double xPosA=this->xPos+(this->desR.w/2);
    double yPosA=this->yPos+(this->desR.h/2);
    double vecX = abs(xPosA - x);
    double vecY = abs(yPosA - y);

    double absVec = sqrt((vecX * vecX) + (vecY * vecY));

    double arcCos = (yPosA * vecY) / (yPosA * absVec);
    double angle90= acos(arcCos) * 180 / 3.14;
    if(xPosA<=x&&yPosA>=y) {
        angle = angle90;
    }else if(xPosA<=x&&yPosA<=y) {
        angle = 180 - angle90;
    }else if(xPosA>=x&&yPosA<=y) {
        angle = angle90 + 180;
    }else if(xPosA>=x&&yPosA>=y) {
        angle = 360 - angle90;
    }
}

void Figure::moveUp() {
    yPos-=walkSpeed;
    this->animation();
}

void Figure::moveDown() {
    yPos+=walkSpeed;
    this->animation();
}

void Figure::moveLeft() {
    xPos-=walkSpeed;
    this->animation();
}

void Figure::moveRight() {
    xPos+=walkSpeed;
    this->animation();
}

