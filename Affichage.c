#include "Affichage.h"
#include "raylib.h"
#include "Initialisation.h"
#include <stdbool.h>
#include <stdio.h>

void AfficherPlateau(void) {
    // Dessiner le sol en cubes
    for (int x =0; x <7; x++) {
        for (int y = 0; y < 7; y++) {
            DrawModel(Plateau[x][y].model, Plateau[x][y].position, 1.0f, WHITE);
            /*if (Plateau[x][y].model.meshCount == 0) {
                printf("Model not loaded properly!\n");
            }*/
        }
    }
}

