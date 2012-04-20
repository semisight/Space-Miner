#ifndef PLAY_H
#define PLAY_H

#include <Qt>
#include <QPoint>
#include "ob.h"

const QPointF triangle[3] = {
    QPointF(-5, -4),
    QPointF(-5,  4),
    QPointF( 5,  0)
};

class play : public ob {
public:
    //Constructor
    play();

    //Inherited functions
    void mov();
    void draw(QPainter &ctx);

    //This should be virtual. All objects should be capable of reset?
    void reset();

    //Setters and getters
    void incScore();
    int getScore();

    void decLives();
    int getLives();

    void setKey(int ind, bool set);

private:
    int score, lives, dir;
    bool keys[4];
};


#endif // PLAY_H
