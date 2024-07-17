#include "tutorial1_control.hpp"
#include<iostream>

void tutorial1::draw()
{
    DrawText("WELCOME TO TUTORIAL SCREEN 1",700,0,25,WHITE);
    DrawText("Press A KEY to move in -x and press D KEY to move in +x",0,50,25,WHITE);
    DrawRectangleRec(control,BLUE);
}

void tutorial1::update()
{
    if(IsDPressed())
    {
        control.x+=speed;
        std::cout<<"The D Button is pressed\n";
    }
    if(IsAPressed())
    {
        control.x-=speed;
        std::cout<<"The A Button is pressed\n";
    }
}

bool tutorial1::IsAPressed()
{
    return (IsKeyDown(KEY_A));
}

bool tutorial1::IsDPressed()
{
    return (IsKeyDown(KEY_D));
}
