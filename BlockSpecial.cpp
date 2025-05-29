#include "BlockSpecial.h"

#include <iostream>

BlockSpecial::BlockSpecial(int valoare, bool special)
    : Block(valoare), special(special)
{
}

bool BlockSpecial::esteSpecial() const { return special; }

void BlockSpecial::activeazaSpecial()
{
    if (special)
    {
        std::cout << "Bloc special activat!" << std::endl;
    }
}

sf::Color BlockSpecial::getCuloare() const
{
    if (special)
    {
        return sf::Color(255, 215, 0);  // Aurie pentru blocurile speciale
    }
    return Block::getCuloare();  // Culoarea normală pentru blocurile obișnuite
}