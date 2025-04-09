#include "raylib.h"
#include <stdbool.h>
#include <stdio.h>
#include "Initialisation.h"
#include "Affichage.h"

int main(void) {
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    InitWindow(screenWidth, screenHeight, "Survive the Island - 3D Prototype");
    SetTargetFPS(60);
    ToggleBorderlessWindowed();
	Camera3D camera = SetupCamera();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(camera);
		AfficherPlateau();

        EndMode3D();

        DrawText("ZQSD to move, SPACE to jump", 10, 10, 20, DARKGRAY);
        DrawFPS(10, 40);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
