#include "../headers/HPbar.h"

HPbar::HPbar() {

}

HPbar::HPbar(int value) {
    hp=value;
}

bool HPbar::isAlive() {
    return hp>0;
}
