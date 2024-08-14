#include "raylib.h"
#include"gameover.hpp"


int gameover(void)
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 400;
    bool over = false;

    InitWindow(screenWidth, screenHeight, "Game Over Screen");

    SetTargetFPS(60);  // Set FPS target


    // Main game loop
    while (!WindowShouldClose()&&!over)  // Detect window close button or ESC key
    {
        // Final draw to show game over screen
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Game Over!", screenWidth / 2 - MeasureText("Game Over!", 40) / 2, screenHeight / 2 - 20, 40, RED);
        EndDrawing();
        if(IsKeyDown(KEY_ENTER)){
            over = true;
        }
    }

    // De-Initialization
    CloseWindow();  // Close window and OpenGL context

    return 0;
}