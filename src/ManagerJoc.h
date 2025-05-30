#pragma once
#include "Joc2048.h"

class ManagerJoc
{
   private:
    Joc2048* joc;

   public:
    explicit ManagerJoc(Joc2048* jocNou) : joc(jocNou) {}
    ~ManagerJoc() { delete joc; }

    void descriereJoc() const { joc->descriere(); }
};