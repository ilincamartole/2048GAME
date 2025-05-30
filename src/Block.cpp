// #include "Block.h"
// acest fisier se aplica doar pentru tema2; cand am transformat proiectul
// pentru tema3, am transformat clasa Block in template si fisierul Block.cpp nu
// mai este necesar

// #include <SFML/Graphics.hpp>

// Block::Block() : valoare(0) {}

// Block::Block(int v, sf::Color c) : valoare(v), culoare(sf::Color(205, 193,
// 180)) {}

// Block::Block(int v) : valoare(v), culoare(determinaCuloare(v)) {}

// int Block::getValoare() const { return valoare; }

// void Block::setValoare(int v)
// {
//     valoare = v;
//     if (v == 0)
//     {
//         culoare = sf::Color(205, 193, 180); // Culoare implicită pentru
//         blocuri goale
//     }
//     else
//     {
//         culoare = determinaCuloare(v); // Culoare specifică pentru valoare
//     }
// }

// bool Block::esteGol() const { return valoare == 0; }

// void Block::dubleaza() { valoare *= 2; }
// sf::Color Block::getCuloare() const { return culoare; }
// void Block::setCuloare(const sf::Color& c) { culoare = c; }
// sf::Color Block::determinaCuloare(int valoare) const
// {
//     switch (valoare)
//     {
//         case 2:
//             return sf::Color(238, 228, 218);
//         case 4:
//             return sf::Color(237, 224, 200);
//         case 8:
//             return sf::Color(242, 177, 121);
//         case 16:
//             return sf::Color(245, 149, 99);
//         case 32:
//             return sf::Color(246, 124, 95);
//         case 64:
//             return sf::Color(246, 94, 59);
//         case 128:
//             return sf::Color(237, 207, 114);
//         case 256:
//             return sf::Color(237, 204, 97);
//         case 512:
//             return sf::Color(237, 200, 80);
//         case 1024:
//             return sf::Color(237, 197, 63);
//         case 2048:
//             return sf::Color(237, 194, 46);
//         default:
//             return sf::Color(205, 193, 180);  // Culoare implicită
//     }
// }
