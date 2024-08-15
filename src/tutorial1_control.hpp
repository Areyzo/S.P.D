#pragma once
#include<raylib.h>
#include<vector>

class TutorialPlayer
{
    public:
    TutorialPlayer();
    ~TutorialPlayer();
    Rectangle rect;
    int speed=8;
    bool active;
    Color color;
    Texture2D image;
    Rectangle frameRec;
    Rectangle hitbox;
    Rectangle InitialRectangle;
    Rectangle FinalRectangle;  


    Texture2D B_image;
    struct Bullet 
    {
    Rectangle rect;
    Vector2 speed;
    bool active;
    }; 

    std::vector<Bullet> bullets;

    int currentFrame;
    int frameCounter;
    int frameSpeed;  
    int noofframes=3;
    void draw();
    void animation();
    void update1();
    void update2();
    void update3();
    void finalupdate();
    
    bool Tut1Done=false;
    bool Tut2Done=false;
    bool Tut3Done=false;
    bool leftarrowpressesd=false;
    bool rightarrowpressed=false;
    bool enterkeypressed=false;
    bool TutCompleted=false;
    float pressedtime1=0.0f;
    float pressedtime2=0.0f;
    float pressedtime3=0.0f;
    float Leftpressedtime=0.0f;

    bool leftcompleted=false;
    float completed=0.0f;
    bool congratulationsdone=false;
    float finishes=0.0f;
    bool congratulationsfinished=false;
    bool screenchanger=false;

    Texture2D background;
    float scale = 0.0f;
    float scrollingBack = 0.0f;


};