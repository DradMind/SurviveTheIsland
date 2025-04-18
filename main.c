#include "raylib.h"
#include "raymath.h"
#include <stdbool.h>
#include <stdio.h>
#include "Initialisation.h"
#include "Affichage.h"
#include <math.h>
#include <time.h>


int main(void) {
    const float screenWidth = GetScreenWidth();
    const float screenHeight = GetScreenHeight();

    InitWindow(screenWidth, screenHeight, "Survive the Island - 3D Prototype");
    SetTargetFPS(60);
    ToggleBorderlessWindowed();
    Vector3 Centre = { 0.0f, 0.0f, 0.0f };
	Camera3D camera = SetupCamera(Centre);
	InitialiserPlateau();
    float angle = 0.0f;
    float rotationSpeed = PI / 2.0f;
    int cameraMode = CAMERA_FIRST_PERSON;
	int DemarrerJeu = 0;

    int MenuOuvert = 1;
    int NbJoueurs = 2;

    while (!WindowShouldClose()) {

        BeginDrawing();
     
        ClearBackground(RAYWHITE);
		
        BeginMode3D(camera);

        AfficherPlateau();
        if (MenuOuvert == 0) {
            BougerCamera(&camera);
        }
        EndMode3D();

        DrawFPS(10, 40);
        AfficherMenu(&MenuOuvert, &NbJoueurs);
		
        EndDrawing();
        
    }
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 13; j++) {
			UnloadModel(Plateau[i][j].model);
		}
	}
    CloseWindow();
    return 0;
}
