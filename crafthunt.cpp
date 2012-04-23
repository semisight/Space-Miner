#include "crafthunt.h"
using namespace std;

crafthunt::crafthunt(play *p, vector<ob*> *g, vector<ob*> *b, vector<anima*> *e) :
    deft(p, g, b, e) {
    fight_rad = 225;
}

//Mostly the same as craftplus, but it will shoot as well.
void crafthunt::mov() {
    double nrot = rot;

    if(!bad->empty()) {
        ob* min = find_min(false);

        if(!min) {
            //If we can't find a baddie, just hoard.
            hoarder::mov();
            return;
        }

        if(hypot(min->getX()-x, min->getY()-y) < 125)
            nrot = atan2(min->getY()-y, min->getX()-x) - M_PI_2;
    }

    if(nrot != rot) {
        if(fabs(nrot - rot) > 0.15)
            nrot > rot ? rot += turn_sp : rot -= turn_sp;
    } else {
        //If we're not being hunted, then we will hunt.
        deft::mov();
        return;
    }

    anima::mov();
    ob::mov();
}
