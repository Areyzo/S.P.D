#pragma once
#include <raylib.h>

class button 
{
    public:
    Texture2D image;
    virtual void draw() = 0; 
    void update();
    bool IsButtonClicked(Rectangle rect);
    bool hoverState = false;
    bool clickState = false;
    int currentframe = 0;
    void reset();
    const int noofframes = 3;
    float clicktime = 0.0f;
    float delaytime = 0.5f;
    Rectangle InitialRectangle;
    Rectangle FinalRectangle;
    bool screenChanger = false;
    float clicktime1=0.0f;
    float clicktime2=0.0f;
    const float delaytime1=0.5f;
    const float delaytime2=0.5f;
    bool screenchange=false;
};
