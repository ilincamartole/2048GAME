#include "JocPowersOfFive.h"

#include <iostream>

#include "Board.h"
#include "Scor.h"
void JocPowersOfFive::initBoard() { Joc2048::getBoard(); }
JocPowersOfFive::JocPowersOfFive() : Joc2048() {}

void JocPowersOfFive::afiseaza() const
{
    getBoard().afiseaza();
    std::cout << "Scor: " << scor.getScorCurent() << "\n";
}

void JocPowersOfFive::mutari(char directie, int cod)
{
    getBoard().muta(directie, cod);

    getBoard().adaugaBlocOfFive();  // Adaugă un bloc special cu o probabilitate de 10%
    scor.adauga(4);
    if (esteGameOver())
    {
        std::cout << "Game Over!" << std::endl;
    }
}
int JocPowersOfFive::getScor() const { return scor.getScorCurent(); }
Board& JocPowersOfFive::getBoard() { return Joc2048::getBoard(); }
const Board& JocPowersOfFive::getBoard() const { return Joc2048::getBoard(); }
void JocPowersOfFive::descriere() const
{
    std::cout << "Acesta este modul Joc PowersOfFive." << std::endl;
}
Joc2048* JocPowersOfFive::clone() const { return new JocPowersOfFive(*this); }
