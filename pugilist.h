#ifndef PUGILIST_H
#define PUGILIST_H

#include "anima.h"
#include "play.h"

class pugilist : public anima {
public:
    pugilist(play *p);

protected:
    play *protagon;
};

#endif // PUGILIST_H
