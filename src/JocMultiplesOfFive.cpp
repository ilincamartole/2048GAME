#include "JocMultiplesOfFive.h"

#include <iostream>

#include "Board.h"
#include "Scor.h"
void JocMultiplesOfFive::initBoard() { Joc2048::getBoard(); }
JocMultiplesOfFive::JocMultiplesOfFive() : Joc2048() {}

void JocMultiplesOfFive::afiseaza() const
{
    getBoard().afiseaza();
    std::cout << "Scor: " << scor.getScorCurent() << "\n";
}

void JocMultiplesOfFive::mutari(char directie, int cod)
{
    getBoard().muta(directie, cod);

    getBoard().adaugaBlocOfFive();
    scor.adauga(4);
    if (esteGameOver())
    {
        std::cout << "Game Over!" << std::endl;
    }
}
int JocMultiplesOfFive::getScor() const { return scor.getScorCurent(); }
Board& JocMultiplesOfFive::getBoard() { return Joc2048::getBoard(); }
const Board& JocMultiplesOfFive::getBoard() const { return Joc2048::getBoard(); }
void JocMultiplesOfFive::descriere() const
{
    std::cout << "Acesta este modul Joc PowersOfFive." << std::endl;
}
Joc2048* JocMultiplesOfFive::clone() const { return new JocMultiplesOfFive(*this); }

bool JocMultiplesOfFive::esteGameOver() const
{
    return getBoard().estePlin() && !getBoard().areMutariPosibile();
}