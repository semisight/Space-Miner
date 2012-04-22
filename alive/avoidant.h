#ifndef AVOIDANT_H
#define AVOIDANT_H

#include "pugilist.h"

class avoidant : public pugilist {
public:
    avoidant(play *p, std::vector<ob*> *g, std::vector<ob*> *b);

    void mov();
    bool firing();
};

#endif // AVOIDANT_H
