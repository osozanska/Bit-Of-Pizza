#ifndef PIZZA_HPP
#define PIZZA_HPP

#include <string>
#include <iostream>

using namespace std;

class Pizza {
private:
    string nazwaPizzy;
    double czasPieczenia;
    int punkty;

public:
    Pizza();
    Pizza(string nazwaPizzy, double czasPieczenia, int punkty);

    string getNazwa() const;
    double getCzasPieczenia() const;
    int getPunkty() const;

    void setNazwa(string nazwaPizzy);
    void setCzasPieczenia(double czasPieczenia);
    void setPunkty(int punkty);

    void showInfo() const;
};

#endif
