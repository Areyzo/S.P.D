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
    int noofframes=3;
    int frameSpeed=5;
    void draw();
    void update();
    Rectangle InitialRectangle;
    Rectangle FinalRectangle;
};