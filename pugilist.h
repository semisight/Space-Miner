#ifndef PUGILIST_H
#define PUGILIST_H

#include "anima.h"
#include "play.h"

#define MAX_SP 3

class pugilist : public anima {
public:
    pugilist(play *p, std::vector<ob*> *g);

    ob* find_min();
protected:
    play *protagon;
    std::vector<ob*> *good;
};

#endif // PUGILIST_H
