#include "Block.h"

Block::Block() : valoare(0) {} 

Block::Block(int v) : valoare(v) {}  // Constructor cu valoare specifică

int Block::getValoare() const {
    return valoare;  // Returnează valoarea blocului
}

void Block::setValoare(int v) {
    valoare = v;  // Setează valoarea blocului
}

bool Block::esteGol() const {
    return valoare == 0;  // Verifică dacă valoarea blocului este 0
}

void Block::dubleaza() {
    valoare *= 2;  // Dublează valoarea blocului
}
sf::Color Block::getCuloare() const {
    return culoare;  // Returnează culoarea blocului
}
void Block::setCuloare(const sf::Color& c) {
    culoare = c;
}


