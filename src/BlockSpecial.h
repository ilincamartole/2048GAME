#pragma once
#include <SFML/Graphics.hpp>

#include "Block.h"
template <typename T>
class BlockSpecial : public Block<T>
{
   private:
    bool special;  // Indică dacă blocul este special

   public:
    BlockSpecial(T valoare = 0, bool special = false);

    bool esteSpecial() const;

    void activeazaSpecial();

    sf::Color getCuloare() const override;
};
