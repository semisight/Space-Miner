#include "ev_rock.h"
using namespace std;

ev_rock::ev_rock() : rock() {
}

ev_rock::ev_rock(double nx, double ny, double r) : rock(nx, ny, r) {
}

ev_rock::ev_rock(double nx, double ny, double r, int pnts) : rock(nx, ny, r, pnts) {
}

void ev_rock::mov() {
    rad = sqrt(points/15) + 4;

    int hue = 60*exp((double)-points/15) + 270;
    col.setHsv(hue, 240, 240);

    ob::mov();
}
