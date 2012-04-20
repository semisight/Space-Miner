#include "deft.h"

deft::deft(play *p) : pugilist(p) {
    sp = 1;
}

void deft::mov() {
    double qx = protagon->getX() - x;
    double qy = protagon->getY() - y;
    double qr = atan2(qy, qx);

    if((qr - rot) < M_PI && qr > rot)
        rot += 0.15;
    else
        rot -= 0.15;

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
