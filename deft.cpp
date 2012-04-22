#include "deft.h"
using namespace std;

deft::deft(play *p, vector<ob*> *g) : hoarder(p, g), is_hoarding(true) {
    sp = 1.5;
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

        if((qr - rot) < M_PI && qr > rot)
            rot += 0.15;
        else
            rot -= 0.15;
    }

    anima::mov();
    ob::mov();
}

bool deft::firing() {
    double qx = protagon->getX() - x;
    double qy = protagon->getY() - y;
    double qr = atan2(qy, qx);
    double qh = hypot(qx, qy);

    return fabs(qr - rot) < 0.3 && qh < 200;
}
