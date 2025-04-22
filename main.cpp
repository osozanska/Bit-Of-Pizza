#include "raylib.h"

enum Ekran { MENU, GRA, WYJSCIE }; // typ dla wartosci stałych , żeby nie pisac np 0,1,2 itp

int main() {
    const int szerokoscOkna = 800, wysokoscOkna = 600;
    InitWindow(szerokoscOkna, wysokoscOkna, "BIT OF PIZZA");
    SetTargetFPS(60);
    Texture2D tloMenu = LoadTexture("obrazki/menu.png");

    Ekran aktualnyEkran = MENU;
    while (!WindowShouldClose()) {
        BeginDrawing();

        if (aktualnyEkran == MENU) {
            DrawTexture(tloMenu, 0, 0, WHITE);

            // MeasureText: Oblicza szerokość tekstu, aby można go było wyśrodkować
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

            Rectangle przyciskStart = { szerokoscOkna/2-100, 200, 200, 50 }; // x: szerokoscOkna/2-100 y: 200 szerokość: 200 wysokość: 50
            DrawRectangleRec(przyciskStart, ORANGE);
            DrawText("Start", przyciskStart.x + 70, przyciskStart.y + 10, 30, WHITE);

            Rectangle przyciskWyjscie = { szerokoscOkna /2-100, 340, 200, 50 };
            DrawRectangleRec(przyciskWyjscie, ORANGE);
            DrawText("Wyjscie", przyciskWyjscie.x + 60, przyciskWyjscie.y + 10, 30, WHITE);

            if (CheckCollisionPointRec(GetMousePosition(), przyciskStart) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                aktualnyEkran = GRA;
            if (CheckCollisionPointRec(GetMousePosition(), przyciskWyjscie) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                aktualnyEkran = WYJSCIE;
        }
        else {
            ClearBackground(RAYWHITE);

            if (aktualnyEkran == GRA) {
                DrawText("ESC", 200, 250, 30, DARKGREEN);
                if (IsKeyPressed(KEY_ESCAPE)) aktualnyEkran = MENU;
            } else if (aktualnyEkran == WYJSCIE) {
                CloseWindow();
                break;
            }
        }

        EndDrawing();
    }

    UnloadTexture(tloMenu); 
    return 0;
}
