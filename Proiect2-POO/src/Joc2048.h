#ifndef JOC2048_H
#define JOC2048_H

#include "Board.h"
#include "Scor.h"

class Joc2048
{
   private:
    Board board;
    static int numarJocuri;

   public:
    Joc2048(const Joc2048& other) : board(other.board), scor(other.scor) {}

    Scor scor;
    Scor& getScor();

    const Scor& getScor() const;
    Joc2048();
    virtual ~Joc2048();

    virtual void afiseaza() const;
    virtual bool esteGameOver() const;
    virtual void descriere() const;
    virtual Joc2048* clone() const;
    virtual void mutari(char directie, int cod);
    Board& getBoard();
    const Board& getBoard() const;  // Returnează referința la tabla de joc

    static int getNumarJocuri() { return numarJocuri; }

    friend bool Board::estePlin() const;
    friend bool Board::esteBlocaje() const;
    friend int Board::getValoare(int i, int j) const;
    friend void Board::setValoare(int i, int j, int valoare);
    friend void Board::adaugaBlocRandom();
};

#endif
