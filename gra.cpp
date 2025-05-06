#include "raylib.h"
#include "gra.hpp"

void UruchomGre(Texture2D tloGry) {
    static int PizzaManX = 400;
    static int PizzaManY = 400;
    static Texture2D pizzaMan;
    static bool initialized = false;

    Rectangle mebel1 = { 1, 2, 800, 153 };
    Rectangle mebel2 = { 299, 3, 161, 207 };
    Rectangle mebel3 = { 0, 3, 270, 230 };
    Rectangle mebel4 = { 30, 455, 282, 20};
    Rectangle mebel5 = { 672, 399, 160, 1};

    if (!initialized) {
        pizzaMan = LoadTexture("obrazki/pizzaman.png");
        initialized = true;
    }

    ClearBackground(RAYWHITE);

    DrawTexture(tloGry, 0, 0, WHITE);

    Rectangle graczRect = { (float)PizzaManX, (float)PizzaManY, (float)pizzaMan.width, (float)pizzaMan.height };

    int poprzedniX = PizzaManX;
    int poprzedniY = PizzaManY;

    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) PizzaManX += 5;
    if (IsKeyDown(KEY_LEFT)  || IsKeyDown(KEY_A)) PizzaManX -= 5;
    if (IsKeyDown(KEY_DOWN)  || IsKeyDown(KEY_S)) PizzaManY += 5;
    if (IsKeyDown(KEY_UP)    || IsKeyDown(KEY_W)) PizzaManY -= 5;

    graczRect.x = (float)PizzaManX;
    graczRect.y = (float)PizzaManY;

    if (CheckCollisionRecs(graczRect, mebel1) ||
        CheckCollisionRecs(graczRect, mebel2) ||
        CheckCollisionRecs(graczRect, mebel3) ||
        CheckCollisionRecs(graczRect, mebel4) ||
        CheckCollisionRecs(graczRect, mebel5)) {
        PizzaManX = poprzedniX;
        PizzaManY = poprzedniY;
    }

    if (PizzaManX < 0) PizzaManX = 0;
    if (PizzaManX > 800 - pizzaMan.width) PizzaManX = 800 - pizzaMan.width;
    if (PizzaManY < 0) PizzaManY = 0;
    if (PizzaManY > 600 - pizzaMan.height) PizzaManY = 600 - pizzaMan.height;

    DrawTexture(pizzaMan, PizzaManX, PizzaManY, WHITE);

    DrawText("ESC", 200, 550, 20, BLACK);
}
