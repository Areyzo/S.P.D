#include<raylib.h>
#include"playbutton.hpp"
#include"skipbutton.hpp"
#include"continuebutton.hpp"
#include"upgradebutton.hpp"
#include"backbutton.hpp"
#include"tutorial1_control.hpp"
#include "mainscreen.hpp"
#include"game.hpp"
#include"optionbutton.hpp"

typedef  enum ScreenChanger {MAIN,UPGRADE,OPTION,TUTORIAL1,TUTORIAL2,GAME } ScreenChanger;

int main()
{
    const int screenwidth=1600.0f;
    const int screenheight=800.0f;
    InitWindow(screenwidth,screenheight,"Play Button Checker");

    ScreenChanger screenchanger=MAIN;
    playbutton play;
    skipbutton skip;
    continuebutton continuebutton;
    upgradebutton upgrade;
    backbutton back;
    TutorialPlayer tut1;
    mainscreen m;
    optionbutton option;

    SetTargetFPS(60);
    while(WindowShouldClose()==false)
    {
        switch(screenchanger)
        {
            case MAIN:
            {
                play.update();
                if(play.screenChanger)
                {
                    play.done();
                    if(play.skip_tutoial)
                    {
                        screenchanger=GAME;
                        play.reset();
                    }
                    else
                    {
                        screenchanger=TUTORIAL1;
                        play.reset();
                    }
                    
                }
                upgrade.update();
                if(upgrade.screenChanger)
                {
                    screenchanger=UPGRADE;
                    upgrade.reset();
                }
                option.update();
                if(option.screenChanger)
                {
                    screenchanger=MAIN;
                    option.reset();
                }
                // if(m.game==1)
                // {
                //     screenchanger=MAIN;
                // }
                // else if(m.game==2)
                // {
                //     screenchanger=UPDATE;
                // }
                // else
                // {

                // }
            }break;
            case UPGRADE:
            {  
                back.update();
                if(back.screenChanger)
                {
                    screenchanger=MAIN;
                    back.reset();
                }
            }break;
            case OPTION:
            {
                back.update();
                if(back.screenChanger)
                {
                    screenchanger=MAIN;
                    back.reset();
                }

            }break;
            case TUTORIAL1:
            {
                continuebutton.update();
                if(continuebutton.screenChanger)
                {
                    screenchanger=TUTORIAL2;
                    continuebutton.reset();
                }
                skip.update();
                if(skip.screenChanger)
                {
                    screenchanger=GAME;
                    skip.reset();
                }
            }break;
            case TUTORIAL2:
            {
                continuebutton.update();
                if(continuebutton.screenChanger)
                {
                    screenchanger=GAME;
                    continuebutton.reset();
                }
            }break;
            case GAME:
            {
                screenchanger=MAIN;
            }break;
            default:break;
        }
        BeginDrawing();
        ClearBackground(BLACK);
        switch(screenchanger)
        {
            case MAIN:
            {
                DrawText("MAIN SCREEN",0,0,25,WHITE);
                m.update();
                m.update_arrows();
                m.draw_text();
                play.draw();
                upgrade.draw();
                option.draw();
                break;
             }
            case UPGRADE:
            {
                DrawText("UPGRADE SCREEN",0,0,25,WHITE);
                back.draw();
                break;
            }
            case OPTION:
            {
                DrawText("OPTION SCREEN",0,0,25,WHITE);
                back.draw();
                break;
            }
            case TUTORIAL1:
            {
                DrawText("TUTORIAL1 SCREEN",0,0,25,WHITE);
                skip.draw();
                continuebutton.draw();
                tut1.draw();
                tut1.animation();
                tut1.update();
                break;
            }
            case TUTORIAL2:
            {
                DrawText("TUTORIAL2 SCREEN",0,0,25,WHITE);
                skip.draw();
                continuebutton.draw();
                break;
            }
            case GAME:
            {
                game();
                //DrawText("GAME SCREEN",0,0,25,WHITE);
                std::cout<<"back"<<std::endl;
                break;
            }
            default:break;
        }

        EndDrawing();
    }
    CloseWindow();
}