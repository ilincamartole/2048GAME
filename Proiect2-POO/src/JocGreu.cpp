#include "JocGreu.h"
#include "Board.h"
#include "Scor.h"

void JocGreu::initBoard() {
    Joc2048::getBoard();
   
}

void JocGreu::afiseaza() const {

    board.afiseaza();
    std::cout << "Scor: " << scor.getScorCurent() << "\n";  // Afișează scorul
}


bool JocGreu::esteGameOver() const {
    return board.estePlin() && board.esteBlocaje();  // Dacă tabla e plină și nu se mai pot face mutări, jocul se încheie
 
}
void JocGreu::mutari(char directie, int cod) {
   
    board.muta(directie, cod);  // Mută blocurile pe tablă
    scor.adauga(4);  
    if (esteGameOver()) {
        std::cout << "Game Over!" << std::endl;
    }
}


