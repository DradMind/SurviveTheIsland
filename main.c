#include "raylib.h"
#include "raymath.h"
#include <stdbool.h>
#include <stdio.h>
#include "Initialisation.h"
#include "Affichage.h"
#include <math.h>
#include <time.h>


int main(void) {
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    InitWindow(screenWidth, screenHeight, "Survive the Island - 3D Prototype");
    SetTargetFPS(600);
    ToggleBorderlessWindowed();
    Vector3 Centre = { 0.0f, 0.0f, 0.0f };
	Camera3D camera = SetupCamera(Centre);
	InitialiserPlateau();
    float angle = 0.0f;
    float rotationSpeed = PI / 2.0f;
    int cameraMode = CAMERA_FIRST_PERSON;
    
    while (!WindowShouldClose()) {

        BeginDrawing();
     
        ClearBackground(RAYWHITE);
		
        BeginMode3D(camera);

        AfficherPlateau();
		
        EndMode3D();

        DrawFPS(10, 40);
        AfficherMenu();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
