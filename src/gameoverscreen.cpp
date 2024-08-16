#include "gameoverscreen.hpp"
#include<iostream>
//#include"gameover.hpp"

Gameover::Gameover()
{
    screen = LoadTexture("Graphics/overscreen.png");
    InitialRectangle1 = {0.0f, 0.0f, (float)screen.width, (float)screen.height};
    FinalRectangle1 = {0.0f, 0.0f, (float)screen.width * 2.0f, (float)screen.height * 2.0f};

    no = LoadTexture("Graphics/no1.png");
    InitialRectangle2 = {0.0f, 0.0f, (float)no.width / no_totalframe, (float)no.height};
    FinalRectangle2 = {825.0f, 650.0f, (float)no.width / no_totalframe * 2.5f, (float)no.height * 2.5f};

    yes = LoadTexture("Graphics/yes1.png");
    InitialRectangle3 = {0.0f, 0.0f, (float)yes.width / yes_totalframe, (float)yes.height};
    FinalRectangle3 = {600.0f, 650.0f, (float)yes.width / yes_totalframe * 2.5f, (float)yes.height * 2.5f};  
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
    if (!yes_clcikstate && IsButtonClicked(FinalRectangle3))
    {
        yes_currentfarme = 1;
        yes_clcikstate = true;
        yes_clicktime1 = GetTime();
        std::cout << "The second frame is displayed\n";
        std::cout << "The time when the button is clicked is " << yes_clicktime1 << std::endl;
    }

    if (yes_clcikstate && (GetTime() - yes_clicktime1 >= delaytime1))  // Corrected timing check
    {
        yes_currentfarme = 2;
        yes_clicktime2 = GetTime();
        yes_screenchange = true;
        yes_clcikstate = false;
        std::cout << "The third/first frame is displayed\n";
        std::cout << "The time when the button is clicked is " << yes_clicktime2 << std::endl;
    }

    if (yes_screenchange && (GetTime() - yes_clicktime2 >= delaytime2))
    {
        yes_screenchange = true;
        std::cout << "The screen is changed\n";
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
        if(gameOver)
        {
            draw_screen();
            draw_yes();
            draw_no();
            std::cout<<"The over function is entered\n";
        }
        
}

bool Gameover::IsButtonClicked(Rectangle rect)
{
    return (CheckCollisionPointRec(GetMousePosition(), rect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON));
}
