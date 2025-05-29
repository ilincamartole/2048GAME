#include "Board.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Block.h"
#include "Joc2048.h"
#include "Scor.h"

void Board::reset()
{
    for (int i = 0; i < DIM; ++i)
    {
        for (int j = 0; j < DIM; ++j)
        {
            board[i][j].setValoare(0);  // Resetează toate blocurile la 0
        }
    }
    adaugaBlocRandom();
}

void Board::afiseaza() const
{
    for (int i = 0; i < DIM; ++i)
    {
        for (int j = 0; j < DIM; ++j)
        {
            std::cout << board[i][j].getValoare() << "\t";
        }
        std::cout << "\n";
    }
}

int Board::getValoare(int i, int j) const { return board[i][j].getValoare(); }

void Board::setValoare(int i, int j, int valoare)
{
    board[i][j].setValoare(valoare);
}

bool Board::estePlin() const
{
    for (int i = 0; i < DIM; ++i)
        for (int j = 0; j < DIM; ++j)
            if (board[i][j].esteGol()) return false;
    return true;
}

bool Board::esteBlocaje() const
{
    for (int i = 0; i < DIM; ++i)
    {
        for (int j = 0; j < DIM; ++j)
        {
            if (board[i][j].esteGol()) return false;
            if (i + 1 < DIM &&
                board[i][j].getValoare() == board[i + 1][j].getValoare())
                return false;
            if (j + 1 < DIM &&
                board[i][j].getValoare() == board[i][j + 1].getValoare())
                return false;
        }
    }
    return true;
}

Board::Board()
{
    std::srand(std::time(nullptr));
    adaugaBlocRandom();
    adaugaBlocRandom();
}

void Board::adaugaBlocRandom()
{
    int x, y;
    do
    {
        x = std::rand() % DIM;
        y = std::rand() % DIM;
    } while (!board[x][y].esteGol());  // Caută o poziție liberă

    board[x][y].setValoare(2);  // Adaugă un bloc cu valoarea 2
}

void Board::adaugaBlocNouColorat()
{
    int x, y;
    do
    {
        x = std::rand() % DIM;
        y = std::rand() % DIM;
    } while (!board[x][y].esteGol());

    int r = std::rand() % 256;
    int g = std::rand() % 256;
    int b = std::rand() % 256;
    board[x][y].setValoare(2);
    board[x][y].setCuloare(sf::Color(r, g, b));
}
sf::Color Board::getCuloare(int i, int j) const
{
    return board[i][j].getCuloare();
}  

Block* Board::operator[](int index) { return board[index]; }

void Board::adaugaBlocRandomizer()
{
    int x, y;
    do
    {
        x = std::rand() % DIM;
        y = std::rand() % DIM;
    } while (!board[x][y].esteGol());

    int valoare = 1 + std::rand() % 10; // Valoare între 1 și 10

    if (valoare == 10)
    {
        // Creează un bloc special dacă valoarea este 10
        board[x][y] = BlockSpecial(valoare, true);
        std::cout << "Bloc special adaugat la (" << x << ", " << y << ") cu valoarea 10.\n";
    }
    else
    {
        // Creează un bloc normal
        board[x][y].setValoare(valoare);
        std::cout << "Bloc normal adaugat la (" << x << ", " << y << ") cu valoarea " << valoare << ".\n";
    }
}

void Board::adaugaBlocSpecial()
{
    int x = rand() % DIM;
    int y = rand() % DIM;

    if (board[x][y].esteGol())
    {
        board[x][y] = BlockSpecial(2, true);
    }
}

void Board::adaugaBlocOfFive()
{
    int x = rand() % DIM;
    int y = rand() % DIM;

    if (board[x][y].esteGol())
    {
        board[x][y] = BlockSpecial(5, true);
    }
}

