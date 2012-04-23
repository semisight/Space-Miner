#include "craftplus.h"
using namespace std;

craftplus::craftplus(play *p, vector<ob*> *g, vector<ob*> *b) : hoarder(p, g, b) {
}

void craftplus::mov() {
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
            nrot > rot ? rot += turn_sp : rot -= turn_sp;
    } else {
        //If we're not being hunted, then we will hoard.
        hoarder::mov();
        return;
    }

    anima::mov();
    ob::mov();
}

bool craftplus::firing() {
    return false;
}
