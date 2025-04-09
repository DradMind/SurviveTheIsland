#include "Initialisation.h"
#include "Affichage.h"
#include <stdbool.h>
#include <stdio.h>
#include "raylib.h"

Camera3D SetupCamera(void) {
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 50.0f, 20.0f, 50.0f };
    camera.target = (Vector3){ 16.5f, 0.0f, 16.5f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
	return camera;
}

void InitialiserPlateau(void) {
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
			Plateau[x][y].position = (Vector3){ x * 5.5f, 0.0f, y * 5.5f };
		}
	}
}