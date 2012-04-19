#ifndef PLAY_H
#define PLAY_H

#include <Qt>
#include "ob.h"

class play : public ob {
public:
    play();

    void mov();
    void coll_detect(const ob &b);

    void reset();

    void incScore();
    int getScore();

    void decLives();
    int getLives();

    void setKey(int ind, bool set);

    bool shouldExit();
private:
    int score, lives, dir;
    bool keys[4];
};


#endif // PLAY_H
