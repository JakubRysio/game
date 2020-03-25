#ifndef GAME_HPBAR_H
#define GAME_HPBAR_H


class HPbar {
public:
    HPbar();
    HPbar(int value);
    bool isAlive();
private:
    int hp;
};


#endif //GAME_HPBAR_H
