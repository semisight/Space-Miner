#ifndef PUGILIST_H
#define PUGILIST_H

#include "anima.h"
#include "play.h"

#define MAX_SP 2.5

class pugilist : public anima {
public:
    pugilist(play *p, std::vector<ob*> *g, std::vector<ob*> *b);

    ob* find_min(bool look_at_good);
protected:
    play *protagon;
    std::vector<ob*> *good;
    std::vector<ob*> *bad;
};

#endif // PUGILIST_H
