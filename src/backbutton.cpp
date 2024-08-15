#include "backbutton.hpp"

backbutton::backbutton()
{
    image=LoadTexture("Graphics/back1.png");
    InitialRectangle={0.0f,0.0f,(float)image.width/noofframes,(float)image.height};
    FinalRectangle={1600.0f-image.width/noofframes*(5.0f),800.0f-image.height*(5.0f),(float)image.width/noofframes*(5.0f),(float)image.height*(5.0f)};
}

backbutton::~backbutton()
{
    UnloadTexture(image);
}

void backbutton::draw()
{
    InitialRectangle.x=currentframe*image.width/noofframes;
    DrawTexturePro(image,InitialRectangle,FinalRectangle,Vector2{0,0},0.0f,WHITE);
}
