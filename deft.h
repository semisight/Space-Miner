#ifndef DEFT_H
#define DEFT_H

#include "pugilist.h"

class deft : public pugilist {
public:
    deft(play *p);

    void mov();
    bool firing();
};

#endif // DEFT_H
