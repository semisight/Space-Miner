#ifndef ROCK_H
#define ROCK_H

#include <vector>
#include "ob.h"

#define AM_I_EVIL_NOW (rand()%100 < 40)
#define HOW_EVIL (rand()%100 < 30 ? BIG_EVIL : EVIL)

//Not much to the rock class. Just a little evil :P
class rock : public ob {
public:
    rock(bool e);
    rock(bool e, double nx, double ny, double r);

    void mov();

private:
    bool evil;
};

#endif // ROCK_H
