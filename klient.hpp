#ifndef KLIENCI_HPP
#define KLIENCI_HPP

#include "raylib.h"
#include "zamowienia.hpp"

class Klienci : public Zamowienie {
protected:
    int x, y;
    int predkoscY;
    bool czyAktywny;
    bool zamowieniePrzyjete;
    bool czyOddana;
    float czasStart;
    int czasNaZamowienie;
    float czasNaNowegoKlienta;
    Texture2D klient;

public:
    Klienci();
    Klienci(int x, int y, int predkoscY, int czasNaZamowienie, int pizzaID, float czasNowy, bool oddana, int punkty, bool zadowolony);

    void aktualizuj();
    void rysuj();
    void sprawdzInterakcje(int graczX, int graczY, bool pizzaDodana, bool sosDodany, bool serDodany,bool peperoniDodane, bool pieczarkiDodane, bool cebulaDodana,bool popranwiePrzypieczona);
    int pozostalyCzas();
    bool getAktywny();
    bool czyGraSkonczona();

};

#endif
