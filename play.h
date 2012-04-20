#ifndef PLAY_H
#define PLAY_H

#include <Qt>
#include <QPoint>
#include "anima.h"

class play : public anima {
public:
    //Constructor
    play();

    //Inherited functions
    void mov();

    //This should be virtual. All objects should be capable of reset?
    void reset();

    void setKey(int ind, bool set);
private:
    bool keys[4];
};


#endif // PLAY_H
