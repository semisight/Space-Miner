#include "hoarder.h"
using namespace std;

hoarder::hoarder(play *p, vector<ob*> &g) : pugilist(p), good(g) {
}

//hoarder is slightly smarter than stupid, in that it actually looks for
//something. It won't shoot though.

void hoarder::mov() {
    if(!good.empty()) {

        ob *min = good[0];

        //TODO: find closest object

        double nrot = atan2(min->getY(), min->getX());

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
