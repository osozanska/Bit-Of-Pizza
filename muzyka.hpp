#ifndef MUZYKA_HPP
#define MUZYKA_HPP
#include "raylib.h"

class Muzyka {
private:
    Music muzyka;
public:
    Muzyka(const char* sciezkaDoPliku);
    void Aktualizuj();
    void Zakonczenie();
};
#endif