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

void AfficherMenu(int* MenuOuvert,int* NbJoueurs) {
	
	float ScreenHeight = GetScreenHeight(); //recupere la hauteur de l'ecran
	float ScreenWidth = GetScreenWidth(); //recupere la largeur de l'ecran

    if (*MenuOuvert==1) {

        DrawText("Survive the Island", PourcentageEntier(50, ScreenWidth) - 100, PourcentageEntier(10, ScreenHeight), 20, BLACK);
		DrawRectangle(0, 0, ScreenWidth, ScreenHeight, Fade(GRAY, 0.5f)); // Dessine un rectangle semi-transparent sur toute la fenêtre
        
        // Dimensions des boutons
		Rectangle playButton = { PourcentageEntier(50,ScreenWidth) - 100, PourcentageEntier(50,ScreenHeight) - 100, 200, 50 }; // afficher le bouton play a 50% de l'ecran
        Rectangle quitButton = { PourcentageEntier(50,ScreenWidth)-100, PourcentageEntier(50,ScreenHeight), 200, 50 };
		Rectangle P2Button = { PourcentageEntier(50,ScreenWidth) - 350, PourcentageEntier(50,ScreenHeight) + 100, 200, 50 };
		Rectangle P3Button = { PourcentageEntier(50,ScreenWidth) - 100, PourcentageEntier(50,ScreenHeight) + 100, 200, 50 };
		Rectangle P4Button = { PourcentageEntier(50,ScreenWidth) + 150, PourcentageEntier(50,ScreenHeight) + 100, 200, 50 };
       
        // Vérification des clics sur les boutons
		Vector2 mousePoint = GetMousePosition(); //recupere la position de la souris

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if (CheckCollisionPointRec(mousePoint, playButton)) {
                
				*MenuOuvert = 0;  // Fermer le menu et commencer le jeu
                return 1;
            }
            if (CheckCollisionPointRec(mousePoint, P2Button))
            {
                printf("2 Joueurs\n");
                // Ici, vous pouvez définir le nombre de joueurs à 2
                *NbJoueurs = 2;
            }
            else if (CheckCollisionPointRec(mousePoint, P3Button))
            {
                printf("3 Joueurs\n");
                // Ici, vous pouvez définir le nombre de joueurs à 3
                *NbJoueurs = 3;
            }
            else if (CheckCollisionPointRec(mousePoint, P4Button))
            {
                printf("4 Joueurs\n");
                // Ici, vous pouvez définir le nombre de joueurs à 4
                *NbJoueurs = 4;
            }

            //verifie la collision entre la souris et le bouton quitter
			if (CheckCollisionPointRec(mousePoint, quitButton)) { 
                CloseWindow();
                return 0; // Fermer la fenêtre
            }
        }

        // Dessine les boutons
		DrawRectangle(PourcentageEntier(20, ScreenWidth), PourcentageEntier(20,ScreenHeight), PourcentageEntier(60, ScreenWidth), PourcentageEntier(60, ScreenHeight), BROWN);
        DrawRectangleRec(playButton, LIGHTGRAY);
        DrawRectangleRec(quitButton, LIGHTGRAY);
		DrawRectangleRec(P2Button, LIGHTGRAY);
		DrawRectangleRec(P3Button, LIGHTGRAY);
		DrawRectangleRec(P4Button, LIGHTGRAY);

        // Ajoute du texte sur les boutons
        DrawText("Play", playButton.x + 70, playButton.y + 15, 20, BLACK);
        DrawText("Quit", quitButton.x + 70, quitButton.y + 15, 20, BLACK);
		DrawText("Nombre de joueurs", P3Button.x+5, P3Button.y - 30, 20, BLACK);
		DrawText("2 Joueurs", P2Button.x + 70, P2Button.y + 15, 20, BLACK);
		DrawText("3 Joueurs", P3Button.x + 70, P3Button.y + 15, 20, BLACK);
		DrawText("4 Joueurs", P4Button.x + 70, P4Button.y + 15, 20, BLACK);


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
		if (*NbJoueurs==2|| (CheckCollisionPointRec(mousePoint, P2Button))) {
			DrawRectangleLinesEx(P2Button, 3, DARKBLUE);
		}
		else {
			DrawRectangleLinesEx(P2Button, 3, BLACK);
		}
        if (*NbJoueurs==3 || (CheckCollisionPointRec(mousePoint, P3Button))) {
            DrawRectangleLinesEx(P3Button, 3, DARKBLUE);
        }
        else {
            DrawRectangleLinesEx(P3Button, 3, BLACK);
        }
        if (*NbJoueurs==4 || (CheckCollisionPointRec(mousePoint, P4Button))) {
            DrawRectangleLinesEx(P4Button, 3, DARKBLUE);
        }
		else {
			DrawRectangleLinesEx(P4Button, 3, BLACK);
		}
    }
}

void BougerCamera(Camera3D camera) {
    if (IsKeyDown(KEY_RIGHT)) {
        camera.position = (Vector3){ -40.0f, 20.0f, -40.0f };
        printf("vers la droite\n");
    }
    if (IsKeyDown(KEY_LEFT)) {
        camera.position = (Vector3){ 40.0f, 20.0f, 40.0f };
        printf("vers la gauche\n");
    }
}