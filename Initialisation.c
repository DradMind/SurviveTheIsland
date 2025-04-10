#include "Initialisation.h"
#include "Affichage.h"
#include <stdbool.h>
#include <stdio.h>
#include "raylib.h"
#include <time.h>

Camera3D SetupCamera(Vector3 Centre) {
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 20.0f, 10.0f, 20.0f };
    camera.target = Centre;
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
	return camera;
}

void InitialiserPlateau(void) {
	srand(time(NULL));
	Case mer = {
		.selectionJoueur = false,
		.model = LoadModel("3d/CaseMer.obj"),
	};
	Case montagne= {
		.selectionJoueur = false,
		.model = LoadModel("3d/CaseMontagne.obj"),
	};
	Case foret={
		.selectionJoueur = false,
		.model = LoadModel("3d/CaseForet.obj"),
	};
	Case sable={
		.selectionJoueur = false,
		.model = LoadModel("3d/CaseSable.obj"),
	};
	for (int x = 0; x < 7; x++) {
		for (int y = 0; y < 7; y++) {
			int r = rand()%4;
			switch (r) {
			case 0:
				Plateau[x][y] = sable;
				break;
			case 1:
				Plateau[x][y] = foret;
				break;
			case 2:
				Plateau[x][y] = montagne;
				break;
			case 3:
				Plateau[x][y] = mer;
				break;
			}
			Plateau[x][y] = mer;
			Plateau[x][y].position = (Vector3){ x * 2.0f, 0.0f, y * 2.0f };
		}
	}
}