#pragma once
#include<iostream>
#include <raylib.h>
#include"buttons.hpp"

class optionbutton:public button
{      
    public:
    optionbutton();
    ~optionbutton();
    void draw() override;
};