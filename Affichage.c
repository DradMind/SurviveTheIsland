#include "Affichage.h"
#include "raylib.h"
#include "Initialisation.h"
#include <stdbool.h>
#include <stdio.h>

void AfficherPlateau() {
    // Dessiner le sol en cubes
    for (int x =0; x <7; x++) {
        for (int y = 0; y < 7; y++) {
			printf("x: %d, y: %d\n", x, y);
            DrawModel(Plateau[x][y].model, Plateau[x][y].position, 1.0f, WHITE);
        }
    }
}

