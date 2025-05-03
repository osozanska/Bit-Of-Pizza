#include "klient.hpp"
#include "raylib.h"

Klienci::Klienci() {
    x = 700;
    y = 0;
    predkoscY = 2;
    czyAktywny = true;
    zamowieniePrzyjete = false;
    czasStart = GetTime();  
    czasNaZamowienie = 120; 
}

void Klienci::aktualizuj() {
    if (czyAktywny == false) return; // zmiana z !czyAktywny, żeby było bardziej czytelniej jak w każdym.

    if (zamowieniePrzyjete == true) {
        if (y < 300) {
            y += predkoscY;
        } else {
            y = 300; // zatrzymanie
        }
    }

    if (pozostalyCzas() <= 0) {
        czyAktywny = false;
    }
}

void Klienci::rysuj() {
    if (czyAktywny == false) return;

    DrawRectangle(x, y, 30, 40, BLUE);
    DrawText(TextFormat("Pozostaly czas: %i s", pozostalyCzas()), 10, 10, 20, WHITE);

    if (!zamowieniePrzyjete) {
        DrawText("Podejdz i kliknij myszka, by przyjac zamowienie", 10, 40, 20, WHITE);
    } else {
        DrawText("Zamwienie przyjete!", 10, 40, 20, GREEN);
    }
}

void Klienci::sprawdzInterakcje(int graczX, int graczY) {
    if (czyAktywny == false || zamowieniePrzyjete) return; // zamowienie przyjete jest w domysle false

    Rectangle klient = { (float)x, (float)y, 30, 40 };

    if (CheckCollisionPointRec(GetMousePosition(), klient) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        zamowieniePrzyjete = true;
        czasStart = GetTime(); 
    }
}

int Klienci::pozostalyCzas() {
    if (zamowieniePrzyjete == false) return czasNaZamowienie; 

    float czasOdKlikniecia = GetTime() - czasStart;
    if (czasNaZamowienie - (int)czasOdKlikniecia < 0) {
        return 0;  
    }
    return czasNaZamowienie - (int)czasOdKlikniecia; 
}

bool Klienci::aktywny() {
    return czyAktywny;
}
