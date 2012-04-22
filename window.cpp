#include "window.h"
#include "rock.h"
using namespace std;

//---- constructor & destructor

window::window(QApplication *parent) : app(parent) {
    level = EASY;
    game_state = BEGIN;
    still_playing = true;
    level_begin();
    timer_id = startTimer(33);
}

window::~window() {
    for(uint i=0; i<objects.size(); i++)
        if(objects[i]) delete objects[i];

    for(uint i=0; i<badobjs.size(); i++)
        if(badobjs[i]) delete badobjs[i];

    for(uint i=0; i<enemies.size(); i++)
        if(enemies[i]) delete enemies[i];

    killTimer(timer_id);
}

//---- inherited functions

void window::paintEvent(QPaintEvent *ev __attribute__((unused))) {
    QPainter ctx(this);
    ctx.setPen(default_pen);
    ctx.setFont(QFont("Helvetica Neue", 14, 300));

    switch(game_state) {
        case BEGIN:
            ctx.drawText(QRectF(40, 40, S_WID-40, S_HGT-40),
                         Qt::AlignLeft | Qt::TextWordWrap,
                         words::greetings);
            break;
        case END_SC:
            player.draw(ctx);

            if(still_playing) {
                //Print get ready for level "level"
                ctx.drawText(QRectF(40, 40, S_WID-40, S_HGT-40),
                             Qt::AlignLeft | Qt::TextWordWrap,
                             words::next_level);
            } else {
                //Print you lost!
                ctx.drawText(QRectF(40, 40, S_WID-40, S_HGT-40),
                             Qt::AlignLeft | Qt::TextWordWrap,
                             words::better_luck);
            }
            break;
        case GAME:
            for(uint i=0; i<objects.size(); i++) {
                if(!objects[i]->getDead())
                    objects[i]->draw(ctx);
            }

            for(uint i=0; i<badobjs.size(); i++) {
                if(!badobjs[i]->getDead())
                    badobjs[i]->draw(ctx);
            }

            for(uint i=0; i<enemies.size(); i++) {
                if(!enemies[i]->getDead())
                    enemies[i]->draw(ctx);
            }

            player.draw(ctx);
            break;
    }
}

void window::timerEvent(QTimerEvent *ev __attribute__((unused))) {
    if(game_state == GAME) {
        switch(check_win_loss()) {
            case 0:
                game_loop();
                break;
            case 1:
                game_state = END_SC;
                reset(true);
                level_begin();
                break;
            case -1:
                game_state = END_SC;
                reset(false);
                still_playing = false;
                break;
        }
    }

    repaint();
}

