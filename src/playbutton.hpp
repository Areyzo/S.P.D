#pragma once
#include<iostream>
#include <raylib.h>
#include"buttons.hpp"

class playbutton:public button
{
    public:
    playbutton();
    ~playbutton();
    void draw() override;
};

