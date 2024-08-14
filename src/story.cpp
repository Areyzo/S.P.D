#include "story.hpp"
#include <iostream>
#include <cstdio>  // For snprintf

story::story() 
    : frameWidth(800), frameHeight(400), currentFrame(0), framesCounter(0),
      framesSpeed(8), timeElapsed(0.0f), animationTime(64.5f) // Initialize member variables
{
    InitAudioDevice(); // Initialize audio device
    spriteSheet = LoadTexture("graphics/intro.png");
    frameRec = {0.0f, 0.0f, (float)frameWidth, (float)frameHeight}; // Initialize frameRec
    framePosition = {0, 0}; // Initialize framePosition to top-left corner

    storysound = LoadSound("Graphics/intro.wav"); // Load sound 
    PlaySound(storysound);  // Start playing background music
}

story::~story() {
    UnloadTexture(spriteSheet); // Unload texture in destructor
    UnloadSound(storysound); // Unload background music
    CloseAudioDevice();
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


    // Draw the current frame of the sprite
    DrawTexturePro(spriteSheet, frameRec, {0,0,1600,800}, {0,0}, 0.0f, WHITE);


    if (timeElapsed >= animationTime)  // Check if the animation is over
    {
        DrawText("Animation Finished!", 1600 / 2 - 100, 800 / 2 + 20, 20, RED);
    }

}
