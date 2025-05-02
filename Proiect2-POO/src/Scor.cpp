#include "Scor.h"

Scor::Scor() : scorCurent(0) {}

void Scor::reset() {
    scorCurent = 0;
}

void Scor::adauga(int valoare) {
    scorCurent += valoare;
}

int Scor::getScorCurent() const {
    return scorCurent;
}
