#pragma once
// aceasta exceptie avea functionalitate doar cand alegeam modul de joc din
// terminal, inainte de rularea ferestrei sfml, acum nu mai este nevoie de el
// o lasam in cod pentru ca ea este folosita in cazul default din jocfactory,
// care nu se executa niciodata
#include "EroareJoc.h"

class EroareModJocInvalid : public EroareJoc
{
   public:
    EroareModJocInvalid() : EroareJoc("Mod de joc invalid! Alege 1, 2 sau 3.")
    {
    }
};