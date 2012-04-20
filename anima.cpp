#include "anima.h"
using namespace std;

anima::anima(double nx, double ny, double d, double s, double ss, QColor c) :
    ob(nx, ny, d, s, ss, c), lives(3), bullet_chg(0) {
}

ob* anima::shoot() {
    double qx, qy;
    qx = x + cos(rot)*10;
    qy = y + sin(rot)*10;

    return new bullet(qx, qy, rot);
}

void anima::draw(QPainter &ctx) {
    //move player color slowly to black.
    col = QColor(col.red()*.95, col.green()*.95, col.blue()*.95);

    //setup transforms
    ctx.translate(x, y);
    ctx.rotate(rot * 180/M_PI);

    //set brush & pen color
    ctx.setBrush(col);

    //draw it
    ctx.drawPolygon(triangle, 3);

    //teardown transforms
    ctx.rotate(-rot * 180/M_PI);
    ctx.translate(-x, -y);
}

void anima::mov() {
    //Kinda cheating here. This function is guaranteed to be called once per time step,
    //so I'm using it for all the anima level counters/states that are time sensitive/
    //have no better place to be.

    //Kill if lives are <=0.
    if(lives <= 0) dead = true;

    //Calculate bullet recharge time.
    if(bullet_chg > 0) bullet_chg--;
    if(bullet_chg < 0) bullet_chg = 0;
}

void anima::incScore(int point) {
    col = QColor(255,255,255);

    points += point;
}

int anima::getScore() {
    return points;
}

void anima::decLives() {
    col = QColor(255,0,0);

    lives -= 1;
}

int anima::getLives() {
    return lives;
}

bool anima::request_shot() {
    if(firing() && bullet_chg==0) {
        bullet_chg = 30;
        return true;
    } else {
        if(bullet_chg > 0) bullet_chg--;
        if(bullet_chg < 0) bullet_chg = 0;
        return false;
    }
}
