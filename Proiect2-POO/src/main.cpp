
// #include "Joc2048.h"
// #include <iostream>
// #include <sstream>
// #include <SFML/Graphics.hpp>

// sf::Color getTileColor(int value) {
//     switch (value) {
//         case 2: return sf::Color(238, 228, 218);
//         case 4: return sf::Color(237, 224, 200);
//         case 8: return sf::Color(242, 177, 121);
//         case 16: return sf::Color(245, 149, 99);
//         case 32: return sf::Color(246, 124, 95);
//         case 64: return sf::Color(246, 94, 59);
//         case 128: return sf::Color(237, 207, 114);
//         case 256: return sf::Color(237, 204, 97);
//         case 512: return sf::Color(237, 200, 80);
//         case 1024: return sf::Color(237, 197, 63);
//         case 2048: return sf::Color(237, 194, 46);
//         default: return sf::Color(205, 193, 180);
//     }
// }

// int main() {
//     const int tileSize = 100, padding = 10, boardSize = 6;
//     sf::RenderWindow window(sf::VideoMode((tileSize + padding) * boardSize + padding,
//                                           (tileSize + padding) * boardSize + padding + 100),
//                             "2048 Game");

//     sf::Font font;
//     if (!font.loadFromFile("src/happy-kids.ttf")) {
//         std::cerr << "Eroare la incarcarea fontului!\n";
//         return -1;
//     }

//     Joc2048 joc;

//     while (window.isOpen()) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//             else if (event.type == sf::Event::KeyPressed) {
//                 if (event.key.code == sf::Keyboard::Left)
//                     joc.muta('a');
//                 else if (event.key.code == sf::Keyboard::Right)
//                     joc.muta('d');
//                 else if (event.key.code == sf::Keyboard::Up)
//                     joc.muta('w');
//                 else if (event.key.code == sf::Keyboard::Down)
//                     joc.muta('s');
//             }
//         }

//         window.clear(sf::Color(250, 248, 239));
//         Board& board = joc.getBoard();

//         for (int i = 0; i < boardSize; ++i) {
//             for (int j = 0; j < boardSize; ++j) {
//                 sf::RectangleShape cell(sf::Vector2f(tileSize, tileSize));
//                 cell.setPosition(padding + j * (tileSize + padding), padding + i * (tileSize + padding));
//                 int val = board.getValoare(i, j);
//                 cell.setFillColor(getTileColor(val));
//                 window.draw(cell);

//                 if (val != 0) {
//                     sf::Text text(std::to_string(val), font, 36);
//                     text.setFillColor(sf::Color::Black);
//                     sf::FloatRect bounds = text.getLocalBounds();
//                     text.setOrigin(bounds.left + bounds.width / 2.0f, bounds.top + bounds.height / 2.0f);
//                     text.setPosition(cell.getPosition().x + tileSize / 2.0f, cell.getPosition().y + tileSize / 2.0f);
//                     window.draw(text);
//                 }
//             }
//         }

//         sf::Text scorText("Scor: " + std::to_string(joc.getScor()), font, 24);
//         scorText.setFillColor(sf::Color::Black);
//         scorText.setPosition(padding, (tileSize + padding) * boardSize + padding);
//         window.draw(scorText);

//         if (joc.esteGameOver()) {
//             sf::Text gameOver("Ai pierdut!", font, 48);
//             gameOver.setFillColor(sf::Color::Red);
//             sf::FloatRect rect = gameOver.getLocalBounds();
//             gameOver.setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);
//             gameOver.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f);
//             window.draw(gameOver);
//             window.display();
//             sf::sleep(sf::seconds(3));
//             window.close();
//         } else {
//             window.display();
//         }
//     }
//     return 0;
// }


#include "Joc2048.h"
#include "Board.h"
#include "JocGreu.h"
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

sf::Color getTileColor(int value) {
    switch (value) {
        case 2: return sf::Color(238, 228, 218);
        case 4: return sf::Color(237, 224, 200);
        case 8: return sf::Color(242, 177, 121);
        case 16: return sf::Color(245, 149, 99);
        case 32: return sf::Color(246, 124, 95);
        case 64: return sf::Color(246, 94, 59);
        case 128: return sf::Color(237, 207, 114);
        case 256: return sf::Color(237, 204, 97);
        case 512: return sf::Color(237, 200, 80);
        case 1024: return sf::Color(237, 197, 63);
        case 2048: return sf::Color(237, 194, 46);
        default: return sf::Color(205, 193, 180);
    }
}

int main() {
    const int tileSize = 100, padding = 10, boardSize = 6;

    std::cout << "Alege modul de joc:\n";
    std::cout << "1. Clasic\n";
    std::cout << "2. Greu (valoare + culoare)\n";

    std::cout << "Introdu alegerea ta: ";

    int optiune;
    std::cin >> optiune;

    std::unique_ptr<Joc2048> joc;

    switch (optiune) {
        case 1: joc = std::make_unique<Joc2048>(); break;
        case 2: joc = std::make_unique<JocGreu>(); break;

        default:
            std::cout << "Optiune invalida. Se porneste modul clasic.\n";
            joc = std::make_unique<Joc2048>();
            break;
    }

    sf::RenderWindow window(sf::VideoMode((tileSize + padding) * boardSize + padding,
                                          (tileSize + padding) * boardSize + padding + 100),
                            "2048 Game");

    sf::Font font;
    if (!font.loadFromFile("src/happy-kids.ttf")) {
        std::cerr << "Eroare la incarcarea fontului!\n";
        return -1;
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Left)
                    joc->mutari('a', optiune);
                else if (event.key.code == sf::Keyboard::Right)
                    joc->mutari('d', optiune);
                else if (event.key.code == sf::Keyboard::Up)
                    joc->mutari('w', optiune);
                else if (event.key.code == sf::Keyboard::Down)
                    joc->mutari('s', optiune);
            }
        }

        window.clear(sf::Color(250, 248, 239));
        const Board& board = joc->getBoard();

        for (int i = 0; i < boardSize; ++i) {
            for (int j = 0; j < boardSize; ++j) {
                sf::RectangleShape cell(sf::Vector2f(tileSize, tileSize));
                cell.setPosition(padding + j * (tileSize + padding), padding + i * (tileSize + padding));
                int val = board.getValoare(i, j);
                cell.setFillColor(getTileColor(val));
                window.draw(cell);

                if (val != 0) {
                    sf::Text text(std::to_string(val), font, 36);
                    text.setFillColor(sf::Color::Black);
                    sf::FloatRect bounds = text.getLocalBounds();
                    text.setOrigin(bounds.left + bounds.width / 2.0f, bounds.top + bounds.height / 2.0f);
                    text.setPosition(cell.getPosition().x + tileSize / 2.0f, cell.getPosition().y + tileSize / 2.0f);
                    window.draw(text);
                }
            }
        }

        sf::Text scorText("Scor: " + std::to_string(joc->getScor()), font, 24);
        scorText.setFillColor(sf::Color::Black);
        scorText.setPosition(padding, (tileSize + padding) * boardSize + padding);
        window.draw(scorText);

        if (joc->esteGameOver()) {
            sf::Text gameOver("Ai pierdut!", font, 48);
            gameOver.setFillColor(sf::Color::Red);
            sf::FloatRect rect = gameOver.getLocalBounds();
            gameOver.setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);
            gameOver.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f);
            window.draw(gameOver);
            window.display();
            sf::sleep(sf::seconds(3));
            window.close();
        } else {
            window.display();
        }
    }

    return 0;
}
