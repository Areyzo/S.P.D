#pragma once
#include<raylib.h>

class SpaceShip
{
    SpaceShip();
    ~SpaceShip();
    Rectangle rect;
    int speed;
    bool active;
    Color color;
    Texture2D texture;
    Rectangle frameRec;
    Rectangle hitbox;
    int currentFrame;
    int frameCounter;
    int frameSpeed;
    void draw();
    void update();

};