#include "optionbutton.hpp"

optionbutton::optionbutton()
{
    image =LoadTexture("Graphics/option1.png");
    InitialRectangle={0.0f,0.0f,(float)image.width/noofframes,(float)image.height};
    FinalRectangle ={0.0f,500.0f,((float)image.width/noofframes)*4.0f,(float)image.height*4.0f};
}
optionbutton::~optionbutton()
{
    UnloadTexture(image);
}

void optionbutton::draw()
{
    InitialRectangle.x=currentframe*image.width/noofframes;
    DrawTexturePro(image,InitialRectangle,FinalRectangle,Vector2{0,0},0,WHITE);
}
