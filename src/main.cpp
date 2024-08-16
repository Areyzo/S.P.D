#include<raylib.h>
#include"playbutton.hpp"
#include"upgradebutton.hpp"
#include"backbutton.hpp"
#include"tutorial1_control.hpp"
#include"mainscreen.hpp"
#include"game.hpp"
#include"optionbutton.hpp"
#include"upgradescreen.hpp"
#include"story.hpp"
#include"gameoverscreen.hpp"
#include"optionscreen.hpp"

typedef  enum ScreenChanger {STORY,MAIN,UPGRADE,OPTION,TUTORIAL1,GAME,GAMEOVER } ScreenChanger;

int main()
{
    const int screenwidth=1600.0f;
    const int screenheight=800.0f;
    InitWindow(screenwidth,screenheight,"Play Button Checker");
    InitAudioDevice(); // Initialize audio device


    ScreenChanger screenchanger=STORY;
    playbutton play;
    upgradebutton upgrade;
    backbutton back;
    TutorialPlayer tut1;
    mainscreen m;
    optionbutton option;
    upgradescreen up;
    optionscreen op;
    story s;
    Gameover over;

    SetTargetFPS(60);
    while(WindowShouldClose()==false)
    {
        switch(screenchanger)
        {
            case STORY:
            {
                if(IsKeyPressed(KEY_ENTER))
                {
                    screenchanger = MAIN;
                    s.stop();  // Stop the story audio and reset the animation
                }
            }break;
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
                    screenchanger=OPTION;
                    option.reset();
                }
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
                if(tut1.screenchanger)
                {
                    screenchanger=GAME;
                }
            }break;
            case GAME:
            {
                
                screenchanger=GAMEOVER;

            }break;
            case GAMEOVER:    
            {
                over.no_update();
                if(over.no_screenchange)
                {
                    screenchanger = MAIN;
                    over.no_reset();
                }

                  over.yes_update();
                if(over.yes_screenchange)
                {
                screenchanger = GAME;
                over.yes_reset(); // This was corrected from over.no_reset() to over.yes_reset()
                }

    // over.draw_screen();
    // over.draw_no();
    // over.draw_yes();
             break;
            }

            default:break;
        }
        BeginDrawing();
        ClearBackground(BLACK);
        switch(screenchanger)
        {
            case STORY:
            {
                //DrawText("STORY MODE",0.0f,0.0f,25,WHITE);
                s.draw();
                std::cout<<"The story mode is displayed\n";
                break;
            }
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
                up.draw();
                up.update();
                up.draw_coins();
                up.draw_up();
                up.up_up();
                back.draw();
                break;
            }
            case OPTION:
            {
                op.draw();
                op.update();
                DrawText("OPTION SCREEN",0,0,25,WHITE);
                back.draw();
                break;
            }
            case TUTORIAL1:
            {
                tut1.draw();
                tut1.animation();
                tut1.update1();
                break;
            }
            case GAME:
            {
                game();
                std::cout<<"gameover screen"<<std::endl;
                over.over();
                break;
            }
            case GAMEOVER:
            {
                over.draw_screen();
                over.draw_no();
                over.draw_yes();
                break;
            }
            default:break;
        }

        EndDrawing();
    }
       CloseAudioDevice();
    CloseWindow();
}