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

void rock::mov() {
    rad = 4 + points/30;

    int hue;
    if(!evil) {
        //trying exponential:
        hue = 210*exp((double)-points/15) + 30;
        sp = points / 30 * .6 + 1;
    } else {
        hue = 60*exp((double)-points/15) + 270;
        sp = points / 30 * 1.2 + 1;
    }

    hue = hue < 0 ? 0 : hue;
    col.setHsv(hue, 240, 240);

    ob::mov();
}
