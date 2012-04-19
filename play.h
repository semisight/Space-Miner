#ifndef PLAY_H
#define PLAY_H

#include <Qt>
#include "ob.h"

class play : public ob {
public:
    play();

    void mov();

    void reset();

    void incScore();
    int getScore();

    void decLives();
    int getLives();

    void setDir(int ndir);

    bool shouldExit();
private:
    int score, lives, dir;
};


#endif // PLAY_H
