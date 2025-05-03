#include "Joc2048.h"

#include <iostream>

#include "Board.h"
#include "Scor.h"

int Joc2048::numarJocuri = 0;

Joc2048::Joc2048() {}
Joc2048::~Joc2048() {}

void Joc2048::afiseaza() const
{
    board.afiseaza();
    std::cout << "Scor: " << scor.getScorCurent() << "\n";
}

void Joc2048::mutari(char directie, int cod)
{
    board.muta(directie, cod);
    scor.adauga(4);
    board.verificaGameOver();
}

bool Joc2048::esteGameOver() const
{
    return board.estePlin() && board.esteBlocaje();
}

Board& Joc2048::getBoard() { return board; }

const Board& Joc2048::getBoard() const { return board; }
void Joc2048::descriere() const
{
    std::cout << "Acesta este modul Joc Clasic." << std::endl;
}

Joc2048* Joc2048::clone() const { return new Joc2048(*this); }
Scor& Joc2048::getScor() { return scor; }
const Scor& Joc2048::getScor() const { return scor; }
