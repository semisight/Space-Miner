#include <QApplication>
#include <QDesktopWidget>
#include "window.h"
#include "defs.h"

int main(int argc, char *argv[]) {
    srand(time(NULL));

    QApplication *a = new QApplication(argc, argv);
    window win(a);

    QDesktopWidget *d = QApplication::desktop();

    int wid = (d->width() - S_WID)/2;
    int hgt = (d->height() - S_HGT)/2;

    win.setGeometry(wid, hgt, S_WID, S_HGT);
    win.setFixedSize(S_WID, S_HGT);

    win.show();
    return a->exec();
}
