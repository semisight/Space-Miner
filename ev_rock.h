#ifndef EV_ROCK_H
#define EV_ROCK_H

#include "rock.h"

class ev_rock : public rock {
public:
    ev_rock();
    ev_rock(double nx, double ny, double r);
    ev_rock(double nx, double ny, double r, int pnts);

    void mov();
};

#endif // EV_ROCK_H