void window::keyPressEvent(QKeyEvent *ev) {

    if(game_state == GAME) {
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
    } else {
        int a = ev->key();

        //Still allow the player to quit.
        if(a==Qt::Key_Q)
            app->exit();

        //Don't want the player to accidentally trigger the move to the next level.
        if(a==Qt::Key_Left || a==Qt::Key_Right || a==Qt::Key_Up ||
                a==Qt::Key_Down || a==Qt::Key_Space)
            ev->ignore();
        else {
            game_state = GAME;
            if(!still_playing) {
                game_state = BEGIN;
                still_playing = true;
                reset(false);
                level_begin();
            }
        }
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

void window::level_begin() {
    switch(level) {
        case EASY:
            for(int i=0; i<70; i++)
                objects.push_back(new rock(false));

            for(int i=0; i<3; i++)
                enemies.push_back(new hoarder(&player, &objects));
            break;
        case MED:
            for(int i=0; i<70; i++)
                objects.push_back(new rock(false));

            for(int i=0; i<2; i++)
                enemies.push_back(new hoarder(&player, &objects));

            for(int i=0; i<2; i++)
                enemies.push_back(new deft(&player, &objects));
            break;
        case HARD:
            for(int i=0; i<70; i++)
                objects.push_back(new rock(false));

            for(int i=0; i<40; i++)
                enemies.push_back(new stupid(&player, &objects));

            for(int i=0; i<2; i++)
                enemies.push_back(new hoarder(&player, &objects));

            for(int i=0; i<3; i++)
                enemies.push_back(new deft(&player, &objects));
            break;
    }

    //ensure next time the level is one higher.
    level++;
}

void window::menu() {
    //TODO: Implement.
}

void window::game_loop() {
    //do basic cleanup
    clean();

    //set title: name, score, lives
    set_title();

    //move and detect
    move_and_interact();

    //shoot
    process_shots();
}

void window::clean() {
    objects.resize(remove_if(objects.begin(), objects.end(), ob::isDead) - objects.begin());
    badobjs.resize(remove_if(badobjs.begin(), badobjs.end(), ob::isDead) - badobjs.begin());
    enemies.resize(remove_if(enemies.begin(), enemies.end(), ob::isDead) - enemies.begin());
}

void window::set_title() {
    stringstream ss;
    ss << "Space Miner! -- Lives:" << player.getLives() << " -- Score: " << player.getScore() << " -- Level: " << level;
    setWindowTitle(ss.str().c_str());
}

void window::move_and_interact() {
    //move objects & detect player & objects
    for(uint i=0; i<objects.size(); i++) {
        objects[i]->mov();
        if(objects[i]->coll_detect(&player)) {
            objects[i]->kill();
            player.incScore(objects[i]->getPoints());
        }
    }

    //detect player & badobjs
    for(uint i=0; i<badobjs.size(); i++) {
        badobjs[i]->mov();
        if(badobjs[i]->coll_detect(&player)) {
            badobjs[i]->kill();
            player.decLives();
        }
    }

    //move badobjs
    for(uint i=0; i<badobjs.size(); i++)
        badobjs[i]->mov();

    //move enemies & do collision detection in the same loop
    for(uint i=0; i<enemies.size(); i++) {
        enemies[i]->mov();

        //enemies earn points too!
        for(uint j=0; j<objects.size(); j++) {
            if(objects[j]->coll_detect(enemies[i])) {
                objects[j]->kill();
                enemies[i]->incScore(objects[j]->getPoints());
            }
        }

        //enemies can die... of course?
        for(uint j=0; j<badobjs.size(); j++) {
            if(badobjs[j]->coll_detect(enemies[i])) {
                badobjs[j]->kill();
                enemies[i]->decLives();
            }
        }
    }

    //detect object & badobj collisions
    for(uint i=0; i<objects.size(); i++) {
        vector<ob*> tmpbad;

        //sometimes good objects go bad...
        for(uint j=0; j<badobjs.size(); j++) {
            if(badobjs[j]->coll_detect(objects[i])) {
                //TODO: smaller objects split.
                if(4*badobjs[j]->getPoints() > objects[i]->getPoints()) {
                    badobjs[j]->kill();
                    objects[i]->kill();
                    tmpbad.push_back(new rock(true,
                                              objects[i]->getX(),
                                              objects[i]->getY(),
                                              objects[i]->getRot()));
                    objects[i]->hit(badobjs[j]);
                } else {
                    badobjs[j]->kill();
                    objects[i]->hit(badobjs[j]);
                }
            }
        }

        for(uint j=0; j<tmpbad.size(); j++)
            badobjs.push_back(tmpbad[j]);
    }

    //Last but not least, object & object
    for(uint i=0; i<objects.size(); i++) {
        for(uint j=0; j<objects.size(); j++) {
            if(i != j && objects[i]->coll_detect(objects[j])) {
                objects[j]->kill();
                objects[i]->hit(objects[j]);
            }
        }
    }

    //If an enemy has 0 lives, it esplodes!
    for(uint i=0; i<enemies.size(); i++) {
        if(enemies[i]->getLives() <= 0) {
            objects.push_back(new rock(false, enemies[i]->getX(),
                                       enemies[i]->getY(),
                                       enemies[i]->getRot()));
        }
    }

    //move player
    player.mov();
}

void window::process_shots() {
    if(player.request_shot())
        badobjs.push_back(player.shoot());

    for(uint i=0; i<enemies.size(); i++) {
        if(enemies[i]->request_shot())
            badobjs.push_back(enemies[i]->shoot());
    }
}

int window::check_win_loss() {
    if(objects.empty()) {
        return 1;
    } else if(player.getLives() <= 0) {
        return -1;
    }

    return 0;
}

void window::reset(bool winner=false) {
    for(uint i=0; i<objects.size(); i++)
        if(objects[i]) delete objects[i];

    for(uint i=0; i<badobjs.size(); i++)
        if(badobjs[i]) delete badobjs[i];

    for(uint i=0; i<enemies.size(); i++)
        if(enemies[i]) delete enemies[i];

    objects.clear();
    badobjs.clear();
    enemies.clear();
    player.reset(winner);

    if(!winner) level = 0;
}
