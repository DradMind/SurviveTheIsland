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

void AfficherMenu(int* MenuOuvert) {
	
	int ScreenHeight = GetScreenHeight(); //recupere la hauteur de l'ecran
	int ScreenWidth = GetScreenWidth(); //recupere la largeur de l'ecran

    if (*MenuOuvert==1) {

        DrawText("Survive the Island", PourcentageEntier(50, ScreenWidth) - 100, PourcentageEntier(10, ScreenHeight), 20, BLACK);
		DrawRectangle(0, 0, ScreenWidth, ScreenHeight, Fade(GRAY, 0.5f)); // Dessine un rectangle semi-transparent sur toute la fenêtre
        
        // Dimensions des boutons
		Rectangle playButton = { PourcentageEntier(50,ScreenWidth) - 100, PourcentageEntier(50,ScreenHeight) - 100, 200, 50 }; // afficher le bouton play a 50% de l'ecran
        Rectangle quitButton = { PourcentageEntier(50,ScreenWidth)-100, PourcentageEntier(50,ScreenHeight), 200, 50 };
       
        // Vérification des clics sur les boutons
		Vector2 mousePoint = GetMousePosition(); //recupere la position de la souris

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if (CheckCollisionPointRec(mousePoint, playButton)) {
                printf("Play button clicked!\n");
				*MenuOuvert = 0;  // Fermer le menu et commencer le jeu
                return 1;
            }
            if (CheckCollisionPointRec(mousePoint, quitButton)) {
                printf("Quit button clicked!\n");
                CloseWindow();
                return 0; // Fermer la fenêtre
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
            DrawRectangleLinesEx(playButton, 3, DARKBLUE);
        }
        else {
            DrawRectangleLinesEx(playButton, 3, BLACK);
        }

        if (CheckCollisionPointRec(mousePoint, quitButton)) {
            DrawRectangleLinesEx(quitButton, 3, DARKBLUE);
        }
        else {
            DrawRectangleLinesEx(quitButton, 3, BLACK);
        }
    }
}

