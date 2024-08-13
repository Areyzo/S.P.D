#include "upgradescreen.hpp"

upgradescreen::upgradescreen()
{   
    background = LoadTexture("Graphics/gameres/bg.png");
    scale = 2.0; 
    background1 = LoadTexture("Graphics/gameres/bgupgrade.png");
    scale1 = 2.0; 
    image=LoadTexture("Graphics/block.png");
    InitialRectangle={0.0f,0.0f,(float)image.width/noofframes,(float)image.height};
    FinalRectangle={400,200,(float)image.width/noofframes*(1.0f),(float)image.height*(1.0f)};
}

upgradescreen::~upgradescreen()
{
    UnloadTexture(image);
    UnloadTexture(background);
    UnloadTexture(background1);
}

void upgradescreen::draw()
{   
    DrawTextureEx(background, (Vector2){ 0, scrollingBack}, 0.0f, scale, WHITE);
    DrawTextureEx(background, (Vector2){0, -background.height*scale + scrollingBack }, 0.0f, scale, WHITE);
    DrawTextureEx(background1, (Vector2){ 0, scrollingBack1}, 0.0f, scale1, WHITE);
    DrawTextureEx(background1, (Vector2){0, -background1.height*scale + scrollingBack1 }, 0.0f, scale, WHITE);
    
    InitialRectangle.x=currentframe*image.width/noofframes;
    DrawTexturePro(image,InitialRectangle,FinalRectangle,Vector2{0,0},0.0f,WHITE);
    
}

void upgradescreen::update()
{
    scrollingBack = scrollingBack+0.2f;
     if (scrollingBack >= background.height*scale) scrollingBack = -background.height*scale;
     scrollingBack1 = scrollingBack1+0.4f;
     if (scrollingBack1 >= background1.height*scale1) scrollingBack1 = -background1.height*scale1;

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
