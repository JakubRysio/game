#include "../headers/Enemy.h"
#include "../headers/Game.h"


Enemy::Enemy() = default;

Enemy::Enemy(const char *texturePath, float x, float y, int w, int h, int animFrames, float walkSpeed) :
Figure(texturePath, x, y, w, h, animFrames, walkSpeed) {

}



Enemy::~Enemy() = default;


void Enemy::update(Position<float> *player) {
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
