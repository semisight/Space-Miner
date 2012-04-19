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

    for(int i=0; i<objects.size(); i++) {
        if(!objects[i]->getDead()) {
            int r = objects[i]->getRad();

            ctx.setBrush(objects[i]->getCol());
            ctx.drawEllipse(QPointF(objects[i]->getX(), objects[i]->getY()), r, r);
        }
    }

    ctx.setBrush(player.getCol());
    ctx.drawEllipse(QPointF(player.getX(), player.getY()),
                    player.getRad(),
                    player.getRad());
}

void window::timerEvent(QTimerEvent *ev) {
    //do basic cleanup
    remove_if(objects.begin(), objects.end(), ob::isDead);

    //set title: name, score, lives
    stringstream ss;
    ss << "Space Miner lives:" << player.getLives() << " score: " << player.getScore();

    setWindowTitle(ss.str().c_str());

    //move objects
    for(int i=0; i<objects.size(); i++) {
        objects[i]->mov();
        if(objects[i]->coll_detect(player)) {
            objects[i]->kill();
            player.incScore();
        }
    }

    //move player
    player.mov();

    repaint();
}

void window::keyPressEvent(QKeyEvent *ev) {
    switch(ev->key()) {
    case Qt::Key_Left:
        player.setKey(KEY_LEFT, true);
        break;
    case Qt::Key_Right:
        player.setKey(KEY_RIGHT, true);
        break;
    case Qt::Key_Up:
        player.setKey(KEY_UP, true);
        break;
    case Qt::Key_Down:
        player.setKey(KEY_DOWN, true);
        break;
    case Qt::Key_Q:
        app->exit();
        break;
    default:
        ev->ignore();
    }
}

void window::keyReleaseEvent(QKeyEvent *ev) {
    switch(ev->key()) {
    case Qt::Key_Left:
        player.setKey(KEY_LEFT, false);
        break;
    case Qt::Key_Right:
        player.setKey(KEY_RIGHT, false);
        break;
    case Qt::Key_Up:
        player.setKey(KEY_UP, false);
        break;
    case Qt::Key_Down:
        player.setKey(KEY_DOWN, false);
        break;
    case Qt::Key_Q:
        app->exit();
        break;
    default:
        ev->ignore();
    }
}
