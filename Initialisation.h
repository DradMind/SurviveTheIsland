#pragma once
#include "raylib.h"
#include <stdbool.h>
#include <stdio.h>

Camera3D SetupCamera(void);

void InitialiserPlateau(void);

typedef struct {
    Vector3 position;
    bool selectionJoueur;
	Model model;
} Case;

Case Plateau[7][7];