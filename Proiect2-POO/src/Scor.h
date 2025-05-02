#pragma once
#include <iostream>

class Scor {
private:
    int scorCurent;

public:
    Scor();
    void reset();
    void adauga(int valoare);
    int getScorCurent() const;
};
