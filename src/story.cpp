#include "story.hpp"
#include <iostream>
#include <cstdio>  // For snprintf

story::story() 
    : frameWidth(800), frameHeight(400), currentFrame(0), framesCounter(0),
      framesSpeed(8), timeElapsed(0.0f), animationTime(5.0f) // Initialize member variables
{
    spriteSheet = LoadTexture("graphics/intro.png");
    frameRec = {0.0f, 0.0f, (float)frameWidth, (float)frameHeight}; // Initialize frameRec
    framePosition = {0, 0}; // Initialize framePosition to top-left corner
}

story::~story() {
    UnloadTexture(spriteSheet); // Unload texture in destructor
}

void story::draw() {
    // Update
    timeElapsed += GetFrameTime();  // Accumulate time elapsed

    if (timeElapsed < animationTime)  // Check if within animation duration
    {
        framesCounter++;

        if (framesCounter >= (60 / framesSpeed))  // Update frame if necessary
        {
            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 3) currentFrame = 0;  // Loop through 4 frames (0-3)
            
            // Update the rectangle to display the correct frame
            frameRec.x = (float)(currentFrame % 4) * frameWidth;
            frameRec.y = 0;  // All frames are in the first row
        }
    }

    // Draw
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Draw the current frame of the sprite
    DrawTextureRec(spriteSheet, frameRec, framePosition, WHITE);

    if (timeElapsed >= animationTime)  // Check if the animation is over
    {
        DrawText("Animation Finished!", 1600 / 2 - 100, 800 / 2 + 20, 20, RED);
    }
    EndDrawing();
}
