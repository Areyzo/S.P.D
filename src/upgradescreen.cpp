#include "upgradescreen.hpp"

upgradescreen::upgradescreen()
{
    image=LoadTexture("Graphics/block.png");
    InitialRectangle={0.0f,0.0f,(float)image.width/noofframes,(float)image.height};
    FinalRectangle={400,200,(float)image.width/noofframes*(1.0f),(float)image.height*(1.0f)};
}

upgradescreen::~upgradescreen()
{
    UnloadTexture(image);
}

void upgradescreen::draw()
{
    InitialRectangle.x=currentframe*image.width/noofframes;
    DrawTexturePro(image,InitialRectangle,FinalRectangle,Vector2{0,0},0.0f,WHITE);
}

void upgradescreen::update()
{
    framecounter++;
    if(framecounter>60/10)
    {
        framecounter=0;
        currentframe++;
        if(currentframe>noofframes-1)
        {
            currentframe=0;
        }
    }
}
