#include "Board.h"
#include "Block.h"
#include "Scor.h"
#include "Timeout.h"
#include "Joc2048.h"
#include <cstdlib>
#include <ctime>
#include <iostream>


void Board::reset() {
    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j) {
            board[i][j].setValoare(0);  // Resetează toate blocurile la 0
        }
    }
    adaugaBlocRandom();  // Adaugă un bloc nou după resetare
}
// Afișează tabla de joc
void Board::afiseaza() const {
    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j) {
            std::cout << board[i][j].getValoare() << "\t";
        }
        std::cout << "\n";
    }
}

// Adaugă un bloc cu valoarea 2 într-o poziție aleatoare




// Returnează valoarea dintr-un bloc
int Board::getValoare(int i, int j) const {
    return board[i][j].getValoare();
}

// Setează o valoare într-un bloc
void Board::setValoare(int i, int j, int valoare) {
    board[i][j].setValoare(valoare);
}

// Verifică dacă tabla este plină
bool Board::estePlin() const {
    for (int i = 0; i < DIM; ++i)
        for (int j = 0; j < DIM; ++j)
            if (board[i][j].esteGol())
                return false;
    return true;
}

// Verifică dacă mai există mutări posibile
bool Board::esteBlocaje() const {
    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j) {
            if (board[i][j].esteGol()) return false;
            if (i + 1 < DIM && board[i][j].getValoare() == board[i + 1][j].getValoare()) return false;
            if (j + 1 < DIM && board[i][j].getValoare() == board[i][j + 1].getValoare()) return false;
        }
    }
    return true;
}

// Mută blocurile într-o direcție (exemplu de schelet)


Board::Board() {
    std::srand(std::time(nullptr));
    adaugaBlocRandom();
    adaugaBlocRandom();
}

bool Board::existaMutariPosibile() const {
    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j) {
            if (board[i][j].esteGol()) return true;
            if (i + 1 < DIM && board[i][j].getValoare() == board[i + 1][j].getValoare()) return true;
            if (j + 1 < DIM && board[i][j].getValoare() == board[i][j + 1].getValoare()) return true;
        }
    }
    return false;
}
void Board::adaugaBlocRandom() {
    int x, y;
    do {
        x = std::rand() % DIM;
        y = std::rand() % DIM;
    } while (!board[x][y].esteGol());  // Caută o poziție liberă

    board[x][y].setValoare(2);  // Adaugă un bloc cu valoarea 2
}

