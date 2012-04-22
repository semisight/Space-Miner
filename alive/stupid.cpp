#include "stupid.h"
#include "play.h"

stupid::stupid(play *p, std::vector<ob*> *g, std::vector<ob*> *b) : pugilist(p, g, b) {
}

//This is literally the simplest class that makes a "functional" enemy. I may
//have to add more, but it makes a good tutorial enemy.

void stupid::mov() {
    anima::mov();
    ob::mov();
}

bool stupid::firing() {
    return true;
}
