#include <iostream>
#include <raylib.h>

#define GLSL_VERSION 330

int main(void) {
    // =============================================
    // SETUP OF RAYLIB
    // =============================================
    std::cout << "Setting up camera...\n";

    const int screenWidth = 800;
    const int screenHeight = 600;
    const int refreshRate = 60;

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "raycube(tm)");
    
    Camera camera = { 0 };
    camera.position = (Vector3){ 2.0f, 3.0f, 2.0f };
    camera.target = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };
    float moveSpeed = 0.1f;

    SetTargetFPS(refreshRate);

    // =============================================
    // DRAWING LOOP
    // =============================================
    while (!WindowShouldClose()) {
        // Cube movement logic
        if (IsKeyDown(KEY_RIGHT)) cubePosition.x += moveSpeed;
        if (IsKeyDown(KEY_LEFT)) cubePosition.x -= moveSpeed;
        if (IsKeyDown(KEY_UP)) cubePosition.z -= moveSpeed;
        if (IsKeyDown(KEY_DOWN)) cubePosition.z += moveSpeed;

        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode3D(camera);
                DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, PURPLE);
                DrawGrid(10, 1.0f);
            EndMode3D();
            DrawText("Use arrow keys to move the cube!", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }
}