#ifndef ROCK_H
#define ROCK_H

#include <vector>
#include "ob.h"

#define AM_I_EVIL_NOW (rand()%100 < 40)
#define HOW_EVIL (rand()%100 < 30 ? BIG_EVIL : EVIL)

enum {
    SMALL,
    MEDIUM,
    BIG,
    EVIL,
    BIG_EVIL
};

//Not much to the rock class. Just a little evil :P
class rock : public ob {
public:
    rock(int rock_size);
    rock(int rock_size, double nx, double ny);

    void reflect();
private:
    void setup_rock(int rock_size);
};

#endif // ROCK_H
