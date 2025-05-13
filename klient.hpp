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
    bool czyZadowolony;
    Texture2D klient;
    float czasNaNowegoKlienta;
    int punkty;
    float czasZadowolenia; 

public:
    Klienci();
    Klienci(int x, int y, int predkoscY, int czasNaZamowienie, int zamowionaPizzaID, bool pizzaDodana, bool sosDodany,bool serDodany, bool peperoniDodane, bool pieczarkiDodane, bool cebulaDodana, float czasNaNowegoKlienta,bool czyOddana,int punkty, bool czyZadowolony);

    void aktualizuj();                      
    void rysuj();                          
    void sprawdzInterakcje(int graczX, int graczY, bool pizzaDodana, bool sosDodany, bool serDodany, bool peperoniDodane, bool pieczarkiDodane, bool cebulaDodana); 
    int pozostalyCzas();                    
    bool aktywny();                         
    int getPizzaId();                      
    void wylosowaneId();                   
    string zamowionaPizza();               
    void poprawnoscZamowienia(bool pizzaDodana, bool sosDodany,bool serDodany, bool peperoniDodane, bool pieczarkiDodane, bool cebulaDodana);
};

#endif
