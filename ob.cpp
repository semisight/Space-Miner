#include "ob.h"
using namespace std;

void ob::mov() {
    //Objects got some bounce!
    double dx = cos(rot) * sp;
    double dy = sin(rot) * sp;

    if(x >= S_WID-rad || x < rad+1) {
        x = x < rad+1 ? rad+1 : x;
        x = x >= S_WID-rad ? S_WID-rad : x;
        dx *= -1;
    }

    if(y >= S_HGT-rad || y < rad+1) {
        y = y < rad+1 ? rad+1 : y;
        y = y >= S_HGT-rad ? S_HGT-rad : y;
        dy *= -1;
    }

    if(sp != 0) {
        rot = atan2(dy, dx);
        if(sp < 0) rot += M_PI;
    }

    x += cos(rot) * sp;
    y += sin(rot) * sp;
}

void ob::draw(QPainter &ctx) {
    ctx.setBrush(col);
    ctx.drawEllipse(QPointF(x, y), rad, rad);
}

bool ob::coll_detect(ob *b) const {
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

void ob::getInfo(QPainter &ctx) {
    stringstream ss;
    ss << points;

    ctx.setFont(QFont("Helvetica Neue", 10));
    ctx.drawText(QRect(x-10, y+rad+1, 20, 12),
                 Qt::AlignHCenter,
                 ss.str().c_str());
}
