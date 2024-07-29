#include"playbutton.hpp"
#include<raylib.h>

playbutton::playbutton()
{
    image =LoadTexture("Graphics/start1.png");
    InitialRectangle={0.0f,0.0f,(float)image.width/noofframes,(float)image.height};
    FinalRectangle ={0.0f,300,((float)image.width/noofframes)*4.0f,(float)image.height*4.0f};
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






