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
