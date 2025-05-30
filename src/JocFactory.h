#pragma once

#include <memory>

#include "EroareModJocInvalid.h"
#include "Joc2048.h"
#include "JocExtrem.h"
#include "JocGreu.h"
#include "JocMultiplesOfFive.h"
#include "JocRandom.h"

class JocFactory
{
   public:
    static std::unique_ptr<Joc2048> createJoc(int optiune)
    {
        switch (optiune)
        {
            case 1:
                return std::make_unique<Joc2048>();
            case 2:
                return std::make_unique<JocGreu>();
            case 3:
                return std::make_unique<JocRandom>();
            case 4:
                return std::make_unique<JocMultiplesOfFive>();
            case 5:
                return std::make_unique<JocExtrem>();
            default:
                throw EroareModJocInvalid();
        }
    }
};