void Board::adaugaBlocNouColorat() {
    int x, y;
    do {
        x = std::rand() % DIM;
        y = std::rand() % DIM;
    } while (!board[x][y].esteGol());  // Caută o poziție liberă

  
    int r = std::rand() % 256;      int g = std::rand() % 256;  
    int b = std::rand() % 256;  
    board[x][y].setValoare(2);  
    board[x][y].setCuloare(sf::Color(r, g, b));  
}


    Block* Board::operator[](int index) {
        return board[index];  
    }


    void Board::muta(char directie, int cod) {
        if (cod==1){
        if (directie == 'w') {  // Mută în sus
            for (int j = 0; j < DIM; ++j) {
                for (int i = 1; i < DIM; ++i) {
                    if (!board[i][j].esteGol()) {
                        int k = i;
                        while (k > 0 && board[k - 1][j].esteGol()) {
                            // Mută blocul în sus
                            board[k - 1][j].setValoare(board[k][j].getValoare());
                            board[k][j].setValoare(0);
                            k--;
                        }
                        if (k > 0 && board[k - 1][j].getValoare() == board[k][j].getValoare()) {
                            // Fuzionează blocurile
                            board[k - 1][j].dubleaza();
                            board[k][j].setValoare(0);
                        }
                    }
                }
            }
        } else if (directie == 's') {  // Mută în jos
            for (int j = 0; j < DIM; ++j) {
                for (int i = DIM - 2; i >= 0; --i) {
                    if (!board[i][j].esteGol()) {
                        int k = i;
                        while (k < DIM - 1 && board[k + 1][j].esteGol()) {
                            // Mută blocul în jos
                            board[k + 1][j].setValoare(board[k][j].getValoare());
                            board[k][j].setValoare(0);
                            k++;
                        }
                        if (k < DIM - 1 && board[k + 1][j].getValoare() == board[k][j].getValoare()) {
                            // Fuzionează blocurile
                            board[k + 1][j].dubleaza();
                            board[k][j].setValoare(0);
                        }   
                    }
                }
            }
        } else if (directie == 'a') {  
            for (int i = 0; i < DIM; ++i) {
                for (int j = 1; j < DIM; ++j) {
                    if (!board[i][j].esteGol()) {
                        int k = j;
                        while (k > 0 && board[i][k - 1].esteGol()) {
                         
                            board[i][k - 1].setValoare(board[i][k].getValoare());
                            board[i][k].setValoare(0);
                            k--;
                        }
                        if (k > 0 && board[i][k - 1].getValoare() == board[i][k].getValoare()) {
                           
                            board[i][k - 1].dubleaza();
                            board[i][k].setValoare(0);
                        }
                    }
                }
            }
        } else if (directie == 'd') { 
            for (int i = 0; i < DIM; ++i) {
                for (int j = DIM - 2; j >= 0; --j) {
                    if (!board[i][j].esteGol()) {
                        int k = j;
                        while (k < DIM - 1 && board[i][k + 1].esteGol()) {
                         
                            board[i][k + 1].setValoare(board[i][k].getValoare());
                            board[i][k].setValoare(0);
                            k++;
                        }
                        if (k < DIM - 1 && board[i][k + 1].getValoare() == board[i][k].getValoare()) {
                            
                            board[i][k + 1].dubleaza();
                            board[i][k].setValoare(0);
                        }
                    }
                }
            }
        }
        adaugaBlocRandom(); 
     }else if (cod==2){
        if (directie == 'w') { 
                        for (int j = 0; j < DIM; ++j) {
                            for (int i = 1; i < DIM; ++i) {
                                if (!board[i][j].esteGol()) {
                                    int k = i;
                                    while (k > 0 && board[k - 1][j].esteGol()) {
                                       
                                        board[k - 1][j].setValoare(board[k][j].getValoare());
                                        board[k][j].setValoare(0);
                                        k--;
                                    }
                                    if (k > 0 && board[k - 1][j].getValoare() == board[k][j].getValoare() && board[k - 1][j].getCuloare() == board[k][j].getCuloare()) {
                                        
                                        board[k - 1][j].dubleaza();
                                        board[k][j].setValoare(0);
                                    }
                                }
                            }
                        }
                    }
                    else if (directie == 's') {  
                        for (int j = 0; j < DIM; ++j) {
                            for (int i = DIM - 2; i >= 0; --i) {
                                if (!board[i][j].esteGol()) {
                                    int k = i;
                                    while (k < DIM - 1 && board[k + 1][j].esteGol()) {
                                        
                                        board[k + 1][j].setValoare(board[k][j].getValoare());
                                        board[k][j].setValoare(0);
                                        k++;
                                    }
                                    if (k < DIM - 1 && board[k + 1][j].getValoare() == board[k][j].getValoare() && board[k + 1][j].getCuloare() == board[k][j].getCuloare()) {
                                       
                                        board[k + 1][j].dubleaza();
                                        board[k][j].setValoare(0);
                                    }
                                }
                            }
                        }
                    }
                    else if (directie == 'a') {  
                        for (int i = 0; i < DIM; ++i) {
                            for (int j = 1; j < DIM; ++j) {
                                if (!board[i][j].esteGol()) {
                                    int k = j;
                                    while (k > 0 && board[i][k - 1].esteGol()) {
                                       
                                        board[i][k - 1].setValoare(board[i][k].getValoare());
                                        board[i][k].setValoare(0);
                                        k--;
                                    }
                                    if (k > 0 && board[i][k - 1].getValoare() == board[i][k].getValoare() && board[i][k-1].getCuloare() == board[i][k].getCuloare()) {
                                     
                                        board[i][k - 1].dubleaza();
                                        board[i][k].setValoare(0);
                                    }
                                }
                            }
                        }
                    }
                    else if (directie == 'd') {  
                        for (int i = 0; i < DIM; ++i) {
                            for (int j = DIM - 2; j >= 0; --j) {
                                if (!board[i][j].esteGol()) {
                                    int k = j;
                                    while (k < DIM - 1 && board[i][k + 1].esteGol()) {
                                    
                                        board[i][k + 1].setValoare(board[i][k].getValoare());
                                        board[i][k].setValoare(0);
                                        k++;
                                    }
                                    if (k < DIM - 1 && board[i][k + 1].getValoare() == board[i][k].getValoare() && board[i][k+1].getCuloare() == board[i][k].getCuloare()) {
                                       
                                        board[i][k + 1].dubleaza();
                                        board[i][k].setValoare(0);
                                    }
                                }
                            }
                        }
                    }
                
                   
                    adaugaBlocNouColorat();
     } 
    }
    
    
    