#ifndef ANIMA_H
#define ANIMA_H

#include "ob.h"
#include "bullet.h"

//Abstract base class for "live" objects (including player)

const QPointF triangle[3] = {
    QPointF(-5, -4),
    QPointF(-5,  4),
    QPointF( 5,  0)
};

class anima : public ob {
public:
    anima(double nx, double ny, double d, double s, double ss, QColor c);

    virtual ob* shoot();

    void draw(QPainter &ctx);
    virtual void mov();

    //Setters and getters
    virtual void incScore(int point);
    virtual int getScore();

    void incLives();
    virtual void decLives();
    virtual int getLives();

    virtual bool firing() = 0;
    bool request_shot();
protected:
    int lives, bullet_chg;
    QColor def_col;
};

#endif // ANIMA_H
