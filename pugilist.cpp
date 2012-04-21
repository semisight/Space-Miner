#include "pugilist.h"

pugilist::pugilist(play *p) : anima(rand()%S_WID, rand()%S_HGT, (rand()%628)/100, 2, 6.5, QColor(255,0,128)),
    protagon(p) {
}
