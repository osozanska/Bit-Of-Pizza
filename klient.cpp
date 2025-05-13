#include "klient.hpp"
#include "raylib.h"
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>  
#include <iostream>
#include <string>
using namespace std;

Klienci::Klienci() {
    x = 700;
    y = 100;
    predkoscY = 2;
    czyAktywny = true;
    zamowieniePrzyjete = false;
    czasStart = GetTime();  
    czasNaZamowienie = 120; 
    zamowionaPizzaID = 0;
    pizzaDodana = false;
    sosDodany = false;
    serDodany = false;
    peperoniDodane = false;
    pieczarkiDodane = false;
    cebulaDodana = false;
    czyOddana = false;
    czyZadowolony = false;
    klient = LoadTexture("obrazki/klient.png");
    czasNaNowegoKlienta = 0.0; 
    punkty = 0;
}

Klienci::Klienci(int x, int y, int predkoscY, int czasNaZamowienie, int zamowionaPizzaID, bool pizzaDodana, bool sosDodany,bool serDodany, bool peperoniDodane, bool pieczarkiDodane, bool cebulaDodana, float czasNaNowegoKlienta,bool czyOddana,int punkty, bool czyZadowolony) {
    this->x = x;
    this->y = y;
    this->predkoscY = predkoscY;
    this->czyAktywny = true;
    this->zamowieniePrzyjete = false;
    this->czasStart = GetTime();
    this->czasNaZamowienie = czasNaZamowienie; 
    this->zamowionaPizzaID = zamowionaPizzaID;
    this->pizzaDodana = pizzaDodana;
    this->sosDodany = sosDodany;
    this->serDodany = serDodany;
    this->peperoniDodane = peperoniDodane;
    this->pieczarkiDodane = pieczarkiDodane;
    this->cebulaDodana = cebulaDodana;
    this->czyOddana = czyOddana;
    klient = LoadTexture("obrazki/klient.png");
    this->czasNaNowegoKlienta = czasNaNowegoKlienta; 
    this->punkty = punkty;
    this->czyZadowolony = czyZadowolony;
}

void Klienci::aktualizuj() {
    if (czyAktywny == false) {
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
    if (czyAktywny == false) return;

    DrawTexture(klient, x, y, WHITE);
    DrawText(TextFormat("Pozostaly czas: %i s", pozostalyCzas()), 10, 10, 20, WHITE);
    DrawText(TextFormat("Punkty: %i", punkty), 10, 70, 20, WHITE);  

    if (!zamowieniePrzyjete) {
        DrawText("Podejdz i kliknij myszka, by przyjac zamowienie", 10, 40, 20, WHITE);
    } else{
        DrawText("Zamowienie przyjete!", 10, 40, 20, GREEN);
        zamowionaPizza();
    } 
}

void Klienci::sprawdzInterakcje(int graczX, int graczY, bool pizzaDodana, bool sosDodany, bool serDodany, bool peperoniDodane, bool pieczarkiDodane, bool cebulaDodana) {
    if (czyAktywny == false || y < 225) return;

    Rectangle klientrec = { (float)x, (float)y, (float)klient.width, (float)klient.height }; 

    if (CheckCollisionPointRec(GetMousePosition(), klientrec) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        
        if (zamowieniePrzyjete == false) { 
            zamowieniePrzyjete = true;
            czasStart = GetTime();
            wylosowaneId();
        } 
        
    else if (zamowieniePrzyjete && czyOddana == false) { 
        poprawnoscZamowienia(pizzaDodana,sosDodany,serDodany,peperoniDodane,pieczarkiDodane,cebulaDodana);
        czyOddana = true;
        DrawText("Pizza dostarczona!", x, y - 50, 20, GREEN);
        czyAktywny = false; 
        if(czyZadowolony == true){
            DrawText("TAK", 100,300,200,YELLOW);
            czasNaNowegoKlienta = GetTime();  
            punkty = punkty + 10;
        } else{
            DrawText("NIE", 100,300,200,RED);
            czasNaNowegoKlienta = GetTime();
            punkty = punkty - 10;
        }
    }
//     else if (zamowieniePrzyjete == true && czyOddana == true) { 
//     poprawnoscZamowienia(pizzaDodana, sosDodany, serDodany,peperoniDodane, pieczarkiDodane, cebulaDodana);
//     czyOddana = true;
//     DrawText("Pizza dostarczona!", x, y - 50, 20, GREEN);
//     czyAktywny = false; 
//     czasNaNowegoKlienta = GetTime();  
// }


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

int Klienci::getPizzaId(){
    return zamowionaPizzaID;
}

void Klienci::wylosowaneId(){
    zamowionaPizzaID = rand() % 5 + 1;
}

string Klienci::zamowionaPizza(){
    switch (zamowionaPizzaID){
        case 1:
        DrawText("Klient zamowil Pizze Margarite!", 10, 70, 20, YELLOW);
        return "Pizza Margarita";
        case 2:
        DrawText("Klient zamowil Pizze Peperonii!", 10, 70, 20, YELLOW);
        return "Pizza Peperonii";
        case 3:
        DrawText("Klient zamowil Pizze z Pieczarkami!", 10, 70, 20, YELLOW);
        return "Pizza z Pieczarkami";
        case 4:
        DrawText("Klient zamowil Pizze z Cebula!", 10, 70, 20, YELLOW);
        return "Pizza z Cebula";
        case 5:
        DrawText("Klient zamowil Pizze ze Wszystkim!", 10, 70, 20, YELLOW);
        return "Pizza ze Wszystkim";
    }
}

void Klienci::poprawnoscZamowienia(bool pizzaDodana, bool sosDodany,bool serDodany, bool peperoniDodane, bool pieczarkiDodane, bool cebulaDodana){
                if(zamowionaPizzaID == 1 && pizzaDodana == true && sosDodany == true && serDodany == true && peperoniDodane == false && pieczarkiDodane == false && cebulaDodana == false){
                    czyZadowolony = true;
                }
            else if(zamowionaPizzaID == 2 && pizzaDodana == true && sosDodany == true && serDodany == true && peperoniDodane == true && pieczarkiDodane == false && cebulaDodana == false){
                    czyZadowolony = true;
                }
            else if(zamowionaPizzaID == 3 && pizzaDodana == true && sosDodany == true && serDodany == true && peperoniDodane == false && pieczarkiDodane == true && cebulaDodana == false){
                    czyZadowolony = true;
                }
            else if(zamowionaPizzaID == 4 && pizzaDodana == true && sosDodany == true && serDodany == true && peperoniDodane == false && pieczarkiDodane == false && cebulaDodana == true){
                    czyZadowolony = true;
                }
            else if(zamowionaPizzaID == 5 && pizzaDodana == true && sosDodany == true && serDodany == true && peperoniDodane == true && pieczarkiDodane == true && cebulaDodana == true){
                    czyZadowolony = true;
                }
            else{
                    czyZadowolony = false;
                }
}
