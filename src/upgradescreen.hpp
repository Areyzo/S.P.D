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

};