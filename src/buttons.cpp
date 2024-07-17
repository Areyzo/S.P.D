#include "buttons.hpp"
#include <iostream>

void button::update() 
{
    if (IsMouseHovered(FinalRectangle)) 
    {
        if (!hoverState) 
        {
            currentframe = 1;
            hoverState = true;
        }
        if (IsButtonClicked(FinalRectangle) && !clickState) 
        {
            currentframe = 2;
            clickState = true;
            clicktime = GetTime();
            std::cout << "The mouse is clicked\n";
        }
        if (clickState && (GetTime() - clicktime >= delaytime)) 
        {
            screenChanger = true;
        }
    } 
    else 
    {
        hoverState = false;
        clickState = false;
        currentframe = 0;
    }
}

bool button::IsMouseHovered(Rectangle rect) 
{
    return (CheckCollisionPointRec(GetMousePosition(), rect));
}

bool button::IsButtonClicked(Rectangle rect) 
{
    return (CheckCollisionPointRec(GetMousePosition(), rect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON));
}

void button::reset() 
{
    currentframe = 0;
    clickState = false;
    hoverState = false;
    clicktime = 0.0f;
    screenChanger = false;
}
