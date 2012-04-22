#ifndef HOARDER_H
#define HOARDER_H

#include "pugilist.h"

class hoarder : public pugilist {
public:
    hoarder(play *p, std::vector<ob*> *g, std::vector<ob*> *b);

    virtual void mov();
    virtual bool firing();

private:
};

#endif // HOARDER_H
