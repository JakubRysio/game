#include <cmath>
#include "../headers/Figure.h"
#include "../headers/Game.h"

Figure::Figure() = default;

Figure::Figure( const char *texturePath, PositionF pos, int w, int h, int animFrames, float walkSpeed, int HPval) {
    texture=Game::loadTexture(texturePath);

    this->pos.x=pos.x;
    this->pos.y=pos.y;

    this->animFrame=animFrames;
    this->currentFrame=0;

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

    //hp=HPbar(HPval);
}

Figure::~Figure() = default; //usuwanie obiektu z jakiegos kontenera na widoczne obiekty itd?

void Figure::update() {

    this->desR.x= this->pos.x;
    this->desR.y= this->pos.y;
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

void Figure::rotate(Position otPos) {
    PositionF posA;
    PositionF vec;
    posA.x=this->pos.x+(this->desR.w/2);
    posA.y=this->pos.y+(this->desR.h/2);
    vec.x = abs(posA.x - otPos.x);
    vec.y = abs(posA.y - otPos.y);

    float absVec = sqrt((vec.x * vec.x) + (vec.y * vec.y));

    float arcCos = (posA.y * vec.y) / (posA.y * absVec);

    float angle90= acos(arcCos) * 180 / 3.14;
    if(posA.x <= otPos.x && posA.y >= otPos.y) {
        angle = angle90;
    }else if(posA.x <= otPos.x && posA.y <= otPos.y) {
        angle = 180 - angle90;
    }else if(posA.x >= otPos.x && posA.y <= otPos.y) {
        angle = angle90 + 180;
    }else if(posA.x >= otPos.x && posA.y >= otPos.y) {
        angle = 360 - angle90;
    }
}

void Figure::moveUp() {
    this->pos.y-=walkSpeed;
    this->animation();
}

void Figure::moveDown() {
    this->pos.y+=walkSpeed;
    this->animation();
}

void Figure::moveLeft() {
    this->pos.x-=walkSpeed;
    this->animation();
}

void Figure::moveRight() {
    this->pos.x+=walkSpeed;
    this->animation();
}


