#pragma once
#include "raylib.h"
#include <stdbool.h>
#include <stdio.h>

Camera3D SetupCamera(void);



typedef struct case{
    Vector3 position;
    Vector3 velocity;
    bool CaseRetournee;
} case;