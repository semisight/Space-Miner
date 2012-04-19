#include "window.h"
#include "rock.h"
using namespace std;

window::window(QApplication *parent) : app(parent) {
    for(int i=0; i<40; i++)
        objects.push_back(new rock);

    timer_id = startTimer(33);
}

window::~window() {
    for(int i=0; i<objects.size(); i++)
        delete objects[i];

    killTimer(timer_id);
}

void window::paintEvent(QPaintEvent *ev) {
    QPainter ctx(this);
    ctx.setBrush(Qt::SolidPattern);

    for(int i=0; i<objects.size(); i++) {
        int r = objects[i]->getRad();

        ctx.drawEllipse(QPointF(objects[i]->getX(), objects[i]->getY()), r, r);
    }

    ctx.setBrush(QBrush(QColor(55,55,255)));
    ctx.drawEllipse(QPointF(player.getX(), player.getY()),
                    player.getRad(),
                    player.getRad());
}

void window::timerEvent(QTimerEvent *ev) {
    for(int i=0; i<objects.size(); i++)
        objects[i]->mov();

    player.mov();

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
