#ifndef ZAMOWIENIA_HPP
#define ZAMOWIENIA_HPP
#include <iostream>
using namespace std; 


class Zamowienie {
protected:
    int zamowionaPizzaID;
    bool czyZadowolony;
    int punkty;

public:
    Zamowienie();
    void wylosujPizzaID();
    void sprawdzPoprawnosc(bool pizzaDodana, bool sosDodany, bool serDodany, bool peperoniDodane, bool pieczarkiDodane, bool cebulaDodana);
    string tekstZamowienia() const;
    bool getCzyZadowolony() const;
    int getPunkty() const;
    int getPizzaID() const;
};

#endif
