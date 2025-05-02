#ifndef JOCGREU_H
#define JOCGREU_H

#include "Joc2048.h"
#include "Board.h"
#include "Scor.h"
#include "Block.h"

class JocGreu : public Joc2048 {
    private:
    static const int DIM = 6;
    
    Board board;
    static const int cod=2;

public:
    Scor scor;
    JocGreu() : Joc2048() {}
    void initBoard() ;
    void mutari(char directie,int cod) override;
    void afiseaza() const override; // Afișează tabla de joc
    bool esteGameOver() const override;
    friend sf::Color Block::getCuloare() const;  // Returnează culoarea blocului
    void adaugaBlocNouColorat();   // Adaugă un bloc nou pe tabla de joc
    friend void Board::adaugaBlocRandom();  // Adaugă un bloc nou pe tabla de joc
    friend int Joc2048:: getScor() const;
    friend bool Board:: estePlin() const;  // Verifică dacă tabla e plină
    friend bool Board::esteBlocaje() const;  // Verifică dacă mai sunt mutări posibile
    friend int Board::getValoare(int i, int j) const;  // Returnează valoarea unui bloc specific pe tabla (pentru a fi folosit în afisare)
    friend void Board::setValoare(int i, int j, int valoare);  // Setează valoarea unui bloc specific pe tabla (pentru a fi folosit în afisare)
    friend bool Board::existaMutariPosibile() const;  // Verifică dacă există mutări posibile
    friend void Board::adaugaBlocRandom();  // Adaugă un bloc nou pe tabla de joc
    
};

#endif 
