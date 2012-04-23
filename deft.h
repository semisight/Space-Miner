#ifndef DEFT_H
#define DEFT_H

#include "hoarder.h"

class deft : public hoarder {
public:
    deft(play *p, std::vector<ob*> *g, std::vector<ob*> *b, std::vector<anima*> *e);

    virtual void mov();
    virtual bool firing();

private:
    bool is_hoarding;
    std::vector<anima*> *en;

protected:
    double fight_rad;
};

#endif // DEFT_H
