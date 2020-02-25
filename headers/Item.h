#ifndef GAME_ITEM_H
#define GAME_ITEM_H

#include "Game.h"

enum itemType{
    SWORD, SHIELD
};

class Item {
public:
    Item(itemType type, Position* pos);
private:
};

#endif
