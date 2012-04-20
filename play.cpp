#include "play.h"

//Constructor
play::play() : ob(S_WID/2, S_HGT/2, 0, 1, 6, QColor(0, 0, 255)), score(0), lives(3) {
    keys[0] = false;
    keys[1] = false;
    keys[2] = false;
    keys[3] = false;
}

//---- inherited functions

void play::mov() {

    sp *= .93;

    //Process Keyboard input
        if(keys[KEY_UP]) sp += 0.25;
        if(keys[KEY_LEFT]) rot -= 0.15;
        if(keys[KEY_DOWN]) sp -= 0.25;
        if(keys[KEY_RIGHT]) rot += 0.15;

    dir = 0;

    //Keep the player's speed within a sane range
    if(sp > 4) sp = 4;
    if(sp < -4) sp = -4;

    ob::mov();
}

void play::draw(QPainter &ctx) {
    //move player color slowly to black.
    col = QColor(col.red()*.95, col.green()*.95, col.blue()*.95);

    //setup transforms
    ctx.translate(x, y);
    ctx.rotate(rot * 180/M_PI);

    ctx.setBrush(col);
    ctx.drawPolygon(triangle, 3);

    //teardown transforms
    ctx.translate(-x, -y);
    ctx.rotate(-rot * 180/M_PI);
}

//---- misc functions

void play::reset() {
    x = S_WID/2;
    y = S_HGT/2;
    rot = 0;
    sp = 1;
    score = 0;
    lives = 3;
}

//---- getters and setters

void play::incScore(int point) {
    col = QColor(255,255,255);

    score += point;
}

int play::getScore() {
    return score;
}

void play::decLives() {
    lives -= 1;
}

int play::getLives() {
    return lives;
}

void play::setKey(int ind, bool set) {
    keys[ind] = set;
}
