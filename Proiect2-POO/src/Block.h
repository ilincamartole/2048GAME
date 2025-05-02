#pragma once
#include <SFML/Graphics.hpp>  // Include pentru a folosi SFML

class Block {
private:
    int valoare;
    sf::Color culoare;

public:
    Block();  // Constructor implicit
    Block(int v);  // Constructor cu valoare specifică

    int getValoare() const;  // Returnează valoarea blocului
    void setValoare(int v);  // Setează valoarea blocului

    bool esteGol() const;  // Verifică dacă blocul este gol (valoare 0)
    void dubleaza();  // Dublează valoarea blocului
    void setCuloare(const sf::Color& nouaCuloare);  // Setează culoarea blocului
    sf::Color getCuloare() const;  // Returnează culoarea blocului

  
};

