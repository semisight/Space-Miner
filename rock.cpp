#include "rock.h"

rock::rock() : ob(rnd(0,S_WID), rnd(0,S_HGT), rnd(0,628)/100.0, .2, '+'), evil(rand()%1000 < 700) {
    //Rocks have a 70% chance of being evil, hence the evil(rand()...) above
    if(evil) ch = '*';
};

bool rock::isEvil() {
    return evil;
}
