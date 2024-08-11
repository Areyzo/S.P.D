#pragma once
#include<iostream>
#include <raylib.h>
#include"buttons.hpp"
#include<fstream>
#include<string.h> 
class playbutton:public button
{      
    public:
    playbutton();
    ~playbutton();
    void draw() override;
    void done();
    bool skip_tutoial=false;
};

