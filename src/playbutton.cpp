#include"playbutton.hpp"
#include<raylib.h>

playbutton::playbutton()
{
    image =LoadTexture("Graphics/play1.png");
    InitialRectangle={0.0f,0.0f,(float)image.width/noofframes,(float)image.height};
    FinalRectangle ={800,400,((float)image.width/noofframes)*5.0f,(float)image.height*5.0f};
}
playbutton::~playbutton()
{
    UnloadTexture(image);
}

void playbutton::draw()
{
    InitialRectangle.x=currentframe*image.width/noofframes;
    DrawTexturePro(image,InitialRectangle,FinalRectangle,Vector2{0,0},0,WHITE);
}


