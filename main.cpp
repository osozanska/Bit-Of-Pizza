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
    Muzyka muzyka("muzyka/muzyka.ogg"); 
    
    Ekran aktualnyEkran = MENU;
    int PizzaManX = 100, PizzaManY = 100; 

    Klienci klient;

    Rectangle blatGorny = { 102, 152, 214, 96 }; // tak srednio dzialaja jeszcze
    Rectangle blatDolny = { 102, 344, 214, 96 }; 

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
                if (CheckCollisionPointRec((Vector2){(float)GetMouseX(), (float)GetMouseY()}, blatGorny) ||
                    CheckCollisionPointRec((Vector2){(float)GetMouseX(), (float)GetMouseY()}, blatDolny)) {
                    aktualnyEkran = PRZYGOTOWYWANIE_PIZZY;
                }
            }            
            
        }
        else if (aktualnyEkran == PRZYGOTOWYWANIE_PIZZY) {
            DrawTexture(tloPrzygotowania, 0, 0, WHITE);

            if (IsKeyPressed(KEY_BACKSPACE)) {
                aktualnyEkran = GRA;
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
    muzyka.Zakonczenie(); 
    return 0;
}