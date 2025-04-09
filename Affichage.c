#include "Affichage.h"
#include "raylib.h"

#include <stdbool.h>
#include <stdio.h>

void AfficherPlateau(void){
    // Dessiner le sol en cubes
    for (int x =0; x <5; x++) {
        for (int y =0; y < 5; y++) {
            Vector3 cubePos = { x, 0, y};
            DrawCube(cubePos, 5.0f, 1.0f, 5.0f, GREEN);
        }
    }
}