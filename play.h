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
    bool firing();

    //This should be virtual. All objects should be capable of reset?
    void reset(bool winner);

    void setKey(int ind, bool set);
private:
    bool keys[5];
};


#endif // PLAY_H
