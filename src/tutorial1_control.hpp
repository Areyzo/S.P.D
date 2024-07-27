#pragma once
#include<raylib.h>

class TutorialPlayer
{
    public:
    TutorialPlayer();
    ~TutorialPlayer();
    Rectangle rect;
    int speed=8;
    bool active;
    Color color;
    Texture2D image;
    Rectangle frameRec;
    Rectangle hitbox;
    Rectangle InitialRectangle;
    Rectangle FinalRectangle;
    int currentFrame;
    int frameCounter;
    int frameSpeed;  
    int noofframes=3;
    void draw();
    void animation();
    void update();

};