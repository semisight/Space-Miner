#include "ob.h"
using namespace std;

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

void ob::draw(QPainter &ctx) {
    ctx.setBrush(col);
    ctx.drawEllipse(QPointF(x, y), rad, rad);
}

bool ob::coll_detect(ob *b) {
    return (hypot(x-b->getX(), y-b->getY()) < (rad + b->getRad())) && !dead;
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

double ob::getSp() const {
    return sp;
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

int ob::getPoints() const {
    return points;
}

void ob::hit(ob *b) {
    //TODO: realistic hits
    //momentum: vnew = (m1*v1 + m2*v2) / (m1+m2)
    double v1x = cos(rot) * sp;
    double v1y = sin(rot) * sp;
    double v2x = cos(b->getRot()) * b->getSp();
    double v2y = cos(b->getRot()) * b->getSp();

    double vnx = ((v1x*points) + (v2x*b->getPoints()))/(points+b->getPoints());
    double vny = ((v1y*points) + (v2y*b->getPoints()))/(points+b->getPoints());

    sp = hypot(vnx, vny);
    rot = atan2(vny, vnx);
    points += b->getPoints();
}

bool ob::isDead(ob *b) {
    return b->getDead();
}
