#include <iostream>
#include "game.hpp"

using namespace std;

void Game::start() {
    cout << "Echo Zaginionego Miasta\n";
    cout << "------------------------\n";
    cout << "Obudziłeś się w dziwnym, pustym miejscu...\n";
    cout << "1. Rozejrzyj się\n";
    cout << "2. Zawołaj kogoś\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "Widzisz mgłę i ruiny starożytnych budynków. Coś za nimi sie kryje..\n";
    } else if (choice == 2) {
        cout << "Z mgły wychodzi stary męzczyzna... bez twarzy?.\n";
    } else {
        cout << "Nieznany wybór. Czas się zaciera...\n";
    }
}
