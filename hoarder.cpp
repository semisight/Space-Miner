#include "hoarder.h"
using namespace std;

hoarder::hoarder(play *p, vector<ob*> *g) : pugilist(p, g) {
}

//hoarder is slightly smarter than stupid, in that it actually looks for
//something. It won't shoot though.

void hoarder::mov() {
    if(!good->empty()) {
        ob* min = find_min();

        double nrot;

        if(min)
            nrot = atan2(min->getY()-y, min->getX()-x);
        else {
            nrot = rot;
            cout << "NIL!\n";
        }

        if(fabs(nrot - rot) > 0.15) {
            nrot > rot ? rot += 0.15 : rot -= 0.15;
        }
    }

    anima::mov();
    ob::mov();
}

bool hoarder::firing() {
    return false;
}
