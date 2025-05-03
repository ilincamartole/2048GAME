#pragma once
#include <exception>
#include <string>

class EroareJoc : public std::exception
{
   protected:
    std::string mesaj;

   public:
    explicit EroareJoc(const std::string& msg) : mesaj(msg) {}
    const char* what() const noexcept override { return mesaj.c_str(); }
};

class EroareModJocInvalid : public EroareJoc
{
   public:
    EroareModJocInvalid() : EroareJoc("Mod de joc invalid! Alege 1, 2 sau 3.")
    {
    }
};

class EroareFont : public EroareJoc
{
   public:
    EroareFont()
        : EroareJoc("Nu s-a putut incarca fontul din fisierul happy-kids.ttf!")
    {
    }
};

class EroareFereastra : public EroareJoc
{
   public:
    EroareFereastra() : EroareJoc("Nu s-a putut deschide fereastra SFML!") {}
};