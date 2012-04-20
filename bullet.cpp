#include "bullet.h"

bullet::bullet(double nx, double ny, double d) : ob(nx, ny, d, 4, 2, QColor(0,0,0)), life(200) {
}

void bullet::mov() {
    if(life > 0)
        life--;
    else
        dead = true;

    ob::mov();
}
