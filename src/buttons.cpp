#include "buttons.hpp"
#include <iostream>

void button::update()
{
    if(!clickState && IsButtonClicked(FinalRectangle))
    {
        currentframe=1;
        clickState=true;
        clicktime1=GetTime();
        std::cout<<"The second frame is displayed\n";
        std::cout<<"The time when the button is clicked is "<<clicktime1<<std::endl;
    }

    if(clickState && (GetTime()-clicktime1>=delaytime1))
    {
        currentframe=2;
        clicktime2=GetTime();
        screenchange=true;
        clickState=false;
        std::cout<<"The thrid/first frame is displayed\n";
        std::cout<<"The time when the button is clicked is "<<clicktime2<<std::endl;
    }

    if(screenchange && (GetTime()-clicktime2>=delaytime2))
    {
        screenChanger=true;
        std::cout<<"The screen is changed\n";
    }
}

bool button::IsButtonClicked(Rectangle rect) 
{
    return (CheckCollisionPointRec(GetMousePosition(), rect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON));
}

void button::reset() 
{
    currentframe = 0;
    clickState = false;
    clicktime1 = 0.0f;
    clicktime2=0.0f;
    screenChanger = false;
    screenchange=false;
}
