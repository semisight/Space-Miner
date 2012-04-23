#include "pugilist.h"
using namespace std;

pugilist::pugilist(play *p, vector<ob*> *g, vector<ob*> *b) :
    anima(rand()%S_WID, rand()%S_HGT, (rand()%628)/100, MAX_SP, 6.5, QColor(255,0,128)),
    protagon(p), good(g), bad(b) {

}

ob* pugilist::find_min(bool look_at_good) {
    vector<ob*> *vec = look_at_good ? good : bad;

    ob *min = NULL;
    double min_d = 10000;

    for(uint i=0; i<vec->size(); i++) {
        ob *b = vec->at(i);
        double nx = b->getX()-x, ny = b->getY()-y;
        double d = hypot(nx, ny);

        if(d < min_d) {
            min_d = d;
            min = b;
        }
    }

    return min;
}
