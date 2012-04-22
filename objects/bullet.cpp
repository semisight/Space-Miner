#include "bullet.h"

bullet::bullet(double nx, double ny, double d) : ob(nx, ny, d, 4, 2, QColor(0,0,0)) {
    points = 10;
}

void bullet::mov() {
    rad = 2 + points/10;
    ob::mov();
}
