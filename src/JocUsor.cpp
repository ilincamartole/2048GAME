#include "JocUsor.h"

#include <iostream>

#include "Board.h"

void JocUsor::initBoard() { Joc2048::getBoard(); }
JocUsor::JocUsor() : Joc2048() {}
void JocUsor::mutari(char directie, int cod)
{
    getBoard().muta(directie, cod);
    scor.adauga(4);
    if (esteGameOver())
    {
        std::cout << "Game Over!" << std::endl;
    }
}

bool JocUsor::esteGameOver() const
{
    return getBoard().estePlin() && getBoard().esteBlocaje();
}

void JocUsor::afiseaza() const
{
    getBoard().afiseaza();
    std::cout << "Scor: " << scor.getScorCurent() << "\n";
}

Joc2048* JocUsor::clone() const { return new JocUsor(*this); }