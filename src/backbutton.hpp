#pragma once
#include<raylib.h>
#include"buttons.hpp"

class backbutton:public button
{
    public:
    backbutton();
    ~backbutton();
    void draw ()override;
};