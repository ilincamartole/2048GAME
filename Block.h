#pragma once
#include <SFML/Graphics.hpp>

template <typename T>
class Block
{
   private:
    T valoare;
    sf::Color culoare;

   public:
    Block()
        : valoare(T()), culoare(sf::Color::White) {}  // constructor implicit

    Block(T v) : valoare(v), culoare(determinaCuloare(v)) {}

    Block(T v, sf::Color c) : valoare(v), culoare(c) {}

    T getValoare() const { return valoare; }

    void setValoare(T v)
    {
        valoare = v;
        culoare = determinaCuloare(v);
    }

    bool esteGol() const
    {
        return valoare == T();
    }  // presupunem că valoarea "zero" sau default înseamnă gol

    void dubleaza()
    {
        valoare = valoare + valoare;
        setCuloare(determinaCuloare(valoare));
    }

    void setCuloare(const sf::Color& nouaCuloare) { culoare = nouaCuloare; }

    virtual sf::Color getCuloare() const { return culoare; }

    sf::Color determinaCuloare(T val) const
    {
        if (val == T())
            return sf::Color(205, 193, 180);  // culoare pentru gol
        else if (val == static_cast<T>(2))
            return sf::Color(238, 228, 218);
        else if (val == static_cast<T>(4))
            return sf::Color(237, 224, 200);
        else if (val == static_cast<T>(8))
            return sf::Color(242, 177, 121);
        else if (val == static_cast<T>(16))
            return sf::Color(245, 149, 99);
        else if (val == static_cast<T>(32))
            return sf::Color(246, 124, 95);
        else if (val == static_cast<T>(64))
            return sf::Color(246, 94, 59);
        else if (val == static_cast<T>(128))
            return sf::Color(237, 207, 114);
        else if (val == static_cast<T>(256))
            return sf::Color(237, 204, 97);
        else if (val == static_cast<T>(512))
            return sf::Color(237, 200, 80);
        else if (val == static_cast<T>(1024))
            return sf::Color(237, 197, 63);
        else if (val == static_cast<T>(2048))
            return sf::Color(237, 194, 46);
        else if (val == static_cast<T>(5))
            return sf::Color(237, 194, 46);
        else
            return sf::Color(
                205, 193, 180);  // culoare implicită pentru orice altă valoare
    }
};
