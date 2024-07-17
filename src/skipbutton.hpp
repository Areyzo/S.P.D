#pragma once
#include<iostream>
#include<raylib.h>
#include"buttons.hpp"

class skipbutton:public button
{
    public:
    skipbutton();
    ~skipbutton();
    void draw() override;
};