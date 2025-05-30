#include "JocExtrem.h"

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

JocExtrem::JocExtrem() : Joc2048() { cadranBlocat.fill(false); }

int JocExtrem::getCadran(int x, int y) const
{
    int half = getBoard().getDim() / 2;
    if (x < half && y < half) return 0;
    if (x < half && y >= half) return 1;
    if (x >= half && y < half) return 2;
    return 3;
}

void JocExtrem::mutari(char directie, int cod)
{
    Board& board = getBoard();
    int dim = board.getDim();

    if (directie == 'a')
    {
        for (int i = 0; i < dim; ++i)
        {
            int last = 0;
            int lastVal = 0;
            for (int j = 0; j < dim; ++j)
            {
                int cadran = getCadran(i, j);
                if (cadranBlocat[cadran]) continue;
                int val = board[i][j].getValoare();
                if (val == 0) continue;
                board[i][j].setValoare(0);
                if (lastVal == val && last > 0)
                {
                    board[i][last - 1].setValoare(val * 2);
                    lastVal = 0;
                }
                else
                {
                    board[i][last].setValoare(val);
                    lastVal = val;
                    last++;
                }
            }
        }
    }
    else if (directie == 'd')
    {
        for (int i = 0; i < dim; ++i)
        {
            int last = dim - 1;
            int lastVal = 0;
            for (int j = dim - 1; j >= 0; --j)
            {
                int cadran = getCadran(i, j);
                if (cadranBlocat[cadran]) continue;
                int val = board[i][j].getValoare();
                if (val == 0) continue;
                board[i][j].setValoare(0);
                if (lastVal == val && last < dim - 1)
                {
                    board[i][last + 1].setValoare(val * 2);
                    lastVal = 0;
                }
                else
                {
                    board[i][last].setValoare(val);
                    lastVal = val;
                    last--;
                }
            }
        }
    }
    else if (directie == 'w')
    {
        for (int j = 0; j < dim; ++j)
        {
            int last = 0;
            int lastVal = 0;
            for (int i = 0; i < dim; ++i)
            {
                int cadran = getCadran(i, j);
                if (cadranBlocat[cadran]) continue;
                int val = board[i][j].getValoare();
                if (val == 0) continue;
                board[i][j].setValoare(0);
                if (lastVal == val && last > 0)
                {
                    board[last - 1][j].setValoare(val * 2);
                    lastVal = 0;
                }
                else
                {
                    board[last][j].setValoare(val);
                    lastVal = val;
                    last++;
                }
            }
        }
    }
    else if (directie == 's')
    {
        for (int j = 0; j < dim; ++j)
        {
            int last = dim - 1;
            int lastVal = 0;
            for (int i = dim - 1; i >= 0; --i)
            {
                int cadran = getCadran(i, j);
                if (cadranBlocat[cadran]) continue;
                int val = board[i][j].getValoare();
                if (val == 0) continue;
                board[i][j].setValoare(0);
                if (lastVal == val && last < dim - 1)
                {
                    board[last + 1][j].setValoare(val * 2);
                    lastVal = 0;
                }
                else
                {
                    board[last][j].setValoare(val);
                    lastVal = val;
                    last--;
                }
            }
        }
    }

    for (int i = 0; i < dim; ++i)
    {
        for (int j = 0; j < dim; ++j)
        {
            int cadran = getCadran(i, j);
            if (!cadranBlocat[cadran] && board[i][j].getValoare() == 32)
            {
                cadranBlocat[cadran] = true;
                std::cout << "Cadranul " << cadran + 1 << " a fost blocat!"
                          << std::endl;
            }
        }
    }

    adaugaBlocNou();

    if (toateCadraneleBlocate())
    {
        std::cout << "Felicitări! Ai atins 2048 în toate cadranele!"
                  << std::endl;
    }
}

bool JocExtrem::esteGameOver() const
{
    Board const& board = getBoard();
    int dim = board.getDim();

    if (toateCadraneleBlocate()) return true;

    for (int cadran = 0; cadran < NR_CADRANE; ++cadran)
    {
        if (!cadranBlocat[cadran])
        {
            int half = dim / 2;
            int xStart = (cadran < 2) ? 0 : half;
            int yStart = (cadran % 2 == 0) ? 0 : half;
            for (int i = xStart; i < xStart + half; ++i)
            {
                for (int j = yStart; j < yStart + half; ++j)
                {
                    if (i + 1 < xStart + half &&
                        board[i][j].getValoare() ==
                            board[i + 1][j].getValoare())
                        return false;
                    if (j + 1 < yStart + half &&
                        board[i][j].getValoare() ==
                            board[i][j + 1].getValoare())
                        return false;
                }
            }
        }
    }
    return true;
}

void JocExtrem::descriere() const
{
    std::cout << "Modul Extrem: Creează 2048 în fiecare din cele 4 cadrane ale "
                 "tablei. Cadranele se blochează pe rând."
              << std::endl;
}

Joc2048* JocExtrem::clone() const { return new JocExtrem(*this); }

void JocExtrem::adaugaBlocNou()
{
    Board& board = getBoard();
    int dim = board.getDim();
    std::vector<std::pair<int, int>> pozitiiLibere;

    for (int i = 0; i < dim; ++i)
    {
        for (int j = 0; j < dim; ++j)
        {
            int cadran = getCadran(i, j);
            if (!cadranBlocat[cadran] && board[i][j].esteGol())
            {
                pozitiiLibere.emplace_back(i, j);
            }
        }
    }

    if (!pozitiiLibere.empty())
    {
        auto [x, y] = pozitiiLibere[rand() % pozitiiLibere.size()];
        board[x][y].setValoare(2);
    }
}

bool JocExtrem::toateCadraneleBlocate() const
{
    return std::all_of(cadranBlocat.begin(), cadranBlocat.end(),
                       [](bool b) { return b; });
}
