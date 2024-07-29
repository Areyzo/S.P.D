#include "upgradebutton.hpp"
#include <iostream>

upgradebutton::upgradebutton() 
{
    image = LoadTexture("Graphics/upgrade1.png");
    InitialRectangle = {0.0f, 0.0f, (float)(image.width / noofframes), (float)image.height};
    FinalRectangle = {0.0f, 400.0f, (float)(image.width / noofframes) * 4.0f, (float)image.height * 4.0f};
}

upgradebutton::~upgradebutton() 
{
    UnloadTexture(image);
}

void upgradebutton::draw() 
{
    InitialRectangle.x = currentframe * image.width / noofframes;
    DrawTexturePro(image, InitialRectangle, FinalRectangle, Vector2{0, 0}, 0.0f, WHITE);
}


