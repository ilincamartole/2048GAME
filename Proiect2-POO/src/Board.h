#pragma once
#include "Block.h"
#include <iostream>

class Board {
private:
    static const int DIM = 6;
    Block board[DIM][DIM];  // Tabla de joc (6x6)
    struct Pozitie {
        int x, y;
    };

    void adaugaBlocNou(); 

    
public:
    Board();  // Constructor pentru a inițializa tabla
    void reset();  // Resetează tabla de joc
    void afiseaza() const;  // Afișează tabla

    void muta(char directie, int cod);
    bool estePlin() const;  // Verifică dacă tabla e plină
    bool esteBlocaje() const;  // Verifică dacă mai sunt mutări posibile
    int getValoare(int i, int j) const;  // Returnează valoarea unui bloc specific pe tabla (pentru a fi folosit în afisare)
    void setValoare(int i, int j, int valoare);  // Setează valoarea unui bloc specific pe tabla (pentru a fi folosit în afisare)
    bool existaMutariPosibile() const;  // Verifică dacă există mutări posibile
    void adaugaBlocRandom();  // Adaugă un bloc nou pe tabla de joc
    void adaugaBlocNouColorat();  // Adaugă un bloc nou pe tabla de joc cu culoare random
    Block* operator[](int index);  // Operatorul [] pentru accesarea blocurilor
   

    

};
