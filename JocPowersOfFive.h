#pragma once
#include "Joc2048.h"

class JocPowersOfFive : public Joc2048
{
public:
private:
    static const int DIM = 6;
    JocPowersOfFive(const JocPowersOfFive& other) : Joc2048(other) {}
    static const int cod = 4; // Dimensiunea tablei de joc (6x6)

   public:
    Scor scor;
    JocPowersOfFive();
    Board& getBoard();
    const Board& getBoard() const;

    int getScor() const;
    void initBoard();
    void mutari(char directie, int cod) override;
    void afiseaza() const override;
    friend sf::Color Block::getCuloare() const;

    friend void Board::adaugaBlocRandom();

    friend bool Board::estePlin() const;
    friend bool Board::esteBlocaje() const;
    friend int Board::getValoare(int i, int j) const;
    friend void Board::setValoare(int i, int j, int valoare);
    friend void Board::adaugaBlocRandom();
    void descriere() const override;
    Joc2048* clone() const override;
};