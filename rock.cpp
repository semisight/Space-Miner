#include "rock.h"

rock::rock() : ob(rnd(0,S_WID),
                  rnd(0,S_HGT),
                  rnd(0,628)/100.0,
                  .2,
                  4,
                  QColor(22,255,22)) {
};

bool rock::isEvil() {
    return evil;
}
