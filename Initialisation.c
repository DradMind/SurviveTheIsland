#include "Initialisation.h"
#include "Affichage.h"
#include <stdbool.h>
#include <stdio.h>
#include "raylib.h"
#include <time.h>

Camera3D SetupCamera(Vector3 Centre) {
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 40.0f, 20.0f, 40.0f };
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
	for (int x = 0; x < 13; x++) {
		for (int y = 0; y < 13; y++) {
			Plateau[x][y].model = LoadModel("3d/CaseMer.obj");
			Plateau[x][y].position = (Vector3){ x * 2.0f, 0.0f, y * 2.0f };
		}
		for (int x = 3; x < 10; x++) {
			for (int y = 3; y < 10; y++) {
				int r = rand() % 3;
				switch (r) {
				case 0:
					Plateau[x][y] = sable;
					Plateau[x][y].position = (Vector3){ x * 2.0f, 0.0f, y * 2.0f };
					break;
				case 1:
					Plateau[x][y] = foret;
					Plateau[x][y].position = (Vector3){ x * 2.0f, 0.0f, y * 2.0f };
					break;
				case 2:
					Plateau[x][y] = montagne;
					Plateau[x][y].position = (Vector3){ x * 2.0f, 0.0f, y * 2.0f };
					break;
				}
			}
		}
		Plateau[6][6] = mer;
		Plateau[6][6].position = (Vector3){ 6.0f, 0.0f, 6.0f };
	}
}