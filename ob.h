#ifndef OB_H
#define OB_H

#include <cstdlib>
#include "defs.h"

//All these classes are documented in much further depth in design.txt

class ob {
public:
    ob(double nx, double ny, double d, double s, char c) : x(nx), y(ny), rot(d), sp(s), ch(c) {};
	
	virtual void mov();
	void draw();

	//friend is needed to it can access the x,y hidden fields. The alternative was making x,y
	//public, or making it a member function. I think this solution is more explicit than the
	//member function route, so I chose it.
	friend void coll_detect();

    double getX();
    double getY();
    double getRot();

protected:
    double x, y, rot, sp;
    char ch;
};

#endif //OB_H
