#include "rock.h"
using namespace std;

rock::rock(int rock_size) : ob(rnd(0,S_WID),
                  rnd(0,S_HGT),
                  rnd(0,628)/100.0,
                  .2,
                  4,
                  QColor(22,255,128)) {
    points = 20;

    if(rock_size == MEDIUM) {
        sp = .8;
        rad = 5;
        col = QColor(128,255,22);
        points = 30;
    } else if(rock_size == BIG) {
        sp = 1.6;
        rad = 6;
        col = QColor(192,255,22);
        points = 50;
    }
}
