#pragma once
#include<raylib.h>
class mainscreen
{
    private:
    //Attibutes Of Earth
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

    //Attributes Of Arrows
    Texture2D leftarrow;
    Texture2D rightarrow;
    Rectangle InitialRectangle1;
    Rectangle FinalRectangle1;
    Rectangle InitialRectangle2;
    Rectangle FinalRectangle2;
    Rectangle InitialRectangle3;
    Rectangle FinalRectangle3;
    Rectangle InitialRectangle4;
    Rectangle FinalRectangle4;
    
    int counter=1;
    public:
    mainscreen();
    ~mainscreen();
    void draw();
    void update();
    //background;
    Texture2D background;
    float scale = 0.0f;
    float scrollingBack = 0.0f;

    //void draw_arrows();
    bool upperframedone=false;
    bool animationdone=false;
    int noofframes=2;
    int currentframe=0;
    bool IsLeftArrowPressed(Rectangle rect);
    bool IsRightArrowPressed(Rectangle rect);
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

    //Attributes for the texts
    Texture2D Earth;
    Rectangle EIR;
    Rectangle EFR;

    Texture2D Saturn;
    Rectangle SIR;
    Rectangle SFR;

    Texture2D Jupiter;
    Rectangle JIR;
    Rectangle JFR;

    int game=1;
};
