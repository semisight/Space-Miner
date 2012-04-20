#include "window.h"
#include "rock.h"
using namespace std;

//---- constructor & destructor

window::window(QApplication *parent) : app(parent) {
    for(int i=0; i<40; i++)
        objects.push_back(new rock(false));

    enemies.push_back(new stupid(&player));
    enemies.push_back(new deft(&player));
    enemies.push_back(new deft(&player));
    enemies.push_back(new deft(&player));
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

    //Check victory/failure
    if(objects.empty()) {
        cout << "You win!\n";
        app->exit();
    } else if(player.getLives() <= 0) {
        cout << "You lose!\n";
        app->exit();
    }

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

    //detect object & badobj collisions
    for(int i=0; i<objects.size(); i++) {
        vector<ob*> tmpbad;

        //sometimes good objects go bad...
        for(int j=0; j<badobjs.size(); j++) {
            if(badobjs[j]->coll_detect(objects[i])) {
                if(AM_I_EVIL_NOW) {
                    badobjs[j]->kill();
                    objects[i]->kill();
                    tmpbad.push_back(new rock(true,
                                              objects[i]->getX(),
                                              objects[i]->getY(),
                                              objects[i]->getRot()));
                } else {
                    badobjs[j]->kill();
                    objects[i]->hit(badobjs[j]);
                }
            }
        }

        for(int j=0; j<tmpbad.size(); j++)
            badobjs.push_back(tmpbad[j]);
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
