#include "Block.h"

#include <SFML/Graphics.hpp>

Block::Block() : valoare(0) {}

Block::Block(int v) : valoare(v) {}

int Block::getValoare() const { return valoare; }

void Block::setValoare(int v)
{
    valoare = v;
    culoare = determinaCuloare(v);
}

bool Block::esteGol() const { return valoare == 0; }

void Block::dubleaza() { valoare *= 2; }
sf::Color Block::getCuloare() const { return culoare; }
void Block::setCuloare(const sf::Color& c) { culoare = c; }
sf::Color Block::determinaCuloare(int valoare) const
{
    switch (valoare)
    {
        case 2:
            return sf::Color(238, 228, 218);
        case 4:
            return sf::Color(237, 224, 200);
        case 8:
            return sf::Color(242, 177, 121);
        case 16:
            return sf::Color(245, 149, 99);
        case 32:
            return sf::Color(246, 124, 95);
        case 64:
            return sf::Color(246, 94, 59);
        case 128:
            return sf::Color(237, 207, 114);
        case 256:
            return sf::Color(237, 204, 97);
        case 512:
            return sf::Color(237, 200, 80);
        case 1024:
            return sf::Color(237, 197, 63);
        case 2048:
            return sf::Color(237, 194, 46);
        default:
            return sf::Color(205, 193, 180);  // Culoare implicită
    }
}
