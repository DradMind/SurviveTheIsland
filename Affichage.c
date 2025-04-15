#include "Affichage.h"
#include "raylib.h"
#include "Initialisation.h"
#include <stdbool.h>
#include <stdio.h>
#include "Calculs.h"

void AfficherPlateau(void) {
    // Dessiner le sol en cubes
    for (int x =0; x <13; x++) {
        for (int y = 0; y < 13; y++) {
			DrawModel(Plateau[x][y].model, Plateau[x][y].position, 1.0f, WHITE); // permet de lire les donnes du tableau plateau et d'afficher le model de la case en x,y
            /*if (Plateau[x][y].model.meshCount == 0) {
                printf("Model not loaded properly!\n");
            }*/
        }
    }
}

bool AfficherMenu(bool MenuOuvert) {
	int ScreenHeight = GetScreenHeight(); //recupere la hauteur de l'ecran
	int ScreenWidth = GetScreenWidth(); //recupere la largeur de l'ecran

    if (MenuOuvert) {
        // Dimensions des boutons
		Rectangle playButton = { PourcentageEntier(50,ScreenWidth) - 100, PourcentageEntier(50,ScreenHeight) - 100, 200, 50 }; // afficher le bouton play a 50% de l'ecran
        Rectangle quitButton = { PourcentageEntier(50,ScreenWidth)-100, PourcentageEntier(50,ScreenHeight), 200, 50 };

        // Vérification des clics sur les boutons
		Vector2 mousePoint = GetMousePosition(); //recupere la position de la souris

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if (CheckCollisionPointRec(mousePoint, playButton)) {
                printf("Play button clicked!\n");
				MenuOuvert = false;  // Fermer le menu et commencer le jeu
                return true;
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

        // Vérifier si la souris survole un bouton et le surligne si la souris est dessus
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

