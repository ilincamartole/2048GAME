#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Block.h"
#include "BlockSpecial.h"

class Board
{
   private:
    static const int DIM = 4;
    Block board[DIM][DIM];
    struct Pozitie
    {
        int x, y;
    };

    void adaugaBlocNou();

   public:
    Board();                        // Constructor pentru a inițializa tabla
    void reset();                   // Resetează tabla de joc
    void afiseaza() const;          // Afișează tabla
    void verificaGameOver() const;  // Verifică dacă jocul s-a terminat
    void muta(char directie, int cod);
    sf::Color getCuloare(int i, int j) const;  // Returnează culoarea blocului
    bool estePlin() const;                     // Verifică dacă tabla e plină
    bool esteBlocaje() const;  // Verifică dacă mai sunt mutări posibile
    int getValoare(int i,
                   int j) const;  // Returnează valoarea unui bloc specific pe
                                  // tabla (pentru a fi folosit în afisare)
    void setValoare(int i, int j,
                    int valoare);  // Setează valoarea unui bloc specific pe
                                   // tabla (pentru a fi folosit în afisare)
    void adaugaBlocRandom();       // Adaugă un bloc nou pe tabla de joc
    void adaugaBlocRandomizer();   // Adaugă un bloc random pe tabla de joc
    void adaugaBlocNouColorat();   // Adaugă un bloc nou pe tabla de joc cu
                                   // culoare random
    void adaugaBlocOfFive();       // Adaugă un bloc special pe tablă
    void adaugaBlocSpecial();      // Adaugă un bloc special pe tablă
    Block* operator[](int index);  // Operatorul [] pentru accesarea blocurilor
                                   // Returnează culoarea blocului
};
