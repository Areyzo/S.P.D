// #pragma once
// #include<raylib.h>

// class button
// {
//     public:

//     Texture2D image;
//     virtual void draw()=0;
//     void update();
//     bool IsMouseHovered(Rectangle rect);
//     bool IsButtonClicked(Rectangle rect);
//     bool hoverState=false;
//     bool clickState=false;
//     int currentframe=0;
//     void reset();
//     const int noofframes=3;
//     float clicktime=0.0f;
//     float delaytime=1.0f;
//     Rectangle InitialRectangle;
//     Rectangle FinalRectangle;
//     bool screenChanger=false;
// };


#pragma once
#include <raylib.h>

class button 
{
    public:
    Texture2D image;
    virtual void draw() = 0; 
    void update();
    bool IsMouseHovered(Rectangle rect);
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
};
