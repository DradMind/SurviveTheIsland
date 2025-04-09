#include "Affichage.h"
#include "raylib.h"

#include <stdbool.h>
#include <stdio.h>

void AfficherPlateau(void){
	float decalage = 5.5f;
    // Dessiner le sol en cubes
    for (int x =0; x <7; x++) {
        for (int y =0; y < 7; y++) {
            Vector3 cubePos = { x*decalage, 0, y*decalage };
            DrawCube(cubePos, 5.0f, 1.0f, 5.0f, GREEN);
			DrawCubeWires(cubePos, 5.0f, 1.0f, 5.0f, DARKGREEN);
        }
    }
	DrawCube((Vector3) { 16.5, 0, 16.5 }, 1.0f, 10.0f, 1.0f, BLUE);
}

