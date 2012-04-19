#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QApplication>
#include <QKeyEvent>
#include <Qt>
#include <vector>

#include "play.h"

class window : public QWidget {
    Q_OBJECT
    
public:
    window(QApplication *parent = 0);
    ~window();

    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *);

private:
    std::vector<ob*> objects;
    play player;

    QApplication *app;
};

#endif // WINDOW_H
