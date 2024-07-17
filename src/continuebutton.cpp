#include "continuebutton.hpp"
#include<iostream>
continuebutton::continuebutton()
{
    image=LoadTexture("Graphics/play.png");
    InitialRectangle={0.0f,0.0f,(float)image.width/noofframes,(float)image.height};
    FinalRectangle={1600.0f-image.width*(10.0f)/(3),800.0f-image.height*(5.0f),(float)image.width/noofframes*(5.0f),(float)image.height*(5.0f)};
}

continuebutton::~continuebutton()
{
    UnloadTexture(image);
}

void continuebutton::draw()
{
    InitialRectangle.x=currentframe*image.width/noofframes;
    DrawTexturePro(image,InitialRectangle,FinalRectangle,Vector2{0,0},0.0f,WHITE);
}

