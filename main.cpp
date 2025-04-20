#include "raylib.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Raylib C++ Menu");
    SetTargetFPS(60);

    bool gameStarted = false;

    while (!WindowShouldClose()) {
        if (!gameStarted && IsKeyPressed(KEY_ENTER)) gameStarted = true;
        if (!gameStarted && IsKeyPressed(KEY_ESCAPE)) break;

        BeginDrawing();
        ClearBackground(BLACK);

        if (!gameStarted) {
            DrawText("MENU GLOWNE", screenWidth/2 - 120, 150, 40, WHITE);
            DrawText("Nacisnij [ENTER], aby rozpoczac", screenWidth/2 - 200, 250, 20, WHITE);
            DrawText("Nacisnij [ESC], aby wyjsc", screenWidth/2 - 150, 300, 20, WHITE);
        } else {
            DrawText("GRA TRWA!", 320, 280, 30, WHITE);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
