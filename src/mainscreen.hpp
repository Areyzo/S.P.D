#pragma once
#include<raylib.h>

class mainscreen
{
    private:
    Texture2D image;
    Rectangle InitialRectangle;
    Rectangle FinalRectangle;
    int upperframe=7;
    int lowerframe=7;
    int currentframe1=0;
    int currentframe2=0;
    float upperframewidth=0;
    float lowerframewidth=0;
    int framecounter1=0;
    int framecounter2=0;
    int framespeed=10;
    public:
    mainscreen();
    ~mainscreen();
    void draw();
    void update();
    bool upperframedone=false;
    bool animationdone=false;
};