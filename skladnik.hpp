#ifndef SKLADNIK_HPP
#define SKLADNIK_HPP

#include "pizza.hpp"

using namespace std;

class Skladnik : public Pizza {
private:
    string nazwaSkladnika;
    double cena;
    string producent;

public:
    Skladnik();
    Skladnik(string nazwaPizzy, double czasPieczenia, int punkty,
             string nazwaSkladnika, double cena, string producent);

    string getNazwaSkladnika() const;
    double getCena() const;
    string getProducent() const;

    void setNazwaSkladnika(string nazwaSkladnika);
    void setCena(double cena);
    void setProducent(string producent);

    void showInfo() const;
};

#endif
