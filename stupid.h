#ifndef STUPID_H
#define STUPID_H

#include "pugilist.h"

class stupid : public pugilist {
public:
    stupid(play *p, std::vector<ob*> *g, std::vector<ob*> *b);

    void mov();

    bool firing();
};

#endif // STUPID_H
