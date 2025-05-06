#ifndef KLIENCI_HPP
#define KLIENCI_HPP

#include "raylib.h"

class Klienci {
private:
    int x;
    int y;
    int predkoscY;
    bool czyAktywny;
    bool zamowieniePrzyjete;
    float czasStart; 
    int czasNaZamowienie;
    Texture2D klient;

public:
    Klienci(); 
    Klienci(int x, int y, int predkoscY, int czasNaZamowienie); 

    void aktualizuj();                     
    void rysuj();                          
    void sprawdzInterakcje(int graczX, int graczY); 
    int pozostalyCzas();                  
    bool aktywny();              
};

#endif
