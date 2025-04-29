#include "Punkty.hpp"

Punkty::Punkty() : aktualnePunkty(0), udaneZamowienia(0), nieudaneZamowienia(0), poziom(1) {}

Punkty::Punkty(int aktualnePunkty, int udaneZamowienia, int nieudaneZamowienia, int poziom) : aktualnePunkty(aktualnePunkty), udaneZamowienia(udaneZamowienia), nieudaneZamowienia(nieudaneZamowienia), poziom(poziom) {}

int Punkty::getAktualnePunkty() const { return aktualnePunkty; }
int Punkty::getUdaneZamowienia() const { return udaneZamowienia; }
int Punkty::getNieudaneZamowienia() const { return nieudaneZamowienia; }
int Punkty::getPoziom() const { return poziom; }

void Punkty::setAktualnePunkty(int aktualnePunkty) {
    this-> aktualnePunkty = aktualnePunkty; 
}
void Punkty::setUdaneZamowienia(int liczba) {
    this->udaneZamowienia = udaneZamowienia;
}
void Punkty::setNieudaneZamowienia(int liczba){
    this-> nieudaneZamowienia = nieudaneZamowienia; 
}
void Punkty::setPoziom(int poziom) { 
    this-> poziom = poziom; 
}

void Punkty::dodajPunkty(int ile) {
    aktualnePunkty += ile;
    udaneZamowienia++;
    aktualizujPoziom();
}

void Punkty::odejmijPunkty(int ile) {
    aktualnePunkty -= ile;
    if (aktualnePunkty < 0) {
        aktualnePunkty = 0;
    }
    nieudaneZamowienia++;
}

void Punkty::aktualizujPoziom() {
    poziom = 1 + aktualnePunkty / 100;
}

void Punkty::showInfo() const {
    cout << "Aktualne punkty: " << aktualnePunkty << endl;
    cout << "Udane zamówienia: " << udaneZamowienia << endl;
    cout << "Nieudane zamówienia: " << nieudaneZamowienia << endl;
    cout << "Poziom: " << poziom << endl;
}
