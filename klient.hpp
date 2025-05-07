#ifndef KLIENCI_HPP
#define KLIENCI_HPP
#include <iostream>
#include <string>
using namespace std;

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
    int zamowionaPizzaID;
    bool pizzaDodana;
    bool sosDodany;
    bool serDodany;
    bool pieczarkiDodane; 
    bool cebulaDodana;
    bool peperoniDodane;
    bool piecPizzaDodane;
    bool czyOddana;
    Texture2D klient;

public:
    Klienci(); 
    Klienci(int x, int y, int predkoscY, int czasNaZamowienie, int zamowionaPizzaID, bool pizzaDodana, bool sosDodany, bool peperoniDodane, bool pieczarkiDodane, bool cebulaDodana, bool czyOddana); 

    void aktualizuj();                     
    void rysuj();                          
    void sprawdzInterakcje(int graczX, int graczY); 
    int pozostalyCzas();                  
    bool aktywny();   
    int getPizzaId();
    void wyloswaneId();
    string zamowionaPizza();     
};

#endif
