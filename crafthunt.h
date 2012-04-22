#ifndef CRAFTHUNT_H
#define CRAFTHUNT_H

#include "deft.h"

class crafthunt : public deft {
public:
    crafthunt(play *p, std::vector<ob*> *g, std::vector<ob*> *b);

    void mov();
};

#endif // CRAFTHUNT_H
