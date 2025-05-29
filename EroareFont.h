#pragma once
#include "EroareJoc.h"

class EroareFont : public EroareJoc
{
public:
    EroareFont()
        : EroareJoc("Nu s-a putut incarca fontul din fisierul happy-kids.ttf!")
    {
    }
};