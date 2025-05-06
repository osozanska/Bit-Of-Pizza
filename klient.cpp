#include "klient.hpp"
#include "raylib.h"

Klienci::Klienci() {
    x = 700;
    y = 100;
    predkoscY = 2;
    czyAktywny = true;
    zamowieniePrzyjete = false;
    czasStart = GetTime();  
    czasNaZamowienie = 120; 
    klient = LoadTexture("obrazki/klient.png");
}

Klienci::Klienci(int x, int y, int predkoscY, int czasNaZamowienie) {
    this->x = x;
    this->y = y;
    this->predkoscY = predkoscY;
    this->czyAktywny = true;
    this->zamowieniePrzyjete = false;
    this->czasStart = GetTime();
    this->czasNaZamowienie = czasNaZamowienie; 
    klient = LoadTexture("obrazki/klient.png");
}

void Klienci::aktualizuj() {
    if (czyAktywny == false) return;

    if (y < 225) {
        y += predkoscY;
    } else {
        y = 225;
    }

    if (pozostalyCzas() <= 0) {
        czyAktywny = false;
    }
}

void Klienci::rysuj() {
    if (czyAktywny == false) return;

    DrawTexture(klient, x, y, WHITE);
    DrawText(TextFormat("Pozostaly czas: %i s", pozostalyCzas()), 10, 10, 20, WHITE);

    if (!zamowieniePrzyjete) {
        DrawText("Podejdz i kliknij myszka, by przyjac zamowienie", 10, 40, 20, WHITE);
    } else {
        DrawText("Zamowienie przyjete!", 10, 40, 20, GREEN);
    }
}

void Klienci::sprawdzInterakcje(int graczX, int graczY) {
    if (czyAktywny == false || zamowieniePrzyjete || y < 225) return;

    Rectangle klientrec = { (float)x, (float)y, (float)klient.width, (float)klient.height }; 

    if (CheckCollisionPointRec(GetMousePosition(), klientrec) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
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
