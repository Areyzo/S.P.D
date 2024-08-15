#include "gameoverscreen.hpp"
#include<iostream>
//#include"gameover.hpp"

Gameover::Gameover()
{
    screen=LoadTexture("Graphics/gameover.png");
    InitialRectangle1={0.0f,0.0f,(float)screen.width,(float)screen.height};
    InitialRectangle1={0.0f,0.0f,(float)screen.width*2.5f,(float)screen.height*2.5f};

    no=LoadTexture("Graphics/no1.png");
    InitialRectangle2={0.0f,0.0f,(float)no.width/no_totalframe,(float)no.height};
    FinalRectangle2={800.0f,400.0f,(float)no.width/no_totalframe*(5.0f),(float)no.height*5.0f};

    yes=LoadTexture("Graphics/yes1.png");
    InitialRectangle3={0.0f,0.0f,(float)yes.width/yes_totalframe,(float)yes.height};
    InitialRectangle3={800.0f,500.0f,(float)yes.width/yes_totalframe*(5.0f),(float)yes.height};

    if (screen.id == 0) {
    std::cerr << "Failed to load screen texture!" << std::endl;
    // Handle error, perhaps return or set a default texture
}
if (no.id == 0) {
    std::cerr << "Failed to load 'no' texture!" << std::endl;
}
if (yes.id == 0) {
    std::cerr << "Failed to load 'yes' texture!" << std::endl;
}
}

Gameover::~Gameover()
{
    UnloadTexture(screen);
    UnloadTexture(no);
    UnloadTexture(yes);
}


void Gameover::update()
{
    no_update();
    yes_update();
}

void Gameover::finished()
{

    // if (IsKeyPressed(KEY_ENTER)) 
    // {
    //     DrawText("Game Over", 0, 0, 50, RED);
    // }
    DrawText("Game Over", 0, 0, 50, RED);
}

void Gameover::draw_screen()
{
    DrawTexturePro(screen,InitialRectangle1,FinalRectangle1,Vector2{0,0},0.0f,WHITE);
}

void Gameover::draw_no()
{
    InitialRectangle2.x=no_currentfarme*no.width/(no_totalframe);
    DrawTexturePro(no,InitialRectangle2,FinalRectangle2,Vector2{0,0},0.0f,WHITE);
}

void Gameover::no_update()
{
    if(!no_clcikstate && IsButtonClicked(FinalRectangle2))
    {
        no_currentfarme=1;
        no_clcikstate=true;
        no_clicktime1=GetTime();
        std::cout<<"The second frame is displayed\n";
        std::cout<<"The time when the button is clicked is "<<no_clicktime1<<std::endl;
    }

    if(no_clcikstate && (GetTime()-no_clcikstate>=delaytime1))
    {
        no_currentfarme=2;
        no_clicktime2=GetTime();
        no_screenchange=true;
        no_clcikstate=false;
        std::cout<<"The thrid/first frame is displayed\n";
        std::cout<<"The time when the button is clicked is "<<no_clicktime2<<std::endl;
    }

    if(no_screenchange && (GetTime()-no_clicktime2>=delaytime2))
    {
        no_screenchange=true;
        std::cout<<"The screen is changed\n";
    }
}

void Gameover::no_reset()
{
    no_currentfarme = 0;
    no_clcikstate = false;
    no_clicktime1 = 0.0f;
    no_clicktime2=0.0f;
    //no_screenChanger = false;
    no_screenchange=false;
}

void Gameover::draw_yes()
{
    InitialRectangle3.x=(yes_currentfarme*yes.width)/yes_totalframe;
    DrawTexturePro(yes,InitialRectangle3,FinalRectangle3,Vector2{0,0},0.0f,WHITE);
}

void Gameover::yes_update()
{
    if(!yes_clcikstate && IsButtonClicked(FinalRectangle3))
    {
        yes_currentfarme=1;
        yes_clcikstate=true;
        yes_clicktime1=GetTime();
        std::cout<<"The second frame is displayed\n";
        std::cout<<"The time when the button is clicked is "<<yes_clicktime1<<std::endl;
    }

    if(yes_clcikstate && (GetTime()-yes_clcikstate>=delaytime1))
    {
        yes_currentfarme=2;
        yes_clicktime2=GetTime();
        yes_screenchange=true;
        yes_clcikstate=false;
        std::cout<<"The thrid/first frame is displayed\n";
        std::cout<<"The time when the button is clicked is "<<yes_clicktime2<<std::endl;
    }

    if(yes_screenchange && (GetTime()-yes_clicktime2>=delaytime2))
    {
        yes_screenchange=true;
        std::cout<<"The screen is changed\n";
    }

}

void Gameover::yes_reset()
{
    yes_currentfarme = 0;
    yes_clcikstate = false;
    yes_clicktime1 = 0.0f;
    yes_clicktime2=0.0f;
    //screenChanger = false;
    yes_screenchange=false;
}

void Gameover::over()
{
    InitWindow(1600,800,"GAME OVER");
    SetTargetFPS(60);
    while(WindowShouldClose()==false)
    {
        BeginDrawing();
        draw_screen();
        draw_yes();
        draw_no();
        EndDrawing();
        CloseWindow();
    }
}

bool Gameover::IsButtonClicked(Rectangle rect)
{
    return (CheckCollisionPointRec(GetMousePosition(), rect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON));
}
