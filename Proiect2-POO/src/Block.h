#pragma once
#include <SFML/Graphics.hpp>

class Block
{
   private:
    int valoare;
    sf::Color culoare;

   public:
    Block();
    Block(int v);

    int getValoare() const;
    void setValoare(int v);

    bool esteGol() const;
    void dubleaza();
    void setCuloare(const sf::Color& nouaCuloare);
    virtual sf::Color getCuloare() const;
    sf::Color determinaCuloare(int valoare) const;
};
