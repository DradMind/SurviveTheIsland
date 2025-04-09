#include "Initialisation.h"

Camera3D SetupCamera(void) {
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 50.0f, 20.0f, 50.0f };
    camera.target = (Vector3){ 16.5f, 0.0f, 16.5f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
	return camera;
}

