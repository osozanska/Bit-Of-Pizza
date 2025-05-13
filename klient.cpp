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
    czyOddana = false;
    czasNaNowegoKlienta = 0.0;
    klient = LoadTexture("obrazki/klient.png");
}

Klienci::Klienci(int x, int y, int predkoscY, int czasNaZamowienie, int pizzaID, float czasNowy, bool oddana, int punkty, bool zadowolony) : Zamowienie(pizzaID, zadowolony, punkty, zrobionePizze, zadowoleniKlienci),  x(x), y(y), predkoscY(predkoscY), czasNaZamowienie(czasNaZamowienie), czasNaNowegoKlienta(czasNowy), czyOddana(oddana), czasStart(GetTime()), czyAktywny(true), zamowieniePrzyjete(false){}

void Klienci::aktualizuj() {
    if (!czyAktywny) {
        if (GetTime() - czasNaNowegoKlienta >= 2.0) {
            czasStart = GetTime();
            zamowieniePrzyjete = false;
            czyOddana = false;
            zamowionaPizzaID = 0;
            czyZadowolony = false;
            czyAktywny = true;
            y = 100;
        }
        return;
    }

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
    if (!czyAktywny) return;

    DrawTexture(klient, x, y, WHITE);
    DrawText(TextFormat("Pozostaly czas: %i s", pozostalyCzas()), 10, 10, 20, WHITE);
    DrawText(TextFormat("Punkty: %i", punkty), 10, 70, 20, WHITE);

    if (!zamowieniePrzyjete) {
        DrawText("Podejdz i kliknij myszka, by przyjac zamowienie", 10, 40, 20, WHITE);
    } else {
        DrawText("Zamowienie przyjete!", 10, 40, 20, GREEN);
        DrawText(tekstZamowienia().c_str(), 10, 100, 20, YELLOW);
        }
    }

void Klienci::sprawdzInterakcje(int graczX, int graczY, bool pizzaDodana, bool sosDodany, bool serDodany, bool peperoniDodane, bool pieczarkiDodane, bool cebulaDodana,bool popranwiePrzypieczona) {
    if (!czyAktywny || y < 225) return;

    Rectangle klientRec = { (float)x, (float)y, (float)klient.width, (float)klient.height };
    if (CheckCollisionPointRec(GetMousePosition(), klientRec) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if (!zamowieniePrzyjete) {
            zamowieniePrzyjete = true;
            czasStart = GetTime();
            wylosujPizzaID();
        } else if (zamowieniePrzyjete && !czyOddana) {
            czyOddana = true;
            sprawdzPoprawnosc(pizzaDodana, sosDodany, serDodany, peperoniDodane, pieczarkiDodane, cebulaDodana, popranwiePrzypieczona);
            czyAktywny = false;
            czasNaNowegoKlienta = GetTime();
            sosDodany = false;
            pizzaDodana = false;
            serDodany = false;
            peperoniDodane = false;
            pieczarkiDodane = false;
            cebulaDodana = false;
        }
    }
}

int Klienci::pozostalyCzas() {
    if (!zamowieniePrzyjete) return czasNaZamowienie;
    int uplynelo = (int)(GetTime() - czasStart);
    return (czasNaZamowienie - uplynelo < 0) ? 0 : czasNaZamowienie - uplynelo;
}

bool Klienci::getAktywny() {
    return czyAktywny;
}

bool Klienci::czyGraSkonczona(){
    return pozostalyCzas() <= 0;
}
