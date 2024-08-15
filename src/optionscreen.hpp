#pragma once
#include<raylib.h>

class optionscreen
{
    public:
    optionscreen();
    ~optionscreen();
    Texture2D image;
    int currentframe=0;
    int totalframes=2;
    int framecounter=0;
    Rectangle IntialRectangle;
    Rectangle FinalRectangle;
    void draw();
    void update();
    bool IsButtonClicked(Rectangle rect);

};