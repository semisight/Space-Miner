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

void ob::draw() {
    //mvaddch((int)y, (int)x, ch);
}

double ob::getX() {
    return x;
}

double ob::getY() {
    return y;
}

double ob::getRot() {
    return rot;
}

double ob::getRad() {
    return rad;
}
