#include "boss.h"
using namespace std;

boss::boss(play *p, vector<ob*> *g, vector<ob*> *b, vector<anima*> *e) :
    deft(p, g, b, e) {
    fight_rad = 600;
    rad = 3*rad;
    lives = 5;
    turn_sp = 0.05;
    sp = PLAY_MAX_SP + 0.5;
}

const QPointF* boss::sub_draw() const {
    return boss_tri;
}

bool boss::request_shot() {
    if(firing() && bullet_chg==0 && points >= 5) {
        points -= 5;
        bullet_chg = 10;
        return true;
    } else {
        if(bullet_chg > 0) bullet_chg--;
        if(bullet_chg < 0) bullet_chg = 0;
        return false;
    }
}

ob* boss::shoot() {
    double qx, qy;
    qx = x + cos(rot)*35;
    qy = y + sin(rot)*35;

    return new bullet(qx, qy, rot);
}
