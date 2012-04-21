#ifndef DEFS_H
#define DEFS_H

#include <ctime>
#include <cmath>
#include <iostream>
#include <Qt>

#define S_WID 1024
#define S_HGT 768

//A quick and dirty macro that generates numbers on the interval [a, b).
#define rnd(a, b) ((rand() % (b-a)) + a)

enum {
    KEY_LEFT = 0,
    KEY_RIGHT,
    KEY_DOWN,
    KEY_UP,
    SPACE
};

#endif // DEFS_H
