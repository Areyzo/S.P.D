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

 
    //Attributes of coin
    void draw_coins();
    int coin;
    void coin_updation();
    bool IsButtonClicked(Rectangle rect);
    void finaldrawing();
    void initialdrawing();
    int coin_counter=1;

    Texture2D up;
    void draw_up();
    void up_up();
    int ucf=0;
    int ufc=0;
    Rectangle UIR;
    Rectangle UFR;

    bool up_clickState=false;
    float up_clicktime1=0.0f;
    float up_clicktime2=0.0f;
    float up_delaytime1=2.0f;
    float up_delaytime2=4.0f;
    bool s_screenchange=false;

    //Attributes of Ship1
    Texture2D ship1;
    Rectangle S1IR;
    Rectangle S1FR;
    int spaceship_totalframe=3;
    int s1_currentframe=0;
    int s1_framecounter=0;
    void s1_draw();
    void s1_update();
    
    //Attributes of Ship2
    Texture2D ship2;
    Rectangle S2IR;
    Rectangle S2FR;
    int s2_currentframe=0;
    int s2_framecounter=0;
    void s2_draw();
    void s2_update();

    //Attributes of Ship3
    Texture2D ship3;
    Rectangle S3IR;
    Rectangle S3FR;
    int s3_currentframe=0;
    int s3_framecounter=0;
    void s3_draw();
    void s3_update();

};