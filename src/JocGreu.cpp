#include "JocGreu.h"

#include "Board.h"
#include "Scor.h"

void JocGreu::initBoard() { Joc2048::getBoard(); }
JocGreu::JocGreu() : Joc2048() {}

void JocGreu::afiseaza() const
{
    getBoard().afiseaza();
    std::cout << "Scor: " << scor.getScorCurent() << "\n";
}
int JocGreu::getScor() const { return scor.getScorCurent(); }

void JocGreu::mutari(char directie, int cod)
{
    getBoard().muta(directie, cod);
    scor.adauga(4);
    if (esteGameOver())
    {
        std::cout << "Game Over!" << std::endl;
    }
}

Board& JocGreu::getBoard() { return Joc2048::getBoard(); }
const Board& JocGreu::getBoard() const { return Joc2048::getBoard(); }

void JocGreu::descriere() const
{
    std::cout << "Acesta este modul Joc Greu." << std::endl;
}

Joc2048* JocGreu::clone() const { return new JocGreu(*this); }

bool JocGreu::esteGameOver() const
{
    return board.estePlin() && !board.areMutariPosibile();
}