#include "skladnik.hpp"

Skladnik::Skladnik() : Pizza(), nazwaSkladnika("none"), cena(0.0), producent("none") {}

Skladnik::Skladnik(string nazwaPizzy, double czasPieczenia, int punkty, string nazwaSkladnika, double cena, string producent)
    : Pizza(nazwaPizzy, czasPieczenia, punkty), nazwaSkladnika(nazwaSkladnika), cena(cena), producent(producent) {}

string Skladnik::getNazwaSkladnika() const { return nazwaSkladnika; }

double Skladnik::getCena() const { return cena; }

string Skladnik::getProducent() const { return producent; }

void Skladnik::setNazwaSkladnika(string nazwaSkladnika) {
    this->nazwaSkladnika = nazwaSkladnika; 
}

void Skladnik::setCena(double cena) {
    this->cena = cena;
}

void Skladnik::setProducent(string producent) {
    this->producent = producent;
}

void Skladnik::showInfo() const {
    cout << "Nazwa składnika: " << nazwaSkladnika << endl;
    cout << "Cena: " << cena << endl;
    cout << "Producent: " << producent << endl;
    cout << "Czas pieczenia: " << getCzasPieczenia() << " sekund" << endl;
    cout << "Punkty: " << getPunkty() << endl;
}
