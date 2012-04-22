#include "crafthunt.h"
using namespace std;

crafthunt::crafthunt(play *p, vector<ob*> *g, vector<ob*> *b) : deft(p, g, b) {
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

        if(hypot(x-min->getX(), y-min->getY()) < 125)
            nrot = fmod(atan2(y-min->getY(), x-min->getX()) - M_PI_4, M_2_PI);
    }

    if(nrot != rot) {
        if(fabs(nrot - rot) > 0.15)
            nrot > rot ? rot += 0.15 : rot -= 0.15;
    } else {
        //If we're not being hunted, then we will hoard.
        deft::mov();
        return;
    }

    anima::mov();
    ob::mov();
}
