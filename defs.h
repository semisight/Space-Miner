#ifndef DEFS_H
#define DEFS_H

#include <cmath>

#define S_WID 640
#define S_HGT 480

//A quick and dirty macro that generates numbers on the interval [a, b).
#define rnd(a, b) ((rand() % (b-a)) + a)

enum {
    KEY_LEFT = 0,
    KEY_RIGHT,
    KEY_DOWN,
    KEY_UP
};

#endif // DEFS_H
