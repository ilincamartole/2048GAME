#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "EroareJoc.h"
#include "EroareModJocInvalid.h"
#include "Joc2048.h"
#include "JocExtrem.h"
#include "JocFactory.h"
#include "JocGreu.h"
#include "JocMultiplesOfFive.h"
#include "JocRandom.h"
#include "UserManager.h"

void setTextCenter(sf::Text& text, float x, float y)
{
    sf::FloatRect rect = text.getLocalBounds();
    text.setOrigin(rect.left + rect.width / 2.f, rect.top + rect.height / 2.f);
    text.setPosition(x, y);
}

struct Button
{
    sf::RectangleShape shape;
    sf::Text text;

    Button(const sf::Font& font, const std::string& label, sf::Vector2f size,
           sf::Vector2f pos)
    {
        shape.setSize(size);
        shape.setFillColor(sf::Color(180, 180, 180));
        shape.setPosition(pos);
        shape.setOutlineThickness(2);
        shape.setOutlineColor(sf::Color::Black);

        text.setFont(font);
        text.setString(label);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Black);

        sf::FloatRect bounds = text.getLocalBounds();
        text.setOrigin(bounds.left + bounds.width / 2.f,
                       bounds.top + bounds.height / 2.f);
        text.setPosition(pos.x + size.x / 2.f, pos.y + size.y / 2.f);
    }

    bool isMouseOver(sf::Vector2f mousePos) const
    {
        return shape.getGlobalBounds().contains(mousePos);
    }

    void setHover(bool hover)
    {
        shape.setFillColor(hover ? sf::Color(150, 150, 250)
                                 : sf::Color(180, 180, 180));
    }

    void draw(sf::RenderWindow& window) const
    {
        window.draw(shape);
        window.draw(text);
    }
};

bool meniulLogin(sf::RenderWindow& window, sf::Font& font,
                 std::string& outUsername, UserManager& userManager)
{
    sf::String inputUsername, inputPassword;
    bool typingUsername = true;
    std::string errorMsg;

    sf::Text instrText("Introduceti username, Enter, apoi parola, Enter", font,
                       18);
    instrText.setFillColor(sf::Color::Black);
    instrText.setPosition(20, 20);

    sf::Text userLabel("Username:", font, 24);
    userLabel.setFillColor(sf::Color::Black);
    userLabel.setPosition(20, 100);

    sf::Text passLabel("Parola:", font, 24);
    passLabel.setFillColor(sf::Color::Black);
    passLabel.setPosition(20, 180);

    sf::Text userInput("", font, 24);
    userInput.setFillColor(sf::Color::Blue);
    userInput.setPosition(150, 100);

    sf::Text passInput("", font, 24);
    passInput.setFillColor(sf::Color::Blue);
    passInput.setPosition(150, 180);

    sf::Text errorText("", font, 20);
    errorText.setFillColor(sf::Color::Red);
    errorText.setPosition(20, 250);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) return false;

            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode == 8)
                {
                    if (typingUsername && !inputUsername.isEmpty())
                        inputUsername.erase(inputUsername.getSize() - 1, 1);
                    else if (!typingUsername && !inputPassword.isEmpty())
                        inputPassword.erase(inputPassword.getSize() - 1, 1);
                }
                else if (event.text.unicode == 13)
                {
                    if (typingUsername)
                    {
                        if (inputUsername.isEmpty()) continue;
                        typingUsername = false;
                    }
                    else
                    {
                        if (inputPassword.isEmpty()) continue;
                        std::string userStr = inputUsername.toAnsiString();
                        std::string passStr = inputPassword.toAnsiString();
                        if (userManager.validateUser(userStr, passStr))
                        {
                            outUsername = userStr;
                            return true;
                        }
                        else
                        {
                            errorMsg = "Utilizator sau parola invalida!";
                            inputPassword.clear();
                        }
                    }
                }
                else if (event.text.unicode >= 32 && event.text.unicode < 127)
                {
                    if (typingUsername)
                        inputUsername += static_cast<char>(event.text.unicode);
                    else
                        inputPassword += static_cast<char>(event.text.unicode);
                }
            }
        }

        userInput.setString(inputUsername);
        passInput.setString(std::string(inputPassword.getSize(), '*'));
        errorText.setString(errorMsg);

        window.clear(sf::Color(250, 248, 239));
        window.draw(instrText);
        window.draw(userLabel);
        window.draw(passLabel);
        window.draw(userInput);
        window.draw(passInput);
        if (!errorMsg.empty()) window.draw(errorText);
        window.display();
    }
    return false;
}

