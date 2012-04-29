#ifndef BOSS_H
#define BOSS_H

#include "deft.h"

class boss : public deft {
public:
    boss(play *p, std::vector<ob*> *g, std::vector<ob*> *b, std::vector<anima*> *e);

    const QPointF* sub_draw() const;
    bool request_shot();
    ob* shoot();
};

#endif // BOSS_H
