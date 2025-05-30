#pragma once
#include "Joc2048.h"

class JocMultiplesOfFive : public Joc2048
{
   public:
   private:
    static const int DIM = 6;
    JocMultiplesOfFive(const JocMultiplesOfFive& other) : Joc2048(other) {}
    static const int cod = 4;

   public:
    Scor scor;
    JocMultiplesOfFive();
    Board& getBoard();
    int getScor() const override;

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