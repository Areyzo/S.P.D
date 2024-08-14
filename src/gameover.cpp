#include "raylib.h"
#include"gameover.hpp"
// #include"gameoverscreen.hpp"


int gameover(void)
{
    // Initialization
    const int screenWidth = 1600;
    const int screenHeight = 800;
    bool over = false;
    //gameover g;

    InitWindow(screenWidth, screenHeight, "Game Over Screen");

    SetTargetFPS(60);  // Set FPS target


    // Main game loop
    while (!WindowShouldClose()&&!over)  // Detect window close button or ESC key
    {
        // Final draw to show game over screen
        // BeginDrawing();
        // g.draw_screen();
        // g.draw_no();
        // g.draw_yes();
        // g.no_update();
        // g.yes_update();
        EndDrawing();
        if(IsKeyDown(KEY_ENTER))
        {
            over = true;
        }
    }

    // De-Initialization
    CloseWindow();  // Close window and OpenGL context

    return 0;
}
        //DrawText("Game Over!", screenWidth / 2 - MeasureText("Game Over!", 40) / 2, screenHeight / 2 - 20, 40, RED);