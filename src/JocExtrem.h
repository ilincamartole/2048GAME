#pragma once
#include <array>

#include "Joc2048.h"

#define NR_CADRANE 4

class JocExtrem : public Joc2048
{
    std::array<bool, NR_CADRANE> cadranBlocat;

    int getCadran(int x, int y) const;
    bool toateCadraneleBlocate() const;

   public:
    JocExtrem();

    void mutari(char directie, int cod) override;
    bool esteGameOver() const override;
    void descriere() const override;
    Joc2048* clone() const override;

    void adaugaBlocNou();
};
