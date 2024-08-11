#include "mainscreen.hpp"
#include<iostream>
#include <fstream> 

mainscreen::mainscreen()
{
    // background
     background = LoadTexture("Graphics/gameres/bg.png");
     scale = 2.0; 

    image=LoadTexture("Graphics/earth.png");
    InitialRectangle={0.0f,0.0f,(float)image.width/upperframe,(float)image.height/2};
    FinalRectangle={600.0f,0.0f,(float)image.width/upperframe*3.0f,(float)image.height/2*3.0f};

    leftarrow=LoadTexture("Graphics/leftarrow.png");
    InitialRectangle1={0.0f,0.0f,(float)leftarrow.width/noofframes,(float)leftarrow.height};
    FinalRectangle1={600.0f,50.0f,(float)leftarrow.width/noofframes*3.0f,(float)leftarrow.height*3.0f};
    std::cout<<"The left arrow is displayed\n";

    rightarrow=LoadTexture("Graphics/rightarrow.png");

    //Earth Right Arrow
    InitialRectangle2={0.0f,0.0f,(float)rightarrow.width/noofframes,(float)rightarrow.height};
    FinalRectangle2={840.0f,50.0f,(float)rightarrow.width/noofframes*3.0f,(float)rightarrow.height*3.0f};

    //Saturn Right Arrow
    InitialRectangle3={0.0f,0.0f,(float)rightarrow.width/noofframes,(float)rightarrow.height};
    FinalRectangle3={890.0f,50.0f,(float)rightarrow.width/noofframes*3.0f,(float)rightarrow.height*3.0f};

    //Jupiter Right Arrow
    InitialRectangle4={0.0f,0.0f,(float)rightarrow.width/noofframes,(float)rightarrow.height};
    FinalRectangle4={930.0f,50.0f,(float)rightarrow.width/noofframes*3.0f,(float)rightarrow.height*3.0f};
    std::cout<<"The right arrow is displayed\n";

    saturn=LoadTexture("Graphics/saturnimage.png");
    SInitialRectangle={0.0f,0.0f,(float)saturn.width/noofplaneframes,(float)saturn.height};
    SFinalRectangle={600.0f,0.0f,(float)saturn.width/noofplaneframes*3.0f,(float)saturn.height*3.0f};

    jupiter=LoadTexture("Graphics/Ajupiter.png");
    JInitialRectangle={0.0f,0.0f,(float)jupiter.width/noofplaneframes,(float)jupiter.height};
    JFinalRectangle={600.0f,0.0f,(float)jupiter.width/noofplaneframes*3.0f,(float)jupiter.height*3.0f};

    Earth=LoadTexture("Graphics/earth616.png");
    EIR={0.0f,0.0f,(float)Earth.width,(float)Earth.height};
    EFR={650.f,50.0f,(float)Earth.width*3.f,(float)Earth.height*3};
    std::cout<<"The image width of earth is "<<Earth.width<<std::endl;

    Saturn=LoadTexture("Graphics/saturn.png");
    SIR={0.0f,0.0f,(float)Saturn.width,(float)Saturn.height};
    SFR={650.f,50.0f,(float)Saturn.width*3,(float)Saturn.height*3};
    
    Jupiter=LoadTexture("Graphics/jupiter.png");
    JIR={0.0f,0.0f,(float)Jupiter.width,(float)Jupiter.height};
    JFR={650.f,50.0f,(float)Jupiter.width*3,(float)Jupiter.height*3};
}

mainscreen::~mainscreen()
{
    UnloadTexture(background);
    UnloadTexture(image);
    UnloadTexture(leftarrow);
    UnloadTexture(rightarrow);
    UnloadTexture(saturn);
    UnloadTexture(jupiter);
    UnloadTexture(Earth);
    UnloadTexture(Saturn);
    UnloadTexture(Jupiter);
    UnloadTexture(background);
}

void mainscreen::draw()
{   
    //drawing background
     DrawTextureEx(background, (Vector2){ 0, scrollingBack}, 0.0f, scale, WHITE);
     DrawTextureEx(background, (Vector2){0, -background.height*scale + scrollingBack }, 0.0f, scale, WHITE);

    InitialRectangle1.x=currentframe*leftarrow.width/noofframes;
    DrawTexturePro(leftarrow,InitialRectangle1,FinalRectangle1,Vector2{0,0},0,WHITE);

    InitialRectangle2.x=currentframe*rightarrow.width/noofframes;
    DrawTexturePro(rightarrow,InitialRectangle2,FinalRectangle2,Vector2{0,0},0,WHITE);

    DrawTexturePro(image,InitialRectangle,FinalRectangle,Vector2{0,0},0.0f,WHITE);
    DrawTexturePro(Earth,EIR,EFR,Vector2{0,0},0.0f,WHITE);

}


