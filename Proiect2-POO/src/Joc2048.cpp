
#include "Joc2048.h"
#include "Board.h"
#include "Scor.h"
#include "Timeout.h"
#include <iostream>

Joc2048::Joc2048() {
  
}

void Joc2048::afiseaza() const {
    board.afiseaza();  // Afișează tabla
    std::cout << "Scor: " << scor.getScorCurent() << "\n";  // Afișează scorul
}

void Joc2048::mutari(char directie, int cod) {
    board.muta(directie,cod);
    scor.adauga(4);  
    if (esteGameOver()) {
        std::cout << "Game Over!" << std::endl;
    }

}

bool Joc2048::esteGameOver() const {
    return board.estePlin() && board.esteBlocaje();  
}

Board& Joc2048::getBoard() {
    return board;
}

int Joc2048::getScor() const {
    return scor.getScorCurent(); 
}

