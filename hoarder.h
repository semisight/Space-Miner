#ifndef HOARDER_H
#define HOARDER_H

#include "pugilist.h"

class hoarder : public pugilist {
public:
    hoarder(play *p, std::vector<ob*> &g);

    virtual void mov();
    virtual bool firing();

private:
    std::vector<ob*> &good;
};

#endif // HOARDER_H
