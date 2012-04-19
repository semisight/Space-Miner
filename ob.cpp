#include "ob.h"

void ob::mov() {
	//Trig calculations to update the object's position
	x += cos(rot) * sp;
	y += sin(rot) * sp;

	//Keep our object within bounds
    if(x >= S_WID) x = 0;
    if(x < 0) x = S_WID-1;
    if(y >= S_HGT) y = 0;
    if(y < 0) y = S_HGT-1;
}

bool ob::coll_detect(const ob &b) const {
    return (hypot(x-b.getX(), y-b.getY()) < (rad + b.getRad())) && !dead;
}

double ob::getX() const {
    return x;
}

double ob::getY() const {
    return y;
}

double ob::getRot() const {
    return rot;
}

double ob::getRad() const {
    return rad;
}

QColor ob::getCol() const {
    return col;
}

bool ob::getDead() const {
    return dead;
}

void ob::kill() {
    dead = true;
}

bool ob::isDead(ob *b) {
     return b->getDead();
}
