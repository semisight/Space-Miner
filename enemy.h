#ifndef ENEMY_H
#define ENEMY_H

#include "ob.h"
#include "play.h"

class enemy : public ob {
public:
    enemy();
    virtual void track(play pl) = 0;
};

#endif // ENEMY_H
