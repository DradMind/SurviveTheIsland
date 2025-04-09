#include "raylib.h"
#include <stdbool.h>

typedef struct  {
    Vector3 position;
    Vector3 velocity;
    float speed;
    float height;
    bool onGround;
} Player;

void UpdatePlayer(Player* player, float deltaTime) {
    // Déplacement horizontal
    Vector3 move = { 0 };
    if (IsKeyDown(KEY_W)) move.z -= 1;
    if (IsKeyDown(KEY_S)) move.z += 1;
    if (IsKeyDown(KEY_A)) move.x -= 1;
    if (IsKeyDown(KEY_D)) move.x += 1;

    // Normaliser mouvement
    if (move.x != 0 || move.z != 0) {
        float length = sqrtf(move.x * move.x + move.z * move.z);
        move.x /= length;
        move.z /= length;
    }

    player->position.x += move.x * player->speed * deltaTime;
    player->position.z += move.z * player->speed * deltaTime;

    // Saut (simple)
    if (player->onGround && IsKeyPressed(KEY_SPACE)) {
        player->velocity.y = 5.0f;
        player->onGround = false;
    }

    // Gravité
    player->velocity.y -= 9.8f * deltaTime;
    player->position.y += player->velocity.y * deltaTime;

    // Collision avec le sol
    if (player->position.y <= player->height / 2.0f) {
        player->position.y = player->height / 2.0f;
        player->velocity.y = 0;
        player->onGround = true;
    }
}

int main(void) {
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    InitWindow(screenWidth, screenHeight, "Survive the Island - 3D Prototype");
    SetTargetFPS(60);
    ToggleBorderlessWindowed();

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 20.0f, 20.0f, 20.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Player player = { 0 };
    player.position = (Vector3){ 0.0f, 1.0f, 0.0f };
    player.velocity = (Vector3){ 0 };
    player.speed = 5.0f;
    player.height = 1.0f;
    player.onGround = true;

    while (!WindowShouldClose()) {
        float delta = GetFrameTime();
        UpdatePlayer(&player, delta);

        camera.target = player.position;
        camera.position.x = player.position.x + 10.0f;
        camera.position.y = player.position.y + 10.0f;
        camera.position.z = player.position.z + 10.0f;

        BeginDrawing();
        ClearBackground(SKYBLUE);

        BeginMode3D(camera);

        // Dessiner le sol en cubes
        for (int x = -GRID_SIZE / 2; x < GRID_SIZE / 2; x++) {
            for (int z = -GRID_SIZE / 2; z < GRID_SIZE / 2; z++) {
                Vector3 cubePos = { x * TILE_SIZE, 0, z * TILE_SIZE };
                DrawCube(cubePos, TILE_SIZE, 1.0f, TILE_SIZE, GREEN);
                DrawCubeWires(cubePos, TILE_SIZE, 1.0f, TILE_SIZE, DARKGREEN);
            }
        }

        // Dessiner le joueur
        DrawCube(player.position, 1.0f, player.height, 1.0f, RED);

        EndMode3D();

        DrawText("ZQSD to move, SPACE to jump", 10, 10, 20, DARKGRAY);
        DrawFPS(10, 40);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
