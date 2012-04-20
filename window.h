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

class window : public QWidget {
    Q_OBJECT
    
public:
    //Constructor & destructor
    window(QApplication *parent = 0);
    ~window();

    //Inherited functions
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);

private:
    std::vector<ob*> objects;
    std::vector<ob*> badobjs;
    std::vector<anima*> enemies;
    play player;
    int timer_id;

    bool keys[4];

    QApplication *app;
};

#endif // WINDOW_H
