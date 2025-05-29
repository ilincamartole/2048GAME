#pragma once
#include "EroareJoc.h"

class EroareFereastra : public EroareJoc
{
public:
    EroareFereastra()
        : EroareJoc("Nu s-a putut deschide fereastra SFML!")
    {
    }
};