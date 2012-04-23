#include "rock.h"
using namespace std;

rock::rock() : ob(rnd(0,S_WID),
                  rnd(0,S_HGT),
                  rnd(0,628)/100.0,
                  .2,
                  4,
                  QColor(22,255,128)) {

    points = rnd(0, 60);
    sp = 10 - 5.5*exp((double)-points/100);
}

rock::rock(double nx, double ny, double r) : ob(rnd(0,S_WID),
                                   rnd(0,S_HGT),
                                   rnd(0,628)/100.0,
                                   .2,
                                   4,
                                   QColor(22,255,128)) {
    points = rnd(0, 60);
    x = nx, y = ny, rot = r;
    sp = 10 - 5.5*exp((double)-points/100);
}

rock::rock(double nx, double ny, double r, int pnts) : ob(rnd(0,S_WID),
                                   rnd(0,S_HGT),
                                   rnd(0,628)/100.0,
                                   .2,
                                   4,
                                   QColor(22,255,128)) {
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

    //trying exponential hues and speeds
    int hue = 210*exp((double)-points/15) + 30;

    hue = hue < 0 ? 0 : hue;
    col.setHsv(hue, 240, 240);

    ob::mov();
}
