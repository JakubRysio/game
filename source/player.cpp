#include "../headers/Player.h"

Player:: Player() :
Figure("../../sprites/player.png", PositionF{200,170},30,15, 3, 3,1000) {
}

Player::~Player() = default;
