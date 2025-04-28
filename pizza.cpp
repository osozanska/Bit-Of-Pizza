#include "pizza.hpp"

Pizza::Pizza() : nazwaPizzy("none"), czasPieczenia(0.0), punkty(0) {}

Pizza::Pizza(string nazwaPizzy, double czasPieczenia, int punkty) : nazwaPizzy(nazwaPizzy), czasPieczenia(czasPieczenia), punkty(punkty) {}

string Pizza::getNazwa() const { return nazwaPizzy; }

double Pizza::getCzasPieczenia() const { return czasPieczenia; }

int Pizza::getPunkty() const { return punkty; }

void Pizza::setNazwa(string nazwaPizzy) {
    this->nazwaPizzy = nazwaPizzy;
}

void Pizza::setCzasPieczenia(double czasPieczenia) {
    this->czasPieczenia = czasPieczenia; 
}

void Pizza::setPunkty(int punkty) {
    this->punkty = punkty; 
}

void Pizza::showInfo() const {
    cout << "Nazwa pizzy: " << nazwaPizzy << endl;
    cout << "Czas pieczenia: " << czasPieczenia << " sekund" << endl;
    cout << "Punkty: " << punkty << endl;
}
