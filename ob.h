#ifndef OB_H
#define OB_H

#include <cstdlib>
#include <Qt>
#include <QColor>

#include "defs.h"

//All these classes are documented in much further depth in design.txt

class ob {
public:
    ob(double nx, double ny, double d, double s, double sz, QColor c)
        : x(nx), y(ny), rot(d), sp(s), rad(sz), col(c) {};
	
	virtual void mov();
	void draw();

	//friend is needed to it can access the x,y hidden fields. The alternative was making x,y
	//public, or making it a member function. I think this solution is more explicit than the
	//member function route, so I chose it.
	friend void coll_detect();

    double getX();
    double getY();
    double getRot();
    double getRad();

protected:
    double x, y;        //Position
    double rot, sp;     //Rotation and speed
    double rad;         //radius of object
    QColor col;
};

#endif //OB_H
