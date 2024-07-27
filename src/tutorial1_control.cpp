#include "tutorial1_control.hpp"

TutorialPlayer::TutorialPlayer()
{
    image=LoadTexture("Graphics/ship3.png");
    InitialRectangle={0.f,0.f,(float)image.width/noofframes,(float)image.height};
    FinalRectangle ={800,400,((float)image.width/noofframes*2.0f),(float)image.height*2.0f};
}

TutorialPlayer::~TutorialPlayer()
{
    UnloadTexture(image);
}

void TutorialPlayer::draw()
{
    DrawTexturePro(image,InitialRectangle,FinalRectangle,Vector2{0,0},0.0f,WHITE);
}

void TutorialPlayer::animation()
{
    frameCounter++;
    if(frameCounter>=60/5)
    {
        currentFrame++;
        frameCounter=0;
        if(currentFrame>noofframes-1)
        {
            currentFrame=0;
        }
        InitialRectangle.x=((image.width*currentFrame)/noofframes);
        currentFrame++;
    }
}

void TutorialPlayer::update()
{
    if(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))//left
    {
        FinalRectangle.x-=speed;
        if(FinalRectangle.x==0)
        {
            FinalRectangle.x=0;

        }
    }
    if(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    {
        FinalRectangle.x+=speed;
    }
}

