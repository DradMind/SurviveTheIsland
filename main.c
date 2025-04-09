#include "raylib.h"
#include <stdbool.h>
#include <stdio.h>
#include "Initialisation.h"
#include "Affichage.h"

int main(void) {
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    InitWindow(screenWidth, screenHeight, "Survive the Island - 3D Prototype");
    SetTargetFPS(600);
    ToggleBorderlessWindowed();
	Camera3D camera = SetupCamera();
	InitialiserPlateau();
    while (!WindowShouldClose()) {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        AfficherPlateau();
        
        EndMode3D();

        DrawFPS(10, 40);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