void Board::muta(char directie, int cod)
{
    if (cod == 1)
    {
        if (directie == 'w')
        {  // Mută în sus
            for (int j = 0; j < DIM; ++j)
            {
                for (int i = 1; i < DIM; ++i)
                {
                    if (!board[i][j].esteGol())
                    {
                        int k = i;
                        while (k > 0 && board[k - 1][j].esteGol())
                        {
                            board[k - 1][j].setValoare(
                                board[k][j].getValoare());
                            board[k][j].setValoare(0);
                            k--;
                        }
                        if (k > 0 && board[k - 1][j].getValoare() ==
                                         board[k][j].getValoare())
                        {
                            // Fuzionează blocurile
                            board[k - 1][j].dubleaza();
                            board[k][j].setValoare(0);
                        }
                    }
                }
            }
        }
        else if (directie == 's')
        {  // Mută în jos
            for (int j = 0; j < DIM; ++j)
            {
                for (int i = DIM - 2; i >= 0; --i)
                {
                    if (!board[i][j].esteGol())
                    {
                        int k = i;
                        while (k < DIM - 1 && board[k + 1][j].esteGol())
                        {
                            board[k + 1][j].setValoare(
                                board[k][j].getValoare());
                            board[k][j].setValoare(0);
                            k++;
                        }
                        if (k < DIM - 1 && board[k + 1][j].getValoare() ==
                                               board[k][j].getValoare())
                        {
                            board[k + 1][j].dubleaza();
                            board[k][j].setValoare(0);
                        }
                    }
                }
            }
        }
        else if (directie == 'a')
        {
            for (int i = 0; i < DIM; ++i)
            {
                for (int j = 1; j < DIM; ++j)
                {
                    if (!board[i][j].esteGol())
                    {
                        int k = j;
                        while (k > 0 && board[i][k - 1].esteGol())
                        {
                            board[i][k - 1].setValoare(
                                board[i][k].getValoare());
                            board[i][k].setValoare(0);
                            k--;
                        }
                        if (k > 0 && board[i][k - 1].getValoare() ==
                                         board[i][k].getValoare())
                        {
                            board[i][k - 1].dubleaza();
                            board[i][k].setValoare(0);
                        }
                    }
                }
            }
        }
        else if (directie == 'd')
        {
            for (int i = 0; i < DIM; ++i)
            {
                for (int j = DIM - 2; j >= 0; --j)
                {
                    if (!board[i][j].esteGol())
                    {
                        int k = j;
                        while (k < DIM - 1 && board[i][k + 1].esteGol())
                        {
                            board[i][k + 1].setValoare(
                                board[i][k].getValoare());
                            board[i][k].setValoare(0);
                            k++;
                        }
                        if (k < DIM - 1 && board[i][k + 1].getValoare() ==
                                               board[i][k].getValoare())
                        {
                            board[i][k + 1].dubleaza();
                            board[i][k].setValoare(0);
                        }
                    }
                }
            }
        }
        adaugaBlocRandom();
    }
    else if (cod == 2)
    {
        if (directie == 'w')
        {
            for (int j = 0; j < DIM; ++j)
            {
                for (int i = 1; i < DIM; ++i)
                {
                    if (!board[i][j].esteGol())
                    {
                        int k = i;
                        while (k > 0 && board[k - 1][j].esteGol())
                        {
                            board[k - 1][j].setValoare(
                                board[k][j].getValoare());
                            board[k][j].setValoare(0);
                            k--;
                        }
                        if (k > 0 &&
                            board[k - 1][j].getValoare() ==
                                board[k][j].getValoare() &&
                            board[k - 1][j].getCuloare() ==
                                board[k][j].getCuloare())
                        {
                            board[k - 1][j].dubleaza();
                            board[k][j].setValoare(0);
                        }
                    }
                }
            }
        }
        else if (directie == 's')
        {
            for (int j = 0; j < DIM; ++j)
            {
                for (int i = DIM - 2; i >= 0; --i)
                {
                    if (!board[i][j].esteGol())
                    {
                        int k = i;
                        while (k < DIM - 1 && board[k + 1][j].esteGol())
                        {
                            board[k + 1][j].setValoare(
                                board[k][j].getValoare());
                            board[k][j].setValoare(0);
                            k++;
                        }
                        if (k < DIM - 1 &&
                            board[k + 1][j].getValoare() ==
                                board[k][j].getValoare() &&
                            board[k + 1][j].getCuloare() ==
                                board[k][j].getCuloare())
                        {
                            board[k + 1][j].dubleaza();
                            board[k][j].setValoare(0);
                        }
                    }
                }
            }
        }
        else if (directie == 'a')
        {
            for (int i = 0; i < DIM; ++i)
            {
                for (int j = 1; j < DIM; ++j)
                {
                    if (!board[i][j].esteGol())
                    {
                        int k = j;
                        while (k > 0 && board[i][k - 1].esteGol())
                        {
                            board[i][k - 1].setValoare(
                                board[i][k].getValoare());
                            board[i][k].setValoare(0);
                            k--;
                        }
                        if (k > 0 &&
                            board[i][k - 1].getValoare() ==
                                board[i][k].getValoare() &&
                            board[i][k - 1].getCuloare() ==
                                board[i][k].getCuloare())
                        {
                            board[i][k - 1].dubleaza();
                            board[i][k].setValoare(0);
                        }
                    }
                }
            }
        }
        else if (directie == 'd')
        {
            for (int i = 0; i < DIM; ++i)
            {
                for (int j = DIM - 2; j >= 0; --j)
                {
                    if (!board[i][j].esteGol())
                    {
                        int k = j;
                        while (k < DIM - 1 && board[i][k + 1].esteGol())
                        {
                            board[i][k + 1].setValoare(
                                board[i][k].getValoare());
                            board[i][k].setValoare(0);
                            k++;
                        }
                        if (k < DIM - 1 &&
                            board[i][k + 1].getValoare() ==
                                board[i][k].getValoare() &&
                            board[i][k + 1].getCuloare() ==
                                board[i][k].getCuloare())
                        {
                            board[i][k + 1].dubleaza();
                            board[i][k].setValoare(0);
                        }
                    }
                }
            }
        }

        adaugaBlocNouColorat();
    }
    else if (cod == 3)
    {
        if (directie == 'w')
        {
            for (int j = 0; j < DIM; ++j)
            {
                for (int i = 1; i < DIM; ++i)
                {
                    if (!board[i][j].esteGol())
                    {
                        int k = i;
                        while (k > 0 && board[k - 1][j].esteGol())
                        {
                            board[k - 1][j].setValoare(
                                board[k][j].getValoare());
                            board[k][j].setValoare(0);
                            k--;
                        }
                        if (k > 0 && board[k - 1][j].getValoare() ==
                                         board[k][j].getValoare())
                        {
                            board[k - 1][j].dubleaza();
                            board[k][j].setValoare(0);
                        }
                    }
                }
            }
            std::cout << "Mutare in sus\n";
        }
        else if (directie == 's')
        {
            for (int j = 0; j < DIM; ++j)
            {
                for (int i = DIM - 2; i >= 0; --i)
                {
                    if (!board[i][j].esteGol())
                    {
                        int k = i;
                        while (k < DIM - 1 && board[k + 1][j].esteGol())
                        {
                            board[k + 1][j].setValoare(
                                board[k][j].getValoare());
                            board[k][j].setValoare(0);
                            k++;
                        }
                        if (k < DIM - 1 && board[k + 1][j].getValoare() ==
                                               board[k][j].getValoare())
                        {
                            board[k + 1][j].dubleaza();
                            board[k][j].setValoare(0);
                        }
                    }
                }
            }
        }
        else if (directie == 'a')
        {
            for (int i = 0; i < DIM; ++i)
            {
                for (int j = 1; j < DIM; ++j)
                {
                    if (!board[i][j].esteGol())
                    {
                        int k = j;
                        while (k > 0 && board[i][k - 1].esteGol())
                        {
                            board[i][k - 1].setValoare(
                                board[i][k].getValoare());
                            board[i][k].setValoare(0);
                            k--;
                        }
                        if (k > 0 && board[i][k - 1].getValoare() ==
                                         board[i][k].getValoare())
                        {
                            // Fuzionează blocurile
                            board[i][k - 1].dubleaza();
                            board[i][k].setValoare(0);
                        }
                    }
                }
            }
        }
        else if (directie == 'd')
        {
            for (int i = 0; i < DIM; ++i)
            {
                for (int j = DIM - 2; j >= 0; --j)
                {
                    if (!board[i][j].esteGol())
                    {
                        int k = j;
                        while (k < DIM - 1 && board[i][k + 1].esteGol())
                        {
                            board[i][k + 1].setValoare(
                                board[i][k].getValoare());
                            board[i][k].setValoare(0);
                            k++;
                        }
                        if (k < DIM - 1 && board[i][k + 1].getValoare() ==
                                               board[i][k].getValoare())
                        {
                            board[i][k + 1].dubleaza();
                            board[i][k].setValoare(0);
                        }
                    }
                }
            }
        }
        adaugaBlocRandomizer();
    }   else if (cod == 4)
    {
        if (directie == 'w')
        {
            for (int j = 0; j < DIM; ++j)
            {
                for (int i = 1; i < DIM; ++i)
                {
                    if (!board[i][j].esteGol())
                    {
                        int k = i;
                        while (k > 0 && board[k - 1][j].esteGol())
                        {
                            board[k - 1][j].setValoare(
                                board[k][j].getValoare());
                            board[k][j].setValoare(0);
                            k--;
                        }
                        if (k > 0 && board[k - 1][j].getValoare() ==
                                         board[k][j].getValoare())
                        {
                            board[k - 1][j].dubleaza();
                            board[k][j].setValoare(0);
                        }
                    }
                }
            }
            std::cout << "Mutare in sus\n";
        }
        else if (directie == 's')
        {
            for (int j = 0; j < DIM; ++j)
            {
                for (int i = DIM - 2; i >= 0; --i)
                {
                    if (!board[i][j].esteGol())
                    {
                        int k = i;
                        while (k < DIM - 1 && board[k + 1][j].esteGol())
                        {
                            board[k + 1][j].setValoare(
                                board[k][j].getValoare());
                            board[k][j].setValoare(0);
                            k++;
                        }
                        if (k < DIM - 1 && board[k + 1][j].getValoare() ==
                                               board[k][j].getValoare())
                        {
                            board[k + 1][j].dubleaza();
                            board[k][j].setValoare(0);
                        }
                    }
                }
            }
        }
        else if (directie == 'a')
        {
            for (int i = 0; i < DIM; ++i)
            {
                for (int j = 1; j < DIM; ++j)
                {
                    if (!board[i][j].esteGol())
                    {
                        int k = j;
                        while (k > 0 && board[i][k - 1].esteGol())
                        {
                            board[i][k - 1].setValoare(
                                board[i][k].getValoare());
                            board[i][k].setValoare(0);
                            k--;
                        }
                        if (k > 0 && board[i][k - 1].getValoare() ==
                                         board[i][k].getValoare())
                        {
                            // Fuzionează blocurile
                            board[i][k - 1].dubleaza();
                            board[i][k].setValoare(0);
                        }
                    }
                }
            }
        }
        else if (directie == 'd')
        {
            for (int i = 0; i < DIM; ++i)
            {
                for (int j = DIM - 2; j >= 0; --j)
                {
                    if (!board[i][j].esteGol())
                    {
                        int k = j;
                        while (k < DIM - 1 && board[i][k + 1].esteGol())
                        {
                            board[i][k + 1].setValoare(
                                board[i][k].getValoare());
                            board[i][k].setValoare(0);
                            k++;
                        }
                        if (k < DIM - 1 && board[i][k + 1].getValoare() ==
                                               board[i][k].getValoare())
                        {
                            board[i][k + 1].dubleaza();
                            board[i][k].setValoare(0);
                        }
                    }
                }
            }
        }
        adaugaBlocOfFive();
    }
}


void Board::verificaGameOver() const
{
    // Verifică dacă există un bloc cu valoarea 2048
    for (int i = 0; i < DIM; ++i)
    {
        for (int j = 0; j < DIM; ++j)
        {
            if (board[i][j].getValoare() == 2048)
            {
                std::cout << "Felicitari! Ai castigat!" << std::endl;
                return;
            }
        }
    }

    // Verifică dacă tabla este plină și nu mai există mutări posibile
    if (estePlin())
    {
        std::cout << "Ai pierdut!" << std::endl;
        return;
    }
}
