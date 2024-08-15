#pragma once
#include<raylib.h>

class Gameover
{
    public:
    Gameover();
    ~Gameover();
    bool IsButtonClicked(Rectangle rect);
    float delaytime1=5.0f;
    float delaytime2=10.0f;
    void update();
    void finished();

    //Attributes of screen 
    Texture2D screen;
    Rectangle InitialRectangle1;
    Rectangle FinalRectangle1;
    void draw_screen();

    //Attribures of no button
    Texture2D no;
    Rectangle InitialRectangle2;
    Rectangle FinalRectangle2;
    void draw_no();
    int no_currentfarme=0;
    int no_totalframe=3;
    void no_update();
    bool no_clcikstate=false;
    float no_clicktime1=0.0f;
    float no_clicktime2=0.0f;
    void no_reset();
    bool no_screenchange=false;

    //Attributes of yes button
    Texture2D yes;
    Rectangle InitialRectangle3;
    Rectangle FinalRectangle3;
    void draw_yes();
    int yes_currentfarme=0;
    int yes_totalframe=3;
    void yes_update();
    bool yes_clcikstate=false;
    float yes_clicktime1=0.0f;
    float yes_clicktime2=0.0f;
    void yes_reset();
    bool yes_screenchange=false;
};