#pragma once
#include<raylib.h>
class mainscreen
{
    private:
    Texture2D image;
    Rectangle InitialRectangle;
    Rectangle FinalRectangle;
    Rectangle InitialRectangle1;
    Rectangle FinalRectangle1;
    Rectangle InitialRectangle2;
    Rectangle FinalRectangle2;
    int upperframe=7;
    int lowerframe=7;
    int currentframe1=0;
    int currentframe2=0;
    float upperframewidth=0;
    float lowerframewidth=0;
    int framecounter1=0;
    int framecounter2=0;
    int framespeed=10;
    int counter=1;
    public:
    mainscreen();
    ~mainscreen();
    void draw();
    void update();
    void draw_arrows();
    Texture2D leftarrow;
    Texture2D rightarrow;
    bool upperframedone=false;
    bool animationdone=false;
    int noofframes=2;
    int currentframe=0;
    bool IsLeftArrowPressed(Rectangle rect);
    bool IsRightArrowPressed(Rectangle rect);
    Texture2D earth;
    void update_arrows();
    void draw_text();

    //Attributes of Saturn
    Texture2D saturn;
    Rectangle SInitialRectangle;
    Rectangle SFinalRectangle;
    int noofplaneframes=11;
    int SaturnCurrentFrame=1;
    int Saturnframecounter=0;
    void saturn_draw();
    void saturn_update(); 
    bool saturnanimationdone=false;

    //Attributes of Jupiter
    Texture2D jupiter;
    Rectangle JInitialRectangle;
    Rectangle JFinalRectangle;
    int JupiterCurrentFrame=1;
    int JupiterFrameCounter=0;
    void jupiter_draw();
    void jupiter_update(); 
    bool jupiteranimationdone=false;
};
