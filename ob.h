#ifndef OB_H
#define OB_H

#include <cstdlib>
#include <sstream>
#include <Qt>
#include <QColor>
#include <QPainter>

#include "defs.h"

//All these classes are documented in much further depth in design.txt

const QPen default_pen(QBrush(QColor(0,0,0)), 2, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);

class ob {
public:
    //Constructor
    ob(double nx, double ny, double d, double s, double sz, QColor c)
        : x(nx), y(ny), rot(d), sp(s), rad(sz), col(c), points(0), dead(false) {};
	
    //Inherited functions
	virtual void mov();
    virtual void draw(QPainter &ctx);
    virtual bool coll_detect(ob *b) const;

    //getters & setters
    double getX() const;
    double getY() const;
    double getRot() const;
    double getSp() const;
    double getRad() const;
    QColor getCol() const;
    bool getDead() const;
    int getPoints() const;
    void kill();
    void hit(ob *b);

    static bool isDead(ob *b);

    //Not a pure getter... but close enough
    void getInfo(QPainter &ctx);

protected:
    double x, y;        //Position
    double rot, sp;     //Rotation and speed
    double rad;         //radius of object
    QColor col;
    int points;
    bool dead;
};

#endif //OB_H
