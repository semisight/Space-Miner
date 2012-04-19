#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QApplication>
#include <QKeyEvent>
#include <QPainter>
#include <Qt>

#include <map>
#include <vector>
#include <iostream>
#include <sstream>

#include "play.h"

class window : public QWidget {
    Q_OBJECT
    
public:
    window(QApplication *parent = 0);
    ~window();

    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);

private:
    std::vector<ob*> objects;
    play player;
    int timer_id;

    bool keys[4];

    QApplication *app;
};

#endif // WINDOW_H
