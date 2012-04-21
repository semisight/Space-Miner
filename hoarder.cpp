#include "hoarder.h"
using namespace std;

hoarder::hoarder(play *p, vector<ob*> &g) : pugilist(p), good(g) {
}

//hoarder is slightly smarter than stupid, in that it actually looks for
//something. It won't shoot though.

void hoarder::mov() {
    if(!good.empty()) {

        ob *min = NULL;
        double min_rat = 0;

        //TODO: find closest object
        //things to take into account:
        //1. How close is it? (duh).
        //2. How much do I need to turn?
        //3. Consider going off screen.
        for(int i=0; i<good.size(); i++) {
            ob *b = good[i];
            double nx = b->getX()-x, ny = b->getY()-y;
            double d = hypot(nx, ny), ang = atan2(ny, nx);

            double tmp_rat = d*exp(ang*ang/2);
            if(tmp_rat > min_rat) {
                min = b;
                min_rat = tmp_rat;
            }
        }

        double nrot = min ? atan2(min->getY(), min->getX()) : 0;

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
