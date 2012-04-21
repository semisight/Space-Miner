#include "rock.h"
using namespace std;

rock::rock(bool e) : ob(rnd(0,S_WID),
                  rnd(0,S_HGT),
                  rnd(0,628)/100.0,
                  .2,
                  4,
                  QColor(22,255,128)),
                  evil(e) {

    points = rnd(0, 60);
}

rock::rock(bool e, double nx, double ny, double r) : ob(rnd(0,S_WID),
                                   rnd(0,S_HGT),
                                   rnd(0,628)/100.0,
                                   .2,
                                   4,
                                   QColor(22,255,128)),
                                   evil(e) {
    points = rnd(0, 60);
    x = nx, y = ny, rot = r;
}

rock::rock(bool e, double nx, double ny, double r, int pnts) : ob(rnd(0,S_WID),
                                   rnd(0,S_HGT),
                                   rnd(0,628)/100.0,
                                   .2,
                                   4,
                                   QColor(22,255,128)),
                                   evil(e) {
    points = pnts;
    x = nx, y = ny, rot = r;
}

void rock::mov() {
    //If points = mass, and density is constant...
    //m/a = d = C => m/C = a.
    //But area is a = pi*r^2.
    //if D = pi*C, m/D = r^2.
    //Therefore, we'll have r = (points/D)^1/2,
    //where r(0) = 4, r(60) = 6 (same as in the original formula).
    rad = sqrt(points/15) + 4;

    int hue;
    if(!evil) {
        //trying exponential:
        //s(0) = .5
        //s(+inf) -> 6
        //6 - 5.5*exp(-p)
        hue = 210*exp((double)-points/15) + 30;
        sp = 6 - 5.5*exp((double)-points/100);
    } else {
        hue = 60*exp((double)-points/15) + 270;
        sp = 6 - 5.5*exp((double)-points/50);
    }

    hue = hue < 0 ? 0 : hue;
    col.setHsv(hue, 240, 240);

    ob::mov();
}
