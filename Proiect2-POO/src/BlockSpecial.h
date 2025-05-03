#pragma once
#include <SFML/Graphics.hpp>

#include "Block.h"

class BlockSpecial : public Block
{
   private:
    bool special;  // Indică dacă blocul este special

   public:
    BlockSpecial(int valoare = 0, bool special = false);

    bool esteSpecial() const;

    void activeazaSpecial();

    sf::Color getCuloare() const override;
};