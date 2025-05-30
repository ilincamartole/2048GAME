#pragma once
#include <iostream>
#include <vector>

class Scor
{
   private:
    int scorCurent;
    std::vector<int> scoruri;
    void reset();

   public:
    Scor();

    void adauga(int puncte);

    void salveazaScor();

    void afiseazaScoruri() const;

    int getScorCurent() const;

    friend void swap(Scor &first, Scor &second) noexcept;

    Scor(const Scor &other);

    Scor &operator=(Scor other);
};
