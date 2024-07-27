#include "mainscreen.hpp"
#include<iostream>

mainscreen::mainscreen()
{
    image=LoadTexture("Graphics/earth.png");
    InitialRectangle={0.0f,0.0f,(float)image.width/upperframe,(float)image.height/2};
    FinalRectangle={600.0f,0.0f,(float)image.width/upperframe*3.0f,(float)image.height/2*3.0f};
}

mainscreen::~mainscreen()
{
    UnloadTexture(image);
}

void mainscreen::draw()
{
    DrawTexturePro(image,InitialRectangle,FinalRectangle,Vector2{0,0},0.0f,WHITE);
}

void mainscreen::update()
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
            upperframedone = false;
        }
}
