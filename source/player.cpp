#include <cmath>
#include "headers/player.h"

Player:: Player() {

}

Player::Player(const char *texturePath, int x, int y, int w, int h, int animFrames)
: Figure(texturePath, x, y, w, h, animFrames) {
}

Player::~Player() {

}

void Player::rotate() {
    double xPosA=this->xPos+(this->desR.w/2);
    double yPosA=this->yPos+(this->desR.h/2);
    double vecX = abs(xPosA - this->mX);
    double vecY = abs(yPosA - this->mY);

    double absVec = sqrt((vecX * vecX) + (vecY * vecY));

    double arcCos = (yPosA * vecY) / (yPosA * absVec);
    double angle90= acos(arcCos) * 180 / 3.14;
    if(xPosA<=this->mX&&yPosA>=mY) {
        angle = angle90;
    }else if(xPosA<=this->mX&&yPosA<=mY) {
        angle = 180 - angle90;
    }else if(xPosA>=this->mX&&yPosA<=mY) {
        angle = angle90 + 180;
    }else if(xPosA>=this->mX&&yPosA>=mY) {
        angle = 360 - angle90;
    }
}

void Player::update() {
    this->animation();

    xPos++;
    yPos++;
    this->desR.x= xPos;
    this->desR.y= yPos;

    rotate();
}
