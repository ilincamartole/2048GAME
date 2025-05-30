#pragma once
#include "Block.h"
#include "Board.h"
#include "Joc2048.h"
#include "Scor.h"

class JocRandom : public Joc2048
{
   private:
    static const int DIM = 6;
    JocRandom(const JocRandom& other) : Joc2048(other) {}
    static const int cod = 3;

   public:
    Scor scor;
    JocRandom();
    int getScor() const override;

    Board& getBoard();
    const Board& getBoard() const;

    void initBoard();
    void mutari(char directie, int cod) override;
    void afiseaza() const override;
    friend sf::Color Block<int>::getCuloare() const;

    friend void Board::adaugaBlocRandom();

    friend bool Board::estePlin() const;
    friend bool Board::esteBlocaje() const;
    friend int Board::getValoare(int i, int j) const;
    friend void Board::setValoare(int i, int j, int valoare);
    friend void Board::adaugaBlocRandom();
    void descriere() const override;
    Joc2048* clone() const override;
    bool esteGameOver() const override;
};
