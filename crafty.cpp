#include "crafty.h"
using namespace std;

crafty::crafty(play *p, vector<ob*> *g, vector<ob*> *b) : hoarder(p, g, b) {
}

//Does a combination of hoarder and avoidant, but I can't call the
//superclass mov() functions because they both call ob::mov().
void crafty::mov() {
    double nrot = rot;

    if(!bad->empty()) {
        ob* min = find_min(false);

        if(min && hypot(min->getX()-x, min->getY()-y) < 200)
            nrot = fmod(atan2(min->getY()-y, min->getX()-x) + M_PI_2, M_2_PI);
    }

    if(nrot != rot) {
        if(fabs(nrot - rot) > 0.15)
            nrot > rot ? rot += turn_sp : rot -= turn_sp;
    } else {
        //If we're not being hunted, then we will hoard
        hoarder::mov();
        return;
    }

    anima::mov();
    ob::mov();
}
