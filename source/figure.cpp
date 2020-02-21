#include <SDL_image.h>
#include "headers/figure.h"
#include <cmath>


Figure::Figure() {
}

Figure::Figure(SDL_Renderer *rendering, const char *texturePath,int x, int y, int w, int h, int animFrames) {
    this->renderer=rendering;
    SDL_Surface* tmpSurface =IMG_Load(texturePath);
    texture=SDL_CreateTextureFromSurface(rendering,tmpSurface);
    SDL_FreeSurface(tmpSurface);

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

    desR.w=srcR.w*3; ////!!!!!
    desR.h=srcR.h*3;    ////!!!!!
}

Figure::~Figure() {
    //usuwanie obiektu z jakiegos kontenera na widoczne obiekty itd?
}

void Figure::update() {
    this->animation();

    xPos++;
    yPos++;
    this->desR.x= xPos;
    this->desR.y= yPos;

    this->rotate();

}

void Figure::render() {
    SDL_RenderCopyEx(renderer,texture, &srcR, &desR, angle,NULL, SDL_FLIP_NONE);
}

void Figure::animation() {
    currentFrame=currentFrame+0.09;
    if(currentFrame>=animFrame){
        this->currentFrame=0;
    }
    this->srcR.x=30*floor(currentFrame);
}

void Figure::rotate() {
    double xPosA=this->xPos+(this->desR.w/2);
    double yPosA=this->yPos+(this->desR.h/2);
    double vecX = abs(xPosA - this->mX);
    double vecY = abs(yPosA - this->mY);

    double absVec = sqrt((vecX * vecX) + (vecY * vecY));

    double arcCos = (yPosA * vecY) / (yPosA * absVec);
    double tmp=acos(arcCos)*180/3.14;
    if(xPosA<=this->mX&&yPosA>=mY) {
        angle = tmp;
    }else if(xPosA<=this->mX&&yPosA<=mY) {
        angle = 180-tmp;
    }else if(xPosA>=this->mX&&yPosA<=mY) {
        angle = tmp+180;
    }else if(xPosA>=this->mX&&yPosA>=mY) {
        angle = 360-tmp;
    }
}





