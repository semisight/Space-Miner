#ifndef BULLET_H
#define BULLET_H

#include "ob.h"

class bullet : public ob {
public:
    bullet(double nx, double ny, double d);

    void mov();
private:
};

#endif // BULLET_H
