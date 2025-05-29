#pragma once

#include "Joc2048.h"
#include "Board.h"
#include "Scor.h"

class JocUsor : public Joc2048
{
private:
    static const int dimensiune = 3;
    static const int cod = 2; // Dimensiunea tablei de joc (3x3)

public:
    JocUsor(); 
    Board& getBoard();
    JocUsor(const JocUsor& other) : Joc2048(other) {}// Constructor implicit
    const Board& getBoard() const;
    void mutari(char directie, int cod) override; // Mută blocurile
    bool esteGameOver() const override;  
    void initBoard();        // Verifică dacă jocul s-a terminat
    Joc2048* clone() const override;  
    void afiseaza() const override;           // Constructor virtual
};