#include "rock.h"
using namespace std;

rock::rock(int rock_size) : ob(rnd(0,S_WID),
                  rnd(0,S_HGT),
                  rnd(0,628)/100.0,
                  .2,
                  4,
                  QColor(22,255,128)) {
    points = 20;
    setup_rock(rock_size);
}

rock::rock(int rock_size, double nx, double ny) : ob(rnd(0,S_WID),
                                                     rnd(0,S_HGT),
                                                     rnd(0,628)/100.0,
                                                     .2,
                                                     4,
                                                     QColor(22,255,128)) {
    x = nx, y = ny;

    setup_rock(rock_size);
}

void rock::setup_rock(int rock_size) {
    switch(rock_size) {
        case MEDIUM:
            sp = .8;
            rad = 5;
            col = QColor(128,255,22);
            points = 30;
            break;
        case BIG:
            sp = 1.6;
            rad = 6;
            col = QColor(192,255,22);
            points = 50;
            break;
        case EVIL:
            sp = 1.6;
            rad = 4;
            col = QColor(255,192,22);
            break;
        case BIG_EVIL:
            sp = 3.2;
            rad = 5;
            col = QColor(255,22,192);
            break;
    }
}
