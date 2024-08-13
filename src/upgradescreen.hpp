#pragma once
#include<raylib.h>

class upgradescreen
{
    public:
    upgradescreen();
    ~upgradescreen();
    Texture2D image;
    Rectangle InitialRectangle;
    Rectangle FinalRectangle;
    int noofframes=2;
    int currentframe=0;
    int framecounter=0;
    void draw();
    void update();
    Texture2D background;
    float scale = 0.0f;
    float scrollingBack = 0.0f;
    Texture2D background1;
    float scale1 = 0.0f;
    float scrollingBack1 = 0.0f;

};