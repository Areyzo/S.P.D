#include "story.hpp"
#include<iostream>

story::story()
{
    image=LoadTexture("Graphics/play.png");
    std::cout<<"The play image is displayed\n";
}

story::~story()
{
    UnloadTexture(image);
}

void story::draw()
{
    DrawTexture(image,0.0f,0.0f,WHITE);
}

