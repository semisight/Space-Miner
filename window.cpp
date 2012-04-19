#include "window.h"
#include "rock.h"
using namespace std;

window::window(QApplication *parent) : app(parent) {
    for(int i=0; i<40; i++)
        objects.push_back(new rock);

    startTimer(10);
}

window::~window() {
    
}

void window::paintEvent(QPaintEvent *ev) {
    QPainter ctx(this);

    for(int i=0; i<objects.size(); i++) {
        ctx.drawEllipse(QPointF(objects[i]->getX(), objects[i]->getY()),
                        objects[i]->getRad(), objects[i]->getRad());
    }
}

void window::timerEvent(QTimerEvent *ev) {
    for(int i=0; i<objects.size(); i++)
        objects[i]->mov();

    //player.mov();

    repaint();
}

void window::keyPressEvent(QKeyEvent *ev) {
    switch(ev->key()) {
    case Qt::Key_Left:
        player.setDir(KEY_LEFT);
        break;
    case Qt::Key_Right:
        player.setDir(KEY_RIGHT);
        break;
    case Qt::Key_Up:
        player.setDir(KEY_UP);
        break;
    case Qt::Key_Down:
        player.setDir(KEY_DOWN);
        break;
    case Qt::Key_Q:
        app->exit();
        break;
    default:
        ev->ignore();
    }
}
