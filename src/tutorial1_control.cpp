#include "tutorial1_control.hpp"
#include<iostream>

TutorialPlayer::TutorialPlayer()
{   
    background = LoadTexture("Graphics/gameres/bg.png");
    scale = 2.0; 

    image=LoadTexture("Graphics/ship3.png");
    InitialRectangle={0.f,0.f,(float)image.width/noofframes,(float)image.height};
    FinalRectangle ={800,400,((float)image.width/noofframes*2.0f),(float)image.height*2.0f};
}

TutorialPlayer::~TutorialPlayer()
{
    UnloadTexture(image);
    UnloadTexture(background);
}

void TutorialPlayer::draw()
{
    DrawTextureEx(background, (Vector2){ 0, scrollingBack}, 0.0f, scale, WHITE);
    DrawTextureEx(background, (Vector2){0, -background.height*scale + scrollingBack }, 0.0f, scale, WHITE);
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


void TutorialPlayer::update1()
{
    scrollingBack = scrollingBack+0.2f;
     if (scrollingBack >= background.height*scale) scrollingBack = -background.height*scale;
     
    if(!Tut1Done)
    {
        DrawText("MOVE THE LEFT ARROW KEY TO MOVE LEFT",0.0f,0.0f,50,WHITE);

        if(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
    {
        if(!leftarrowpressesd)
        {
            pressedtime1=GetTime();
            std::cout<<"The value of leftarrowpressed is "<<leftarrowpressesd<<std::endl;
            leftarrowpressesd=true;
        }
        FinalRectangle.x-=speed;
        if(GetTime()-pressedtime1>=1.0f)
        {
            Tut1Done=true;
            completed=GetTime();
            std::cout<<"The tutorial 1 of movement is completed\n";
        }
    }
    }
    else
    {
        leftcompleted=false;
        if(!congratulationsdone)
        {
            DrawText("CONGRATULATIONS",550,200,50,WHITE);
            std::cout<<"The congratulations from update1 is being displayed\n";
        }
            if((GetTime()-completed>=1.0f))
            {
                congratulationsdone=true;
                update2();
            } 
    }
}

void TutorialPlayer::update2()
{
    if(!Tut2Done)
    {
        DrawText("MOVE THE RIGHT ARROW KEY TO MOVE RIGHT",0.0f,0.0f,50,WHITE);

        if(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    {
        if(!rightarrowpressed)
        {
            pressedtime2=GetTime();
            std::cout<<"The value of rightarrowpressed is "<<rightarrowpressed<<std::endl;
            rightarrowpressed=true;
        }
        FinalRectangle.x+=speed;
        if(GetTime()-pressedtime2>=1.0f)
        {
            Tut2Done=true;
            std::cout<<"The tutorial 1 of movement is completed\n";
        }
        std::cout<<"The value of pressed time is "<<pressedtime2<<std::endl;
        std::cout<<"The value of gettime is "<<GetTime()<<std::endl;
        std::cout<<"The tutorial 1 of movement is not completed\n";
    }
    }
    else
    {
        DrawText("CONGRATULATIONS",550,200,50,WHITE);
    }
}
void TutorialPlayer::update3()
{
    if(!Tut3Done)
    {
        DrawText("PRESS SPACE TO SHOOT",0.0f,0.0f,50,WHITE);

        if(IsKeyDown(KEY_SPACE))
    {
        
        if(GetTime()-pressedtime2>=1.0f)
        {
            Tut3Done=true;
            std::cout<<"The tutorial 3 of bullet is completed\n";
        }
        std::cout<<"The value of pressed time is "<<pressedtime2<<std::endl;
        std::cout<<"The value of gettime is "<<GetTime()<<std::endl;
        std::cout<<"The tutorial 1 of movement is not completed\n";
    }
    }
    else
    {
        DrawText("CONGRATULATIONS",550,200,50,WHITE);
    }
}

        