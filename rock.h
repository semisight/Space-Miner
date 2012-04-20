#ifndef ROCK_H
#define ROCK_H

#include <vector>
#include "ob.h"

enum {
    SMALL,
    MEDIUM,
    BIG
};

//Not much to the rock class. Just a little evil :P
class rock : public ob {
public:
    rock(int rock_size);

    int getRockSize() const;
private:
};

#endif // ROCK_H
