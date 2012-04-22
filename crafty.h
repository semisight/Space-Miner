#ifndef CRAFTY_H
#define CRAFTY_H

#include "hoarder.h"

class crafty : public hoarder {
public:
    crafty(play *p, std::vector<ob*> *g, std::vector<ob*> *b);

    void mov();
};

#endif // CRAFTY_H
