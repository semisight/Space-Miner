#ifndef ROCK_H
#define ROCK_H

#include "ob.h"

//Not much to the rock class. Just a little evil :P
class rock : public ob {
public:
    rock();

    bool isEvil();
private:
    bool evil;
};

#endif // ROCK_H
