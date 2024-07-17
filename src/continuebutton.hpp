#pragma once
#include<raylib.h>
#include"buttons.hpp"

class continuebutton:public button
{
    public:
    continuebutton();
    ~continuebutton();
    void draw() override;
};