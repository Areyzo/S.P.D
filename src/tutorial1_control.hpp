#pragma once
#include<raylib.h>

class tutorial1
{
    public:
    void draw();
    Rectangle control={800.0f,400.0f,200,150};
    const int speed=5;
    void update();
    bool IsAPressed();    
    bool IsDPressed();
};