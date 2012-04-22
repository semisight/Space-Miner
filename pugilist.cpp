#include "pugilist.h"

pugilist::pugilist(play *p, std::vector<ob*> *g) :
    anima(rand()%S_WID, rand()%S_HGT, (rand()%628)/100, MAX_SP, 6.5, QColor(255,0,128)),
    protagon(p), good(g) {
}

ob* pugilist::find_min() {
    ob *min = NULL;
    double min_d = 10000;

    for(int i=0; i<good->size(); i++) {
        ob *b = good->at(i);
        double nx = b->getX()-x, ny = b->getY()-y;
        double d = hypot(nx, ny);

        if(d < min_d) {
            min_d = d;
            min = b;
        }
    }

    return min;
}
