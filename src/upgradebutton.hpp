#pragma once
#include <raylib.h>
#include "buttons.hpp"

class upgradebutton : public button 
{
public:
    upgradebutton();
    ~upgradebutton();
    void draw() override; // Implementing the pure virtual function
};
