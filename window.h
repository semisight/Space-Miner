#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QApplication>
#include <QKeyEvent>
#include <QPainter>
#include <Qt>

#include <algorithm>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>

#include "play.h"
#include "stupid.h"
#include "hoarder.h"
#include "deft.h"

enum {
    EASY,
    MED,
    HARD
};

const QString greetings(
        "Hello, intrepid explorer! Welcome to Space Miner! I think you'll see"
        " that there's more to this game than meets the eye.\n\n"
        "The premise here is simple; collect the cool yellow/green blue rocks"
        " that you see floating around to get points. Avoid enemies and their"
        " bullets (avoid your bullets too). You can shoot with as well (use"
        " the [SPACE] bar), but it costs energy, which is taken from your"
        "points. Your score and lives are in the title of the window. That's"
        "it!\n\n"
        "Press any key_");

class window : public QWidget {
    Q_OBJECT
    
public:
    //Constructor & destructor
    window(QApplication *parent = 0);
    ~window();

    //Inherited functions
    void paintEvent(QPaintEvent * __attribute__((unused)));
    void timerEvent(QTimerEvent * __attribute__((unused)));
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);

private:
    //different possible states
    void level_begin();
    void end_screen();
    void menu();

    //common level functions
    void game_loop();
    void clean();
    void set_title();
    void move_and_interact();
    void process_shots();
    void reset(bool winner);

    //called outside of game loop
    //>0 for win, <0 for loss, ==0 otherwise
    int check_win_loss();

    std::vector<ob*> objects;
    std::vector<ob*> badobjs;
    std::vector<anima*> enemies;
    play player;
    int timer_id;
    int level;

    //bool keys[4];

    QApplication *app;
};

#endif // WINDOW_H
