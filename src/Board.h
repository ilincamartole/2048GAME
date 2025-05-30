#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Block.h"
#include "BlockSpecial.h"

class Board
{
   private:
    static const int DIM = 6;
    Block<int> board[DIM][DIM];
    struct Pozitie
    {
        int x, y;
    };

    void adaugaBlocNou();

   public:
    int getDim() const;
    Board();                        // Constructor pentru a initializa tabla
    void reset();                   // Reseteaza tabla de joc
    void afiseaza() const;          // Afisează tabla
    bool verificaGameOver() const;  // Verifica dacă jocul s-a terminat
    void muta(char directie, int cod);
    sf::Color getCuloare(int i, int j) const;  // Returneaza culoarea blocului
    bool estePlin() const;
    bool areMutariPosibile() const;  // Verifica dacă tabla e plina
    bool esteBlocaje() const;        // Verifica dacă mai sunt mutari posibile
    int getValoare(int i,
                   int j) const;  // Returneaza valoarea unui bloc specific pe
                                  // tabla (pentru a fi folosit în afisare)
    void setValoare(int i, int j,
                    int valoare);  // Setează valoarea unui bloc specific pe
                                   // tabla (pentru a fi folosit în afisare)
    void adaugaBlocRandom();       // Adaugă un bloc nou pe tabla de joc
    void adaugaBlocRandomizer();   // Adaugă un bloc random pe tabla de joc
    void adaugaBlocNouColorat();   // Adaugă un bloc nou pe tabla de joc cu
                                   // culoare random
    void adaugaBlocOfFive();       // Adaugă un bloc special pe tabla
    void adaugaBlocSpecial();      // Adaugă un bloc special pe tabla
    Block<int>* operator[](
        int index);  // Operatorul [] pentru accesarea blocurilor
    const Block<int>* operator[](int index) const;
    // Returnează culoarea blocului
};
