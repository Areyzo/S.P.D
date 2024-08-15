#pragma once
#include<raylib.h>
#include"gameoverscreen.hpp"

class endingscreen:public Gameover
{
    public:
    void draw();
    bool over=false;
};