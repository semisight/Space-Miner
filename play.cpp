#include "play.h"
using namespace std;

//Constructor
play::play() : anima(S_WID/2, S_HGT/2, 0, -1, 6.5, QColor(0, 0, 255)) {
    keys[0] = false;
    keys[1] = false;
    keys[2] = false;
    keys[3] = false;
    keys[4] = false;

    def_col = QColor(0,0,255);
}

//---- inherited functions

void play::mov() {

    sp *= .93;

    //Process Keyboard input
        if(keys[KEY_UP]) sp += 0.3;
        if(keys[KEY_LEFT]) rot -= turn_sp;
        if(keys[KEY_DOWN]) sp -= 0.3;
        if(keys[KEY_RIGHT]) rot += turn_sp;

    //Keep the player's speed within a sane range
    if(sp > PLAY_MAX_SP) sp = PLAY_MAX_SP;
    if(sp < -PLAY_MAX_SP) sp = -PLAY_MAX_SP;

    //Call superclass mov functions
    anima::mov();
    ob::mov();
}

bool play::firing() {
    return keys[SPACE];
}

//---- misc functions

void play::reset(bool winner) {
    if(!winner) {
        x = S_WID/2;
        y = S_HGT/2;
        rot = 0;
        sp = 1;
        points = 0;
        lives = 3;
    }
}

//---- getters and setters

void play::setKey(int ind, bool set) {
    keys[ind] = set;
}
