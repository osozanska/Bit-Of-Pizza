#ifndef ZAMOWIENIA_HPP
#define ZAMOWIENIA_HPP
#include <iostream>
using namespace std; 


class Zamowienie {
protected:
    int zamowionaPizzaID;
    bool czyZadowolony;
    int punkty;
    int zrobionePizze;
    int zadowoleniKlienci;


public:
    Zamowienie();
    Zamowienie(int zamowionaPizzaID, bool czyZadowolony, int punkty,int zrobionePizze,int zadowoleniKlienci);
    void wylosujPizzaID();
    void sprawdzPoprawnosc(bool pizzaDodana, bool sosDodany, bool serDodany, bool peperoniDodane, bool pieczarkiDodane, bool cebulaDodana,bool popranwiePrzypieczona);
    string tekstZamowienia() const;
    bool getCzyZadowolony() const;
    int getPunkty() const;
    int getPizzaID() const;
    int getZrobionePizze() const;
    int getZadowoleniKlienci() const;
};

#endif
