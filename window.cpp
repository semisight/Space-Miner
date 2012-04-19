#include "window.h"
using namespace std;

window::window(QApplication *parent) : app(parent) {
}

window::~window() {
    
}

void window::paintEvent(QPaintEvent *ev) {

}

void window::timerEvent(QTimerEvent *ev) {
    for(int i=0; i < objects.size(); i++)
        objects[i]->mov();

    player.mov();
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
