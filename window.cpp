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

    enemies.push_back(new stupid(&player));
    enemies.push_back(new hoarder(&player, objects));


    timer_id = startTimer(33);
}

window::~window() {
    for(int i=0; i<objects.size(); i++)
        if(objects[i]) delete objects[i];

    for(int i=0; i<badobjs.size(); i++)
        if(badobjs[i]) delete badobjs[i];

    for(int i=0; i<enemies.size(); i++)
        if(enemies[i]) delete enemies[i];

    killTimer(timer_id);
}

//---- inherited functions

void window::paintEvent(QPaintEvent *ev) {
    QPainter ctx(this);

    ctx.setPen(default_pen);

    for(int i=0; i<objects.size(); i++) {
        if(!objects[i]->getDead())
            objects[i]->draw(ctx);
    }

    for(int i=0; i<badobjs.size(); i++) {
        if(!badobjs[i]->getDead())
            badobjs[i]->draw(ctx);
    }

    for(int i=0; i<enemies.size(); i++) {
        if(!enemies[i]->getDead())
            enemies[i]->draw(ctx);
    }

    player.draw(ctx);
}

void window::timerEvent(QTimerEvent *ev) {

    //do basic cleanup
    objects.resize(remove_if(objects.begin(), objects.end(), ob::isDead) - objects.begin());
    badobjs.resize(remove_if(badobjs.begin(), badobjs.end(), ob::isDead) - badobjs.begin());
    enemies.resize(remove_if(enemies.begin(), enemies.end(), ob::isDead) - enemies.begin());

    //set title: name, score, lives
    stringstream ss;
    ss << "Space Miner! -- Lives:" << player.getLives() << " -- Score: " << player.getScore();
    setWindowTitle(ss.str().c_str());

    //move objects
    for(int i=0; i<objects.size(); i++) {
        objects[i]->mov();
        if(objects[i]->coll_detect(&player)) {
            objects[i]->kill();
            player.incScore(objects[i]->getPoints());
        }
    }

    //detect player & badobjs
    for(int i=0; i<badobjs.size(); i++) {
        badobjs[i]->mov();
        if(badobjs[i]->coll_detect(&player)) {
            badobjs[i]->kill();
            player.decLives();
        }
    }

    //move badobjs
    for(int i=0; i<badobjs.size(); i++)
        badobjs[i]->mov();

    //move enemies & do collision detection in the same loop
    for(int i=0; i<enemies.size(); i++) {
        enemies[i]->mov();

        //enemies earn points too!
        for(int j=0; j<objects.size(); j++) {
            if(objects[j]->coll_detect(enemies[i])) {
                objects[j]->kill();
                enemies[i]->incScore(objects[j]->getPoints());
            }
        }

        //enemies can die... of course?
        for(int j=0; j<badobjs.size(); j++) {
            if(badobjs[j]->coll_detect(enemies[i])) {
                badobjs[j]->kill();
                enemies[i]->decLives();
            }
        }
    }

    //move player
    player.mov();

    //shoot
    if(player.request_shot())
        badobjs.push_back(player.shoot());

    for(int i=0; i<enemies.size(); i++) {
        if(enemies[i]->request_shot())
            badobjs.push_back(enemies[i]->shoot());
    }

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
    case Qt::Key_Space:
        player.setKey(SPACE, true);
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
    case Qt::Key_Space:
        player.setKey(SPACE, false);
        break;
    case Qt::Key_Q:
        app->exit();
        break;
    default:
        ev->ignore();
    }
}
