#include "anima.h"

void anima::draw(QPainter &ctx) {
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

void anima::incScore(int point) {
    col = QColor(255,255,255);

    score += point;
}

int anima::getScore() {
    return score;
}

void anima::decLives() {
    lives -= 1;
}

int anima::getLives() {
    return lives;
}
