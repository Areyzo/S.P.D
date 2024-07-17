#include "skipbutton.hpp"

skipbutton::skipbutton()
{
    image=LoadTexture("Graphics/play.png");
    InitialRectangle={0.0f,0.0f,(float)image.width/noofframes,(float)image.height};
    FinalRectangle={1600.0f-image.width*(5.0f)/(noofframes),800.0f-image.height*(5.0f),(float)image.width/noofframes*(5.0f),(float)image.height*(5.0f)};
}

skipbutton::~skipbutton()
{
    UnloadTexture(image);
}

void skipbutton::draw()
{
    InitialRectangle.x=currentframe*image.width/noofframes;
    DrawTexturePro(image,InitialRectangle,FinalRectangle,Vector2{0,0},0.0f,WHITE);
}

