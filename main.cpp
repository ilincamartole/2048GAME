#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "Block.h"
#include "Board.h"
#include "EroareJoc.h"
#include "Joc2048.h"
#include "JocUsor.h"
#include "JocGreu.h"
#include "JocRandom.h"
#include "Scor.h"
#include "EroareFereastra.h"
#include "EroareFont.h"
#include "EroareModJocInvalid.h"
#include "BlockSpecial.h"
#include "JocPowersOfFive.h"

int main()
{
    const int tileSize = 100, padding = 10, boardSize = 4;

    int optiune;
    std::cout << "Alege modul de joc (1 - Clasic, 2 - Greu, 3 - Random, 4 - PowersOfFive): ";
    std::cin >> optiune;

    try
    {
        if (optiune != 1 && optiune != 2 && optiune != 3 && optiune != 4)
        {
            throw EroareModJocInvalid();
        }
    }
    catch (const EroareJoc& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;  // Închide programul
    }

    std::unique_ptr<Joc2048> joc;

    switch (optiune)
    {
        case 1:
            joc = std::make_unique<Joc2048>();
            break;
        case 2:
            joc = std::make_unique<JocGreu>();
            break;
        case 3:
            joc = std::make_unique<JocRandom>();
            break;
         case 4:
             joc = std::make_unique<JocPowersOfFive>(); // Adaugă opțiunea pentru JocUsor
             break;
        default:
            std::cout << "Optiune invalida. Se porneste modul clasic.\n";
            joc = std::make_unique<Joc2048>();
            break;
    }

    Joc2048* jocTest = new JocGreu();
    if (auto* jocGreu = dynamic_cast<JocGreu*>(jocTest))
    {
        std::cout << "Jocul este in modul on." << std::endl;
    }
    delete jocTest;

    JocGreu jocOriginal;
    jocOriginal.getScor().adauga(100);  // Adaugă un scor pentru testare

    // Creează o copie folosind constructorul de copiere
    JocGreu jocCopie = jocOriginal;

    // Verifică dacă scorul a fost copiat corect
    std::cout << "Scor original: " << jocOriginal.getScor().getScorCurent()
              << std::endl;
    std::cout << "Scor copie: " << jocCopie.getScor().getScorCurent()
              << std::endl;

    sf::RenderWindow window(
        sf::VideoMode((tileSize + padding) * boardSize + padding,
                      (tileSize + padding) * boardSize + padding + 100),
        "2048 Game");
    if (!window.isOpen())
    {
        throw EroareFereastra();
    }

    sf::Font font;
    try
    {
        if (!font.loadFromFile("src/happy-kids.ttf"))
        {
            throw EroareFont();
        }
    }
    catch (const EroareJoc& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;  // Închide programul
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed)
            {
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

        for (int i = 0; i < boardSize; ++i)
        {
            for (int j = 0; j < boardSize; ++j)
            {
                sf::RectangleShape cell(sf::Vector2f(tileSize, tileSize));
                cell.setPosition(padding + j * (tileSize + padding),
                                 padding + i * (tileSize + padding));
                int val = board.getValoare(i, j);
                cell.setFillColor(
                    board.getCuloare(i, j));  // Folosește culoarea blocului
                window.draw(cell);

                if (val != 0)
                {
                    sf::Text text(std::to_string(val), font, 36);
                    text.setFillColor(sf::Color::Black);
                    sf::FloatRect bounds = text.getLocalBounds();
                    text.setOrigin(bounds.left + bounds.width / 2.0f,
                                   bounds.top + bounds.height / 2.0f);
                    text.setPosition(cell.getPosition().x + tileSize / 2.0f,
                                     cell.getPosition().y + tileSize / 2.0f);
                    window.draw(text);
                }
            }
        }

        sf::Text scorText(
            "Scor: " + std::to_string(joc->getScor().getScorCurent()), font,
            24);
        scorText.setFillColor(sf::Color::Black);
        scorText.setPosition(padding,
                             (tileSize + padding) * boardSize + padding);
        window.draw(scorText);

        if (joc->esteGameOver())
        {
            sf::Text gameOver;
            if (joc->getBoard().estePlin() && joc->getBoard().esteBlocaje())
            {
                gameOver.setString("Ai pierdut!");
                gameOver.setFillColor(sf::Color::Red);
            }
            else
            {
                gameOver.setString("Felicitari!");
                gameOver.setFillColor(sf::Color::Green);
            }

            gameOver.setFont(font);
            gameOver.setCharacterSize(48);
            sf::FloatRect rect = gameOver.getLocalBounds();
            gameOver.setOrigin(rect.left + rect.width / 2.0f,
                               rect.top + rect.height / 2.0f);
            gameOver.setPosition(window.getSize().x / 2.0f,
                                 window.getSize().y / 2.0f);
            window.draw(gameOver);
            window.display();
            sf::sleep(sf::seconds(3));

            // Salvează scorul curent
            joc->getScor().salveazaScor();

            // Afișează toate scorurile
            joc->getScor().afiseazaScoruri();

            window.close();
        }
        else
        {
            window.display();
        }
    }

    return 0;
}
