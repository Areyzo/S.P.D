#include "raylib.h"
#include "gameover.hpp"
#include "gameoverscreen.hpp"
#include <fstream>
#include <iostream>

int gameover(void)
{
    Gameover g;
    
    // Check if the window initializes correctly
    const int screenWidth = 1600;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Game Over Screen");
    if (!IsWindowReady()) {
        TraceLog(LOG_ERROR, "Window initialization failed!");
        return -1;  // Return with an error code if the window fails to initialize
    }

    SetTargetFPS(60);  
    bool over = false;

    // Main game loop
    while (!WindowShouldClose() && !over)  
    {
        // Start Drawing
        BeginDrawing();
        
        // Clear the background with white (optional if your draw_screen method handles it)
        ClearBackground(RAYWHITE);  

        // Draw the game over screen
        std::cout << "Drawing Game Over Screen" << std::endl;
        g.draw_screen();
        
        // Update and draw additional elements
        g.update();
        g.draw_no();
        g.draw_yes();
        
        // End Drawing
        EndDrawing();

        // Check for Enter key to close the window
        if (IsKeyDown(KEY_ENTER))
        {
            over = true;
        }
    }

    // Close the window and clean up resources
    CloseWindow();
    return 0;
}


    // // Initialization
    // const int screenWidth = 1600;
    // const int screenHeight = 800;
    // bool over = false;
    // Gameover g;

    // std::ofstream outFile("T.txt");
    // if (!outFile) 
    // {
    //     std::cerr << "Error opening file for writing." << std::endl;
    //     return -1; // Exit the function if the file cannot be opened
    // }

    // InitWindow(screenWidth, screenHeight, "Game Over Screen");

    // SetTargetFPS(60);  

    // while (!WindowShouldClose() && !over)  
    // {
    //     BeginDrawing();
    //     ClearBackground(RAYWHITE); // Clear the screen with a white background

    //     g.update();

    //     if(g.no_screenchange)
    //     {
    //         outFile << "Main";
    //         over = true;
    //         g.no_reset();
    //     }
    //     if(g.yes_screenchange)
    //     {
    //         outFile << "game";
    //         over = true;
    //         g.yes_reset();
    //     }

    //     EndDrawing();

    //     if(IsKeyDown(KEY_ENTER))
    //     {
    //         over = true;
    //     }
    // }

    // outFile.close(); // Close the file after writing

    // CloseWindow();  // Close window and OpenGL context