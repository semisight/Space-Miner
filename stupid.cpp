#include "stupid.h"
#include "play.h"

stupid::stupid(play *p) : pugilist(p) {
}

void stupid::mov() {
    anima::mov();
    ob::mov();
}

bool stupid::firing() {
    return true;
}
