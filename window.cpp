#include "window.h"
#include "rock.h"
using namespace std;

//---- constructor & destructor

window::window(QApplication *parent) : app(parent) {
    for(int i=0; i<30; i++)
        objects.push_back(new rock(SMALL));

    for(int i=0; i<7; i++)
        objects.push_back(new rock(MEDIUM));

    for(int i=0; i<3; i++)
        objects.push_back(new rock(BIG));

    timer_id = startTimer(33);
}

window::~window() {
    for(int i=0; i<objects.size(); i++)
        if(objects[i]) delete objects[i];

    killTimer(timer_id);
}

//---- inherited functions

void window::paintEvent(QPaintEvent *ev) {
    QPainter ctx(this);

    ctx.setPen(QPen(QBrush(QColor(0,0,0)), 2, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin));

    for(int i=0; i<objects.size(); i++) {
        if(!objects[i]->getDead())
            objects[i]->draw(ctx);
    }

    player.draw(ctx);
}

void window::timerEvent(QTimerEvent *ev) {

    //do basic cleanup
    objects.resize(remove_if(objects.begin(), objects.end(), ob::isDead) - objects.begin());

    //set title: name, score, lives
    stringstream ss;
    ss << "Space Miner lives:" << player.getLives() << " score: " << player.getScore();

    setWindowTitle(ss.str().c_str());

    //move objects
    for(int i=0; i<objects.size(); i++) {
        objects[i]->mov();
        if(objects[i]->coll_detect(player)) {
            objects[i]->kill();
            player.incScore(objects[i]->getPoints());
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
