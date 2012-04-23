#include "deft.h"
using namespace std;

deft::deft(play *p, vector<ob*> *g, vector<ob*> *b, vector<anima*> *e) :
    hoarder(p, g, b), is_hoarding(true), en(e) {
    sp = 1.5;
    fight_rad = 125;
}

void deft::mov() {

    if((points < 10 && !is_hoarding) || points < 120) {
        //Hoard
        is_hoarding = true;
        hoarder::mov();
    } else {
        //Kill
        is_hoarding = false;

        double qx = protagon->getX() - x;
        double qy = protagon->getY() - y;
        double qr = atan2(qy, qx);
        double qh = hypot(qx, qy);

        for(uint i=0; i<en->size(); i++) {
            anima* t = en->at(i);
            if(t != this) {
                qx = t->getX() - x;
                qy = t->getY() - y;

                if(hypot(qx, qy) < qh) {
                    qh = hypot(qx, qy);
                    qr = atan2(qy, qx);
                }
            }
        }

        if((qr - rot) < M_PI && qr > rot)
            rot += turn_sp;
        else
            rot -= turn_sp;
    }

    anima::mov();
    ob::mov();
}

bool deft::firing() {
    double qx = protagon->getX() - x;
    double qy = protagon->getY() - y;
    double qr = atan2(qy, qx);
    double qh = hypot(qx, qy);

    for(uint i=0; i<en->size(); i++) {
        anima* t = en->at(i);
        if(t != this) {
            qx = t->getX() - x;
            qy = t->getY() - y;

            if(hypot(qx, qy) < qh) {
                qh = hypot(qx, qy);
                qr = atan2(qy, qx);
            }
        }
    }

    return fabs(qr - rot) < 0.3 && qh < fight_rad;
}
