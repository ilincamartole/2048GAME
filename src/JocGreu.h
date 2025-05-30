#pragma once

#include "Block.h"
#include "Board.h"
#include "Joc2048.h"
#include "Scor.h"

class JocGreu : public Joc2048
{
   private:
    static const int DIM = 6;
    static const int cod = 2;

   public:
    JocGreu(const JocGreu& other) : Joc2048(other) {}

    Scor scor;
    JocGreu();
    Board& getBoard();
    const Board& getBoard() const;
    void initBoard();
    int getScor() const override;
    void mutari(char directie, int cod) override;
    void afiseaza() const override;
    friend sf::Color Block<int>::getCuloare() const;
    void adaugaBlocNouColorat();
    friend void Board::adaugaBlocRandom();
    bool esteGameOver() const override;
    friend bool Board::estePlin() const;
    friend bool Board::esteBlocaje() const;
    friend int Board::getValoare(int i, int j) const;
    friend void Board::setValoare(int i, int j, int valoare);
    friend void Board::adaugaBlocRandom();
    void descriere() const override;
    Joc2048* clone() const override;
};
