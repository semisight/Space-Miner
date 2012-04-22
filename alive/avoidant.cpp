#include "avoidant.h"
using namespace std;

avoidant::avoidant(play *p, vector<ob*> *g, vector<ob*> *b) : pugilist(p, g, b) {
}

void avoidant::mov() {
    if(!good->empty()) {
        ob* min = find_min(false);

        //Unlike in hoarder's class, here we want to avoid all harmful objects.
        //We're gonna do this by prefering a perpindicular angle between us
        //and the nearest baddie.
        double nrot;

        if(min && hypot(min->getX()-x, min->getY()-y) < 300)
            nrot = fmod(atan2(min->getY()-y, min->getX()-x) + M_PI_2, M_2_PI);
        else
            nrot = rot;

        if(fabs(nrot - rot) > 0.15) {
            nrot > rot ? rot += 0.15 : rot -= 0.15;
        }
    }

    anima::mov();
    ob::mov();
}

bool avoidant::firing() {
    return false;
}
