#include "endingscreen.hpp"

void endingscreen::draw()
{
    if(!over)
    {
        
        DrawText("GAME OVER",0.0f,0.0f,50,WHITE);
            over=true;

    }
    
}