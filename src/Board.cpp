#include "Board.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Block.h"
#include "Joc2048.h"
#include "Scor.h"
#include "Utilis.h"

void Board::reset()
{
    for (int i = 0; i < DIM; ++i)
    {
        for (int j = 0; j < DIM; ++j)
        {
            board[i][j].setValoare(0);
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
    } while (!board[x][y].esteGol());

    board[x][y].setValoare(2);
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

Block<int>* Board::operator[](int index) { return board[index]; }
int Board::getDim() const { return DIM; }

void Board::adaugaBlocRandomizer()
{
    int x, y;
    do
    {
        x = std::rand() % DIM;
        y = std::rand() % DIM;
    } while (!board[x][y].esteGol());

    int valoare = 1 + std::rand() % 10;

    if (valoare == 10)
    {
        board[x][y] = Block<int>(10);
        std::cout << "Bloc special adaugat la (" << x << ", " << y
                  << ") cu valoarea 10.\n";
    }
    else
    {
        board[x][y].setValoare(valoare);
        std::cout << "Bloc normal adaugat la (" << x << ", " << y
                  << ") cu valoarea " << valoare << ".\n";
    }
}

void Board::adaugaBlocSpecial()
{
    int x = rand() % DIM;
    int y = rand() % DIM;

    if (board[x][y].esteGol())
    {
        board[x][y] = Block<int>(2);
    }
}

void Board::adaugaBlocOfFive()
{
    int x, y;
    do
    {
        x = rand() % DIM;
        y = rand() % DIM;
    } while (!board[x][y].esteGol());

    board[x][y] = Block<int>(5);
}
const Block<int>* Board::operator[](int index) const { return board[index]; }
void Board::muta(char directie, int cod)
{
    if (cod == 1)
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
                            poateFiCombinat(board[k - 1][j], board[k][j]))

                            if (board[k - 1][j].getCuloare() ==
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
                            poateFiCombinat(board[k + 1][j], board[k][j]))
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
                            poateFiCombinat(board[i][k - 1], board[i][k]))

                            if (board[i][k - 1].getCuloare() ==
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
                            poateFiCombinat(board[i][k + 1], board[i][k]))

                            if (board[i][k + 1].getCuloare() ==
                                board[i][k].getCuloare())
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
                            board[k - 1][j].setValoare(0);
                            board[k][j].setCuloare(board[k][j].getCuloare());
                            k--;
                        }
                        if (k > 0 &&
                            poateFiCombinat(board[k - 1][j], board[k][j]) &&
                            board[k - 1][j].getCuloare() ==
                                board[k][j].getCuloare())
                        {
                            board[k - 1][j].dubleaza();
                            board[k][j].setValoare(0);
                            board[k - 1][j].setCuloare(
                                board[k - 1][j].getCuloare());
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
                            board[k + 1][j].setCuloare(
                                board[k][j].getCuloare());
                            board[k][j].setValoare(0);
                            k++;
                        }
                        if (k < DIM - 1 &&
                            poateFiCombinat(board[k + 1][j], board[k][j]) &&
                            board[k + 1][j].getCuloare() ==
                                board[k][j].getCuloare())
                        {
                            board[k + 1][j].dubleaza();
                            board[k][j].setValoare(0);
                            board[k + 1][j].setCuloare(
                                board[k + 1][j].getCuloare());
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
                            board[i][k - 1].setCuloare(
                                board[i][k].getCuloare());
                            board[i][k].setValoare(0);
                            k--;
                        }
                        if (k > 0 &&
                            poateFiCombinat(board[i][k - 1], board[i][k]) &&
                            board[i][k - 1].getCuloare() ==
                                board[i][k].getCuloare())
                        {
                            board[i][k - 1].dubleaza();
                            board[i][k].setValoare(0);
                            board[i][k - 1].setCuloare(
                                board[i][k - 1].getCuloare());
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
                            board[i][k + 1].setCuloare(
                                board[i][k].getCuloare());
                            board[i][k].setValoare(0);
                            k++;
                        }
                        if (k < DIM - 1 &&
                            poateFiCombinat(board[i][k + 1], board[i][k]) &&
                            board[i][k + 1].getCuloare() ==
                                board[i][k].getCuloare())
                        {
                            board[i][k + 1].dubleaza();
                            board[i][k].setValoare(0);
                            board[i][k + 1].setCuloare(
                                board[i][k + 1].getCuloare());
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
                            poateFiCombinat(board[k + 1][j], board[k][j]))
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
                            poateFiCombinat(board[i][k - 1], board[i][k]))
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
                            poateFiCombinat(board[i][k + 1], board[i][k]))

                        {
                            board[i][k + 1].dubleaza();
                            board[i][k].setValoare(0);
                        }
                    }
                }
            }
        }
        adaugaBlocRandomizer();
    }
    else if (cod == 4)
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
                            poateFiCombinat(board[k - 1][j], board[k][j]))

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
                        if (k < DIM - 1 &&
                            poateFiCombinat(board[k + 1][j], board[k][j]))
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
                            poateFiCombinat(board[i][k - 1], board[i][k]))
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
                            poateFiCombinat(board[i][k + 1], board[i][k]))

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

bool Board::verificaGameOver() const
{
    for (int i = 0; i < DIM; ++i)
        for (int j = 0; j < DIM; ++j)
            if (board[i][j].getValoare() == 2048) return false;

    if (estePlin() && !areMutariPosibile())
    {
        return true;
    }
    return false;
}

bool Board::areMutariPosibile() const
{
    for (int i = 0; i < DIM; ++i)
    {
        for (int j = 0; j < DIM; ++j)
        {
            if (i + 1 < DIM &&
                board[i][j].getValoare() == board[i + 1][j].getValoare())
                return true;
            if (j + 1 < DIM &&
                board[i][j].getValoare() == board[i][j + 1].getValoare())
                return true;
        }
    }
    return false;
}
