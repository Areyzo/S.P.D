#pragma once
#include "raylib.h"  // Ensure Raylib is included

class story {
public:
    story();  // Constructor
    ~story(); // Destructor

    void draw(); // Method to draw and animate

private:
    Texture2D spriteSheet; // Sprite sheet texture
    Rectangle frameRec;    // Rectangle for sprite frame
    int frameWidth;        // Width of each frame
    int frameHeight;       // Height of each frame
    int currentFrame;      // Current frame index
    int framesCounter;     // Counter for frame timing
    int framesSpeed;       // Speed of the animation (frames per second)
    float timeElapsed;     // Time elapsed for animation
    float animationTime;   // Total animation time
    Vector2 framePosition; // Position to draw the frame on the screen
    Sound storysound; // Background music
};