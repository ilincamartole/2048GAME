#include "Scor.h"

Scor::Scor() : scorCurent(0) {}

void Scor::reset() { scorCurent = 0; }

void Scor::adauga(int puncte) { scorCurent += puncte; }

void Scor::salveazaScor()
{
    scoruri.push_back(scorCurent);
    scorCurent = 0;
}

void Scor::afiseazaScoruri() const
{
    std::cout << "Scoruri obtinute:\n";
    for (size_t i = 0; i < scoruri.size(); ++i)
    {
        std::cout << "Scor " << i + 1 << ": " << scoruri[i] << "\n";
    }
}

int Scor::getScorCurent() const { return scorCurent; }

void swap(Scor& first, Scor& second) noexcept
{
    using std::swap;
    swap(first.scorCurent, second.scorCurent);
    swap(first.scoruri, second.scoruri);
}

Scor::Scor(const Scor& other)
    : scorCurent(other.scorCurent), scoruri(other.scoruri)
{
}

Scor& Scor::operator=(Scor other)
{
    swap(*this, other);
    return *this;
}
