#ifndef KLIENCI_HPP
#define KLIENCI_HPP

#include "raylib.h"

class Klienci {
private:
    int x = 700;
    int y = 0;
    int predkoscY = 2;
    bool czyAktywny = true;
    bool zamowieniePrzyjete = false;
    float czasStart = 0;  
    int czasNaZamowienie = 120;

public:
    Klienci();

    void aktualizuj();                     
    void rysuj();                          
    void sprawdzInterakcje(int graczX, int graczY); 
    int pozostalyCzas();                  
    bool aktywny();                      
};

#endif
