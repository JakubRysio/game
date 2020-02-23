#include "headers/enemy.h"

Enemy::Enemy() = default;

Enemy::Enemy(const char *texturePath, int x, int y, int w, int h, int animFrames, float walkSpeed) :
Figure(texturePath, x, y, w, h,animFrames,walkSpeed) {
}

Enemy::~Enemy() = default;

void Enemy::update(Player* player) {
    Figure::update();
    if(player->xPos<this->xPos){
        moveLeft();
    }
    else if(player->xPos>this->xPos){
        moveRight();
    }
    if(player->yPos<this->yPos){
        moveUp();
    }
    else if(player->yPos>this->yPos){
        moveDown();
    }
}
