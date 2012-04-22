#ifndef CRAFTPLUS_H
#define CRAFTPLUS_H

#include "hoarder.h"

class craftplus : public hoarder {
public:
    craftplus(play *p, std::vector<ob*> *g, std::vector<ob*> *b);

    void mov();
    bool firing();
};

#endif // CRAFTPLUS_H
