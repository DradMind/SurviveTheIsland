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
    Vector3 Centre = { 20.0f, 10.0f, 20.0f };
	Camera3D camera = SetupCamera(Centre);
	InitialiserPlateau();
    float angle = 0.0f;
    float rotationSpeed = PI / 2.0f;
    float cameraDistance = Vector3Distance(camera.position, Centre);
    
    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_RIGHT))
        {
            // Rotate right (clockwise) by 90 degrees
            angle -= rotationSpeed;

            // Update camera position based on the new angle
            camera.position.x = Centre.x + cameraDistance * sinf(angle);
            camera.position.z = Centre.z + cameraDistance * cosf(angle);

            // Ensure camera still looks at the rotation point
            camera.target = Centre;
        }
        else if (IsKeyPressed(KEY_LEFT))
        {
            // Rotate left (counter-clockwise) by 90 degrees
            angle += rotationSpeed;

            // Update camera position based on the new angle
            camera.position.x = Centre.x + cameraDistance * sinf(angle);
            camera.position.z = Centre.z + cameraDistance * cosf(angle);

            // Ensure camera still looks at the rotation point
            camera.target = Centre;
        }

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
