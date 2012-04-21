#ifndef ROCK_H
#define ROCK_H

#include <vector>
#include "ob.h"

//Not much to the rock class. Just a little evil :P
class rock : public ob {
public:
    rock(bool e);
    rock(bool e, double nx, double ny, double r);
    rock(bool e, double nx, double ny, double r, int pnts);

    void mov();

private:
    bool evil;
};

#endif // ROCK_H
