#ifndef PUNKTY_HPP
#define PUNKTY_HPP

#include <iostream>
using namespace std;

class Punkty {
private:
    int aktualnePunkty;
    int udaneZamowienia;
    int nieudaneZamowienia;
    int poziom;

public:
    Punkty();
    Punkty(int aktualnePunkty, int udaneZamowienia, int nieudaneZamowienia, int poziom);

    int getAktualnePunkty() const;
    int getUdaneZamowienia() const;
    int getNieudaneZamowienia() const;
    int getPoziom() const;

    void setAktualnePunkty(int aktualnePunkty);
    void setUdaneZamowienia(int udaneZamowienia);
    void setNieudaneZamowienia(int nieudaneZamowienia);
    void setPoziom(int poziom);

    void dodajPunkty(int ile);
    void odejmijPunkty(int ile);
    void aktualizujPoziom();
    void showInfo() const;
};

#endif 
