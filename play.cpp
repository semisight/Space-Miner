#include "play.h"

play::play() : ob(S_WID/2, S_HGT/2, 0, 1, 6, QColor(0, 0, 255)), score(0), lives(3) {
}

void play::reset() {
    x = S_WID/2;
    y = S_HGT/2;
    rot = 0;
    sp = 1;
    score = 0;
    lives = 3;
}

void play::incScore() {
    score += 20;
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

void play::mov() {

    //Process Keyboard input
    switch(dir) {
        case KEY_UP:
            sp += 0.3;
            break;
        case KEY_LEFT:
            rot -= 0.4;
            break;
        case KEY_DOWN:
            sp -= 0.3;
            break;
        case KEY_RIGHT:
            rot += 0.4;
            break;
    }

    dir = 0;

    //Keep the player's speed within a sane range
    if(sp > 2) sp = 2;
    if(sp < -2) sp = -2;

    ob::mov();
}

void play::setDir(int ndir) {
    dir = ndir;
}