void mainscreen::update()
{

    scrollingBack = scrollingBack+0.2f;
     if (scrollingBack >= background.height*scale) scrollingBack = -background.height*scale;

    if(!animationdone)
    {
        framecounter1++;
    if(!upperframedone && framecounter1 >= 60 / 10)
    {
        if(upperframewidth <= image.width)
        {
            framecounter1 = 0;
            InitialRectangle.x = currentframe1 * image.width / upperframe;
            InitialRectangle.y = 0;
            upperframewidth = InitialRectangle.x;
            currentframe1++;
            if(currentframe1 > upperframe - 1)
            {
                currentframe1 = 0;
            }
            std::cout << "The upperframe is executed\n";
        }

        if(upperframewidth >= (image.width - image.width / upperframe))
        {
            upperframedone = true;
        }
    }

    framecounter2++;
    if(upperframedone && framecounter2 >= 60 / 10)
    {
        if(lowerframewidth <= image.width)
        {
            framecounter2 = 0;
            InitialRectangle.x = currentframe2 * image.width / lowerframe;
            InitialRectangle.y = image.height / 2.0;
            lowerframewidth = InitialRectangle.x;
            currentframe2++;
            if(currentframe2 > lowerframe - 1)
            {
                currentframe2 = 0;
            }
            std::cout << "The lowerframe is executed\n";
        }
    }
    if(lowerframewidth >= (image.width - image.width / upperframe))
        {
            animationdone=true;  
        }
    }
}


void mainscreen::update_arrows()
{
    bool rightPressed = false;

    if (IsLeftArrowPressed(FinalRectangle1))
    {
        counter--;
        if (counter < 1)
        {
            counter = 3;
        }
    }
    if (IsRightArrowPressed(FinalRectangle2) && !rightPressed)
    {
        counter++;
        if (counter > 3)
        {
            counter = 1;
        }
        rightPressed = true;
    }
    if (IsRightArrowPressed(FinalRectangle3) && !rightPressed)
    {
        counter++;
        if (counter > 3)
        {
            counter = 1;
        }
        rightPressed = true;
    }
    if (IsRightArrowPressed(FinalRectangle4) && !rightPressed)
    {
        counter++;
        if (counter > 3)
        {
            counter = 1;
        }
        rightPressed = true;
    }
}

void mainscreen::draw_text()
{
    switch (counter)
    {
        case 1:
        {
            draw();
            game = 1;
            std::ofstream outfile("screen.txt");
            if (outfile.is_open()) {
                outfile << game;
                outfile.close();
            }
            break;
        }
        case 2:
        {
            saturn_update();
            saturn_draw();
            game = 2;
            std::ofstream outfile("screen.txt");
            if (outfile.is_open()) {
                outfile << game;
                outfile.close();
            }
            break;
        }
        case 3:
        {
            jupiter_update();
            jupiter_draw();
            game = 3;
            std::ofstream outfile("screen.txt");
            if (outfile.is_open()) {
                outfile << game;
                outfile.close();
            }
            break;
        }
    }
}

void mainscreen::saturn_draw()
{
    DrawTextureEx(background, (Vector2){ 0, scrollingBack}, 0.0f, scale, WHITE);
    DrawTextureEx(background, (Vector2){0, -background.height*scale + scrollingBack }, 0.0f, scale, WHITE);

    InitialRectangle1.x=currentframe*leftarrow.width/noofframes;
    DrawTexturePro(leftarrow,InitialRectangle1,FinalRectangle1,Vector2{0,0},0,WHITE);

    InitialRectangle3.x=currentframe*rightarrow.width/noofframes;
    DrawTexturePro(rightarrow,InitialRectangle3,FinalRectangle3,Vector2{0,0},0,WHITE);

    DrawTexturePro(saturn,SInitialRectangle,SFinalRectangle,Vector2{0,0},0.0f,WHITE);
    DrawTexturePro(Saturn,SIR,SFR,Vector2{0,0},0.0f,WHITE);
}

void mainscreen::saturn_update()
{
    if(!saturnanimationdone)
    {
        Saturnframecounter++;
        if(Saturnframecounter>=60/10)
        {
            Saturnframecounter=0;
            SInitialRectangle.x=(SaturnCurrentFrame*saturn.width)/noofplaneframes;
            SaturnCurrentFrame++;
            if(SaturnCurrentFrame>noofplaneframes-1)
            {
                saturnanimationdone=true;
            }
        }
    }
}

void mainscreen::jupiter_draw()
{
    DrawTextureEx(background, (Vector2){ 0, scrollingBack}, 0.0f, scale, WHITE);
    DrawTextureEx(background, (Vector2){0, -background.height*scale + scrollingBack }, 0.0f, scale, WHITE);
    
    InitialRectangle1.x=currentframe*leftarrow.width/noofframes;
    DrawTexturePro(leftarrow,InitialRectangle1,FinalRectangle1,Vector2{0,0},0,WHITE);

    InitialRectangle4.x=currentframe*rightarrow.width/noofframes;
    DrawTexturePro(rightarrow,InitialRectangle4,FinalRectangle4,Vector2{0,0},0,WHITE);

    DrawTexturePro(jupiter,JInitialRectangle,JFinalRectangle,Vector2{0,0},0.0f,WHITE);
    DrawTexturePro(Jupiter,JIR,JFR,Vector2{0,0},0.0f,WHITE);

}

void mainscreen::jupiter_update()
{
    if(!jupiteranimationdone)
    {
        JupiterFrameCounter++;
        if(JupiterFrameCounter>=60/10)
        {
            JupiterFrameCounter=0;
            JInitialRectangle.x=(JupiterCurrentFrame*jupiter.width)/noofplaneframes;
            JupiterCurrentFrame++;
            if(JupiterCurrentFrame>noofplaneframes-1)
            {
                jupiteranimationdone=true;
            }
        }
    }
}

bool mainscreen::IsLeftArrowPressed(Rectangle rect)
{
    return (CheckCollisionPointRec(GetMousePosition(),rect) && (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)));
}

bool mainscreen::IsRightArrowPressed(Rectangle rect)
{
    return (CheckCollisionPointRec(GetMousePosition(),rect) && (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)));
}
