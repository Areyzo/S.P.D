#pragma once
#include "raylib.h"  // Ensure Raylib is included

class story {
public:
    story();
    ~story();
    void draw();
    void stop();  // Add this method to stop audio and reset animation

private:
    Texture2D spriteSheet;
    Sound storysound;
    Rectangle frameRec;
    Vector2 framePosition;
    int frameWidth;
    int frameHeight;
    int currentFrame;
    int framesCounter;
    int framesSpeed;
    float timeElapsed;
    float animationTime;
};