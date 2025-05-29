#pragma once
#include "EroareJoc.h"

class EroareModJocInvalid : public EroareJoc
{
public:
    EroareModJocInvalid()
        : EroareJoc("Mod de joc invalid! Alege 1, 2 sau 3.")
    {
    }
};