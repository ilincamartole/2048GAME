#include "JocRandom.h"

#include <iostream>

#include "Board.h"
#include "Scor.h"
void JocRandom::initBoard() { Joc2048::getBoard(); }
JocRandom::JocRandom() : Joc2048() {}

void JocRandom::afiseaza() const
{
    getBoard().afiseaza();
    std::cout << "Scor: " << scor.getScorCurent() << "\n";
}

void JocRandom::mutari(char directie, int cod)
{
    getBoard().muta(directie, cod);

    

    scor.adauga(4);
    if (esteGameOver())
    {
        std::cout << "Game Over!" << std::endl;
    }
}
int JocRandom::getScor() const { return scor.getScorCurent(); }
Board& JocRandom::getBoard() { return Joc2048::getBoard(); }
const Board& JocRandom::getBoard() const { return Joc2048::getBoard(); }
void JocRandom::descriere() const
{
    std::cout << "Acesta este modul Joc Random." << std::endl;
}
Joc2048* JocRandom::clone() const { return new JocRandom(*this); }
