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
                                   evil(e){
    points = rnd(0, 60);
    x = nx, y = ny, rot = r;
}

void rock::mov() {
    rad = 4 + points/30;

    if(!evil) {
        col.setHsv((int)(-2.5*points + 210)%360, 240, 240);
        sp = points / 30 * .6 + 1;
    } else {
        col.setHsv((int)(-1.5*points + 390)%360, 240, 240);
        sp = points / 30 * 1.2 + 1;
    }

    ob::mov();
}
