#include "avoidant.h"
using namespace std;

avoidant::avoidant(play *p, vector<ob*> *g, vector<ob*> *b) : pugilist(p, g, b) {
}

void avoidant::mov() {
    //Unlike in hoarder's class, here we want to avoid all harmful objects.
    //We're gonna do this by prefering a perpindicular angle between us
    //and the nearest baddie.
    double nrot = rot;

    if(!bad->empty()) {
        ob* min = find_min(false);

        if(min && hypot(min->getX()-x, min->getY()-y) < 300)
            nrot = fmod(atan2(min->getY()-y, min->getX()-x) + M_PI_2, M_2_PI);
    }

    if(fabs(nrot - rot) > 0.15)
        nrot > rot ? rot += 0.15 : rot -= 0.15;

    anima::mov();
    ob::mov();
}

bool avoidant::firing() {
    return false;
}
