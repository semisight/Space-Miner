#ifndef DEFT_H
#define DEFT_H

#include "hoarder.h"

class deft : public hoarder {
public:
    deft(play *p, std::vector<ob *> &g);

    void mov();
    bool firing();

private:
    bool is_hoarding;
};

#endif // DEFT_H