int meniulAlegereMod(sf::RenderWindow& window, sf::Font& font)
{
    std::vector<Button> buttons;
    const sf::Vector2f size(300, 60);
    const float startX = (window.getSize().x - size.x) / 2.f;
    float startY = 150;

    buttons.push_back(
        Button(font, "1 - Clasic", size, sf::Vector2f(startX, startY)));
    buttons.push_back(
        Button(font, "2 - Greu", size, sf::Vector2f(startX, startY + 80)));
    buttons.push_back(
        Button(font, "3 - Random", size, sf::Vector2f(startX, startY + 160)));
    buttons.push_back(Button(font, "4 - PowersOfFive", size,
                             sf::Vector2f(startX, startY + 240)));
    buttons.push_back(
        Button(font, "5 - Extrem", size, sf::Vector2f(startX, startY + 320)));

    Button backButton(font, "Inapoi la Meniu Principal", sf::Vector2f(300, 50),
                      sf::Vector2f(startX, startY + 400));

    while (window.isOpen())
    {
        sf::Event event;
        sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) return -1;

            if (event.type == sf::Event::MouseMoved)
            {
                for (auto& btn : buttons)
                    btn.setHover(btn.isMouseOver(mousePos));
                backButton.setHover(backButton.isMouseOver(mousePos));
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    for (size_t i = 0; i < buttons.size(); ++i)
                    {
                        if (buttons[i].isMouseOver(mousePos))
                        {
                            return static_cast<int>(i + 1);
                        }
                    }
                    if (backButton.isMouseOver(mousePos))
                    {
                        return 0;
                    }
                }
            }
        }

        window.clear(sf::Color(250, 248, 239));
        sf::Text title("Alege modul de joc", font, 30);
        title.setFillColor(sf::Color::Black);
        setTextCenter(title, window.getSize().x / 2.f, 60);
        window.draw(title);

        for (const auto& btn : buttons) btn.draw(window);

        backButton.draw(window);

        window.display();
    }
    return -1;
}

int main()
{
    const int tileSize = 100, padding = 10;

    sf::RenderWindow window(sf::VideoMode(800, 700), "2048 Game");

    if (!window.isOpen())
    {
        std::cerr << "Eroare la deschiderea ferestrei!\n";
        return 1;
    }

    sf::Font font;
    if (!font.loadFromFile("src/happy-kids.ttf"))
    {
        std::cerr << "Eroare la incarcare font!\n";
        return 1;
    }

    UserManager& userManager = UserManager::getInstance();
    if (!userManager.loadUsersFromFile("src/user.txt"))
    {
        std::cerr << "Nu s-au putut incarca userii din fisier!\n";
        return 1;
    }

    while (window.isOpen())  // meniul de login
    {
        std::string username;
        if (!meniulLogin(window, font, username, userManager)) break;

        std::cout << "Username logat: " << username << "\n";

        int optiune = meniulAlegereMod(window, font);
        if (optiune == -1) break;
        if (optiune == 0) continue;

        std::unique_ptr<Joc2048> joc;

        try
        {
            joc = JocFactory::createJoc(optiune);
        }
        catch (const EroareJoc& e)
        {
            std::cerr << e.what() << std::endl;
            break;
        }

        int boardSize = joc->getBoard().getDim();
        int windowWidth = (tileSize + padding) * boardSize + padding;
        int windowHeight = (tileSize + padding) * boardSize + padding + 120;

        window.create(sf::VideoMode(windowWidth, windowHeight),
                      "2048 Game - Mod " + std::to_string(optiune));

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
                    cell.setFillColor(board.getCuloare(i, j));
                    window.draw(cell);

                    if (val != 0)
                    {
                        sf::Text text(std::to_string(val), font, 36);
                        text.setFillColor(sf::Color::Black);
                        sf::FloatRect bounds = text.getLocalBounds();
                        text.setOrigin(bounds.left + bounds.width / 2.0f,
                                       bounds.top + bounds.height / 2.0f);
                        text.setPosition(
                            cell.getPosition().x + tileSize / 2.0f,
                            cell.getPosition().y + tileSize / 2.0f);
                        window.draw(text);
                    }
                }
            }

            sf::Text scorText("Scor: " + std::to_string(joc->getScor()), font,
                              20);
            scorText.setFillColor(sf::Color::Black);
            scorText.setPosition(10, window.getSize().y - 80);
            window.draw(scorText);

            sf::Text usernameText("Utilizator: " + username, font, 20);
            usernameText.setFillColor(sf::Color::Black);
            usernameText.setPosition(10, window.getSize().y - 50);
            window.draw(usernameText);

            window.display();

            if (joc->esteGameOver())
            {
                sf::Text gameOver("Game Over! Apasa ESC pentru a iesi.", font,
                                  24);
                gameOver.setFillColor(sf::Color::Red);
                setTextCenter(gameOver, window.getSize().x / 2.f,
                              window.getSize().y / 2.f);
                window.draw(gameOver);
                window.display();

                bool waitExit = true;
                while (waitExit && window.isOpen())
                {
                    sf::Event ev;
                    while (window.pollEvent(ev))
                    {
                        if (ev.type == sf::Event::Closed)
                            window.close();
                        else if (ev.type == sf::Event::KeyPressed &&
                                 ev.key.code == sf::Keyboard::Escape)
                            waitExit = false;
                    }
                }

                userManager.addScore(username, joc->getScor());
                std::cout << "Salvez scorul " << joc->getScor()
                          << " pentru userul: " << username << std::endl;
                userManager.saveUsersToFile("src/user.txt");
                break;
            }
        }
    }

    return 0;
}
