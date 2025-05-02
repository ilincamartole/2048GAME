#ifndef JOC2048_H
#define JOC2048_H
#include "Board.h"
#include "Scor.h"
#include "Timeout.h"

class Joc2048 {
private:
    Board board;
    Scor scor;
    Timeout timer;
public:
    Joc2048(); 
    virtual void afiseaza() const;
    virtual bool esteGameOver() const;
    virtual ~Joc2048() {}
    Board& getBoard(); 
    virtual int getScor() const;
    virtual void mutari(char directie, int cod); // Mută blocurile pe tabla de joc
    
    friend bool Board:: estePlin() const;  // Verifică dacă tabla e plină
    friend bool Board::esteBlocaje() const;  // Verifică dacă mai sunt mutări posibile
    friend int Board::getValoare(int i, int j) const;  // Returnează valoarea unui bloc specific pe tabla (pentru a fi folosit în afisare)
    friend void Board::setValoare(int i, int j, int valoare);  // Setează valoarea unui bloc specific pe tabla (pentru a fi folosit în afisare)
    friend bool Board::existaMutariPosibile() const;  // Verifică dacă există mutări posibile
    friend void Board::adaugaBlocRandom();  // Adaugă un bloc nou pe tabla de joc
    

};


#endif 
