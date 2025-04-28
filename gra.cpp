#include "raylib.h"
#include "gra.hpp"

void UruchomGre(Texture2D tloGry) {
    static int PizzaManX = 100;
    static int PizzaManY = 100;
    static Texture2D pizzaMan;
    static bool initialized = false;

    if (!initialized) {
        pizzaMan = LoadTexture("obrazki/pizzaman.png");
        initialized = true;
    }

    ClearBackground(RAYWHITE);

    DrawTexture(tloGry, 0, 0, WHITE);

    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) PizzaManX += 5;
    if (IsKeyDown(KEY_LEFT)  || IsKeyDown(KEY_A)) PizzaManX -= 5;
    if (IsKeyDown(KEY_DOWN)  || IsKeyDown(KEY_S)) PizzaManY += 5;
    if (IsKeyDown(KEY_UP)    || IsKeyDown(KEY_W)) PizzaManY -= 5;

    DrawTexture(pizzaMan, PizzaManX, PizzaManY, WHITE);

    DrawText("ESC", 200, 550, 20, BLACK);
}
