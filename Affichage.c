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

void AfficherMenu(void) {
	bool MenuOuvert = true;
	int ScreenHeight = GetScreenHeight();
	int ScreenWidth = GetScreenWidth();

    if (MenuOuvert) {
        // Dimensions des boutons
        Rectangle playButton = { ScreenWidth/2, ScreenHeight/2, 200, 50 };
        Rectangle quitButton = { ScreenWidth/2, ScreenHeight/2-100, 200, 50 };

        // Vérification des clics sur les boutons
        Vector2 mousePoint = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if (CheckCollisionPointRec(mousePoint, playButton)) {
                printf("Play button clicked!\n");
				MenuOuvert = false;  // Fermer le menu
            }
            if (CheckCollisionPointRec(mousePoint, quitButton)) {
                printf("Quit button clicked!\n");
                CloseWindow();  // Fermer la fenêtre
            }
        }

        // Dessiner les boutons
        DrawRectangleRec(playButton, LIGHTGRAY);
        DrawRectangleRec(quitButton, LIGHTGRAY);

        // Ajouter du texte sur les boutons
        DrawText("Play", playButton.x + 70, playButton.y + 15, 20, BLACK);
        DrawText("Quit", quitButton.x + 70, quitButton.y + 15, 20, BLACK);

        // Vérifier si la souris survole un bouton
        if (CheckCollisionPointRec(mousePoint, playButton)) {
            DrawRectangleLinesEx(playButton, 3, RED);
        }
        else {
            DrawRectangleLinesEx(playButton, 3, BLACK);
        }

        if (CheckCollisionPointRec(mousePoint, quitButton)) {
            DrawRectangleLinesEx(quitButton, 3, RED);
        }
        else {
            DrawRectangleLinesEx(quitButton, 3, BLACK);
        }
    }
}

