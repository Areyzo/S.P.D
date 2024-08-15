#include "optionscreen.hpp"

optionscreen::optionscreen()
{
    image=LoadTexture("Graphics/sound.png");
    IntialRectangle={0.0f,0.0f,(float)image.width/totalframes,(float)image.height};
    FinalRectangle={800,400,(float)image.width/totalframes*(4.0f),(float)image.height*(4.0f)};
}

optionscreen::~optionscreen()
{
    UnloadTexture(image);
}

void optionscreen::draw()
{
    IntialRectangle.x=currentframe*image.width/totalframes;
    DrawTexturePro(image,IntialRectangle,FinalRectangle,Vector2{0,0},0,WHITE);
}

void optionscreen::update()
{
    if(IsButtonClicked(FinalRectangle))
    {
        currentframe++;
        if(currentframe>1)
        {
            currentframe=0;
        }
    }

}

bool optionscreen::IsButtonClicked(Rectangle rect)
{
    return (CheckCollisionPointRec(GetMousePosition(), rect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON));
}



    



