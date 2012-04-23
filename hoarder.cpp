#include "hoarder.h"
using namespace std;

hoarder::hoarder(play *p, vector<ob*> *g, vector<ob*> *b) : pugilist(p, g, b) {
}

//hoarder is slightly smarter than stupid, in that it actually looks for
//something. It won't shoot though.

void hoarder::mov() {
    if(!good->empty()) {
        ob* min = find_min(true);

        double nrot;

        if(min)
            nrot = atan2(min->getY()-y, min->getX()-x);
        else
            nrot = rot;

        if(fabs(nrot - rot) > 0.15) {
            nrot > rot ? rot += turn_sp : rot -= turn_sp;
        }
    }

    anima::mov();
    ob::mov();
}

bool hoarder::firing() {
    return false;
}
