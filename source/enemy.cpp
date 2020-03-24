#include "../headers/Enemy.h"

Enemy::Enemy() = default;

Enemy::Enemy(const char *texturePath, PositionF pos, int w, int h, int animFrames, float walkSpeed, int hp) :
Figure(texturePath, pos, w, h, animFrames, walkSpeed, hp) {

}



Enemy::~Enemy() = default;


void Enemy::update(Position *player) {
    Figure::update();
    if(player->x<this->pos.x){
        moveLeft();
    }
    else if(player->x>this->pos.x){
        moveRight();
    }
    if(player->y<this->pos.y){
        moveUp();
    }
    else if(player->y>this->pos.y){
        moveDown();
    }
}
