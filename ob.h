#ifndef OB_H
#define OB_H

#include <cstdlib>
#include <Qt>
#include <QColor>
#include <QPainter>

#include "defs.h"

//All these classes are documented in much further depth in design.txt

class ob {
public:
    ob(double nx, double ny, double d, double s, double sz, QColor c)
        : x(nx), y(ny), rot(d), sp(s), rad(sz), col(c), dead(false) {};
	
	virtual void mov();
    virtual void draw(QPainter &ctx);

	//friend is needed to it can access the x,y hidden fields. The alternative was making x,y
	//public, or making it a member function. I think this solution is more explicit than the
	//member function route, so I chose it.
    virtual bool coll_detect(const ob &b) const;

    double getX() const;
    double getY() const;
    double getRot() const;
    double getRad() const;
    QColor getCol() const;
    bool getDead() const;

    void kill();

    static bool isDead(ob *b);

protected:
    double x, y;        //Position
    double rot, sp;     //Rotation and speed
    double rad;         //radius of object
    QColor col;

    bool dead;
};

#endif //OB_H
