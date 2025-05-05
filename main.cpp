#include "raylib.h"
#include "gra.hpp"
#include "skladnik.hpp"
#include "pizza.hpp"
#include "punkty.hpp"
#include "klient.hpp"
#include "muzyka.hpp" 

enum Ekran { MENU, GRA, PRZYGOTOWYWANIE_PIZZY, WYJSCIE }; 

int main() {
    const int szerokoscOkna = 800, wysokoscOkna = 600;
    InitWindow(szerokoscOkna, wysokoscOkna, "BIT OF PIZZA");
    SetTargetFPS(60);

    Texture2D tloMenu = LoadTexture("obrazki/menu.png");
    Texture2D tloGry = LoadTexture("obrazki/tloGry.png");
    Texture2D pizzaMan = LoadTexture("obrazki/pizzaman.png");
    Texture2D tloPrzygotowania = LoadTexture("obrazki/blat.png");
    Texture2D pizzaObrazek = LoadTexture("obrazki/pizza.png");
    Texture2D sosObrazek = LoadTexture("obrazki/sos.png");
    Texture2D serObrazek = LoadTexture("obrazki/ser.png");
    Texture2D pieczarkiObrazek = LoadTexture("obrazki/pieczarki.png");
    Texture2D cebulaObrazek = LoadTexture("obrazki/cebula.png");
    Texture2D peperoniObrazek = LoadTexture("obrazki/peperoni.png");
    Muzyka muzyka("muzyka/muzyka.ogg"); 
    
    Ekran aktualnyEkran = MENU;
    int PizzaManX = 100, PizzaManY = 100; 

    Klienci klient;

    Rectangle walek = { 411, 50, 239, 81 };

    bool pizzaDodana = false;
    int pizzaX = 0;
    int pizzaY = 0;

    Rectangle blatGorny = { 76, 215, 239, 98 }; 
    Rectangle blatDolny = { 26, 414, 315, 102 }; 

    Rectangle sos = { 198, 26, 133, 100 }; 
    bool sosDodany = false;
    int sosX = 0; 
    int sosY = 0;

    Rectangle ser = { 49, 31, 133, 105 }; 
    bool serDodany = false;
    int serX = 0; 
    int serY = 0;

    Rectangle pieczarki = { 47, 169, 143, 107 }; 
    bool pieczarkiDodane = false;
    int pieczarkiX = 0; 
    int pieczarkiY = 0;

    
    Rectangle cebula = { 51, 296, 142, 108 }; 
    bool cebulaDodana = false;
    int cebulaX = 0; 
    int cebulaY = 0;

    Rectangle peperoni = { 49, 446, 153, 113 }; 
    bool peperoniDodane = false;
    int peperoniX = 0; 
    int peperoniY = 0;

    while (!WindowShouldClose()) {
        BeginDrawing();
        muzyka.Aktualizuj(); 

        if (aktualnyEkran == MENU) {
            DrawTexture(tloMenu, 0, 0, WHITE);

            int tekstX = szerokoscOkna / 2 - MeasureText("BIT OF PIZZA", 40) / 2;
            int tekstY = 100;
            DrawText("BIT OF PIZZA", tekstX - 2, tekstY, 40, BLACK);
            DrawText("BIT OF PIZZA", tekstX + 2, tekstY, 40, BLACK);
            DrawText("BIT OF PIZZA", tekstX, tekstY - 2, 40, BLACK);
            DrawText("BIT OF PIZZA", tekstX, tekstY + 2, 40, BLACK);
            DrawText("BIT OF PIZZA", tekstX - 1, tekstY - 1, 40, BLACK);
            DrawText("BIT OF PIZZA", tekstX + 1, tekstY - 1, 40, BLACK);
            DrawText("BIT OF PIZZA", tekstX - 1, tekstY + 1, 40, BLACK);
            DrawText("BIT OF PIZZA", tekstX + 1, tekstY + 1, 40, BLACK);
            DrawText("BIT OF PIZZA", tekstX, tekstY, 40, WHITE);

            Rectangle przyciskStart = { szerokoscOkna / 2 - 100, 200, 200, 50 };
            DrawRectangleRec(przyciskStart, ORANGE);
            DrawText("Start", przyciskStart.x + 70, przyciskStart.y + 10, 30, WHITE);

            Rectangle przyciskWyjscie = { szerokoscOkna / 2 - 100, 340, 200, 50 };
            DrawRectangleRec(przyciskWyjscie, ORANGE);
            DrawText("wyjscie", przyciskWyjscie.x + 60, przyciskWyjscie.y + 10, 30, WHITE);

            if (CheckCollisionPointRec(GetMousePosition(), przyciskStart) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                aktualnyEkran = GRA;
            if (CheckCollisionPointRec(GetMousePosition(), przyciskWyjscie) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                aktualnyEkran = WYJSCIE;
        }
        else if (aktualnyEkran == GRA) {
            UruchomGre(tloGry); 
             
            klient.aktualizuj();
            klient.rysuj();
            klient.sprawdzInterakcje(PizzaManX,PizzaManY);
            
            int mouseX = GetMouseX();
            int mouseY = GetMouseY();

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                if (CheckCollisionPointRec((Vector2){(float)mouseX, (float)mouseY}, blatGorny) ||
                    CheckCollisionPointRec((Vector2){(float)mouseX, (float)mouseY}, blatDolny)) {
                    aktualnyEkran = PRZYGOTOWYWANIE_PIZZY;
                }
            }            
        }
        else if (aktualnyEkran == PRZYGOTOWYWANIE_PIZZY) {
            DrawTexture(tloPrzygotowania, 0, 0, WHITE);

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                if (CheckCollisionPointRec((Vector2){(float)GetMouseX(), (float)GetMouseY()}, walek)) {
                    pizzaDodana = true;
                    pizzaX = 0; 
                    pizzaY = 0;
                }
                if (CheckCollisionPointRec((Vector2){(float)GetMouseX(), (float)GetMouseY()}, sos)) {
                    sosDodany = true;
                    sosX = 0;
                    sosY = 0;
                }
                if (CheckCollisionPointRec((Vector2){(float)GetMouseX(), (float)GetMouseY()}, ser)) {
                    serDodany = true;
                    serX = 0;
                    serY = 0;
                }
                if (CheckCollisionPointRec((Vector2){(float)GetMouseX(), (float)GetMouseY()}, pieczarki)) {
                    pieczarkiDodane = true;
                    pieczarkiX = 0;
                    pieczarkiY = 0;
                }
                if (CheckCollisionPointRec((Vector2){(float)GetMouseX(), (float)GetMouseY()}, cebula)) {
                    cebulaDodana = true;
                    cebulaX = 0;
                    cebulaY = 0;
                }
                if (CheckCollisionPointRec((Vector2){(float)GetMouseX(), (float)GetMouseY()}, peperoni)) {
                    peperoniDodane = true;
                    peperoniX = 0;
                    peperoniY = 0;
                }
            }
            if (pizzaDodana) {
                DrawTexture(pizzaObrazek, pizzaX, pizzaY, WHITE);
            }
            if (sosDodany) {
                DrawTexture(sosObrazek, sosX, sosY, WHITE);
            }            
            if (serDodany) {
                DrawTexture(serObrazek, sosX, sosY, WHITE);
            }    
            if (pieczarkiDodane) {
                DrawTexture(pieczarkiObrazek, sosX, sosY, WHITE);
            }    
            if (cebulaDodana) {
                DrawTexture(cebulaObrazek, sosX, sosY, WHITE);
            }    
            if (peperoniDodane) {
                DrawTexture(peperoniObrazek, sosX, sosY, WHITE);
            }    
            if (IsKeyPressed(KEY_ESCAPE)) {
                aktualnyEkran = GRA;
                pizzaDodana = false;
                sosDodany = false;
                serDodany = false;
                pieczarkiDodane = false;
                cebulaDodana = false;
                peperoniDodane = false;
            }
        }
        else if (aktualnyEkran == WYJSCIE) {
            break;
        }

        EndDrawing();
    }
    UnloadTexture(tloMenu);
    UnloadTexture(tloGry);
    CloseWindow();
    UnloadTexture(pizzaObrazek);
    UnloadTexture(sosObrazek);
    UnloadTexture(serObrazek);
    UnloadTexture(pieczarkiObrazek);
    UnloadTexture(cebulaObrazek);
    UnloadTexture(peperoniObrazek);
    muzyka.Zakonczenie(); 
    return 0;
}
