#ifndef ANIMA_H
#define ANIMA_H

#include "ob.h"

//Abstract base class for "live" objects (including player)

const QPointF triangle[3] = {
    QPointF(-5, -4),
    QPointF(-5,  4),
    QPointF( 5,  0)
};

class anima : public ob {
public:
    anima(double nx, double ny, double d, double s, double ss, QColor c) : ob(nx, ny,d, s, ss, c) {};

    void draw(QPainter &ctx);

    //Setters and getters
    virtual void incScore(int point);
    virtual int getScore();

    virtual void decLives();
    virtual int getLives();
protected:
    int score, lives;
};

#endif // ANIMA_H
