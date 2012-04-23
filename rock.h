#ifndef ROCK_H
#define ROCK_H

#include <vector>
#include "ob.h"

//Not much to the rock class. Just a little evil :P
class rock : public ob {
public:
    rock();
    rock(double nx, double ny, double r);
    rock(double nx, double ny, double r, int pnts);

    virtual void mov();

private:
};

#endif // ROCK_H
