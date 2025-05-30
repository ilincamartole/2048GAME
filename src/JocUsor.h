#pragma once

#include "Board.h"
#include "Joc2048.h"
#include "Scor.h"

class JocUsor : public Joc2048
{
   private:
    static const int dimensiune = 3;
    static const int cod = 2;

   public:
    JocUsor();
    Board& getBoard();
    JocUsor(const JocUsor& other) : Joc2048(other) {}
    const Board& getBoard() const;
    void mutari(char directie, int cod) override;
    bool esteGameOver() const override;
    void initBoard();
    Joc2048* clone() const override;
    void afiseaza() const override;
};