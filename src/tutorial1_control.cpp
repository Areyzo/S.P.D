#include "tutorial1_control.hpp"
#include<iostream>
#include <algorithm> // For std::remove_if

TutorialPlayer::TutorialPlayer()
{   
    background = LoadTexture("Graphics/gameres/bg.png");
    scale = 2.0; 

    image=LoadTexture("Graphics/ship3.png");
    InitialRectangle={0.f,0.f,(float)image.width/noofframes,(float)image.height};
    FinalRectangle ={800,400,((float)image.width/noofframes*2.0f),(float)image.height*2.0f};

    B_image=LoadTexture("Graphics/gameres/bullet.png");
}

TutorialPlayer::~TutorialPlayer()
{
    UnloadTexture(image);
    UnloadTexture(background);
    UnloadTexture(B_image);
}

void TutorialPlayer::draw()
{
    DrawTextureEx(background, (Vector2){ 0, scrollingBack}, 0.0f, scale, WHITE);
    DrawTextureEx(background, (Vector2){0, -background.height*scale + scrollingBack }, 0.0f, scale, WHITE);
    DrawTexturePro(image,InitialRectangle,FinalRectangle,Vector2{0,0},0.0f,WHITE);
}

void TutorialPlayer::animation()
{
    frameCounter++;
    if(frameCounter>=60/5)
    {
        currentFrame++;
        frameCounter=0;
        if(currentFrame>noofframes-1)
        {
            currentFrame=0;
        }
        InitialRectangle.x=((image.width*currentFrame)/noofframes);
        currentFrame++;
    }
}


void TutorialPlayer::update1()
{
    scrollingBack = scrollingBack+0.2f;
     if (scrollingBack >= background.height*scale) scrollingBack = -background.height*scale;
     
    if(!Tut1Done)
    {
        DrawText("MOVE THE LEFT ARROW KEY TO MOVE LEFT",0.0f,0.0f,50,WHITE);

        if(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
    {
        if(!leftarrowpressesd)
        {
            pressedtime1=GetTime();
            std::cout<<"The value of leftarrowpressed is "<<leftarrowpressesd<<std::endl;
            leftarrowpressesd=true;
        }
        FinalRectangle.x-=speed;
        if(GetTime()-pressedtime1>=1.0f)
        {
            Tut1Done=true;
            completed=GetTime();
            std::cout<<"The tutorial 1 of movement is completed\n";
        }
    }
    }
    else
    {
        leftcompleted=false;
        if(!congratulationsdone)
        {
            DrawText("CONGRATULATIONS",550,200,50,WHITE);
            std::cout<<"The congratulations from update1 is being displayed\n";
        }
            if((GetTime()-completed>=1.0f))
            {
                congratulationsdone=true;
                update2();
            } 
    }
}

// void TutorialPlayer::update2()
// {
//     if (!Tut2Done)
//     {
//         DrawText("MOVE THE RIGHT ARROW KEY TO MOVE RIGHT", 0.0f, 0.0f, 50, WHITE);

//         if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
//         {
//             if (!rightarrowpressed)
//             {
//                 pressedtime2 = GetTime();
//                 std::cout << "Right arrow pressed at time: " << pressedtime2 << std::endl;
//                 rightarrowpressed = true;
//             }
//             FinalRectangle.x += speed;
//             if (GetTime() - pressedtime2 >= 1.0f)
//             {
//                 Tut2Done = true;
//                 finishes = GetTime();
//                 std::cout << "Tutorial 2 completed at time: " << finishes << std::endl;
//             }
//         }
//     }
//     else
//     {
//         if (!congratulationsfinished)
//         {
//             DrawText("CONGRATULATIONS", 550, 200, 50, WHITE);
//             std::cout << "Displaying congratulations in update2" << std::endl;
//         }

//         if ((GetTime() - finishes >= 1.0f))
//         {
//             congratulationsfinished = true;
//             std::cout << "Calling update3 from update2 at time: " << GetTime() << std::endl;
//             update3(); // Call to update3
//         }
//     }
// }

// void TutorialPlayer::update3()
// {
    
//     if(!Tut3Done)
//     {
//         DrawText("PRESS THE SPACE KEY TO SHOOT BULLETS",0.0f,0.0f,50,WHITE);

//         if(IsKeyDown(KEY_ENTER))
//         {
//             if(!enterkeypressed)
//         {
//             pressedtime3=GetTime();
//             std::cout<<"The value of enterkeypressed is "<<enterkeypressed<<std::endl;
//             enterkeypressed=true;
//         }
//         Bullet newBullet;
//             newBullet.rect = { FinalRectangle.x + FinalRectangle.width / 2 , FinalRectangle.y,(float) B_image.width,(float) B_image.height };
//             // newBullet.speed = { 0,  };
//             newBullet.active = true;
//             bullets.push_back(newBullet);
//         }
//         for (auto& bullet : bullets) 
//         {
//             if (bullet.active) 
//             {
//                 bullet.rect.y += 5;
//                 if (bullet.rect.y < -B_image.height) 
//                 {
//                     bullet.active = false;
//                 }
//             }
//         }
//          bullets.erase(
//             std::remove_if(bullets.begin(), bullets.end(), [](const Bullet& b) { return !b.active; }),
//             bullets.end()
//         );
//         //DrawRectangle(playerPosition.x, playerPosition.y, playerWidth, playerHeight, BLUE);
//         for (const auto& bullet : bullets) {
//             if (bullet.active) {
//                 DrawRectangleRec(bullet.rect, RED);
//             }
//         }

//         if(GetTime()-pressedtime3>=1.0f)
//         {
//             Tut3Done=true;
//             std::cout<<"The tutorial 2 of bullet firing is completed\n";
//         }
//         std::cout<<"The value of pressed time is "<<pressedtime3<<std::endl;
//         std::cout<<"The value of gettime is "<<GetTime()<<std::endl;
//         std::cout<<"The tutorial 1 of movement is not completed\n";
//     }
//     else
//     {
//         DrawText("CONGRATULATIONS",550,200,50,WHITE);
//     }
// }


void TutorialPlayer::update2()
{
    if (!Tut2Done)
    {
        DrawText("MOVE THE RIGHT ARROW KEY TO MOVE RIGHT", 0.0f, 0.0f, 50, WHITE);

        if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
        {
            if (!rightarrowpressed)
            {
                pressedtime2 = GetTime();
                std::cout << "Right arrow pressed at time: " << pressedtime2 << std::endl;
                rightarrowpressed = true;
            }
            FinalRectangle.x += speed;
            if (GetTime() - pressedtime2 >= 1.0f)
            {
                Tut2Done = true;
                finishes = GetTime();
                std::cout << "Tutorial 2 completed at time: " << finishes << std::endl;
            }
        }
    }
    else
    {
        if (!congratulationsfinished)
        {
            DrawText("CONGRATULATIONS", 550, 200, 50, WHITE);
            std::cout << "Displaying congratulations in update2" << std::endl;

            // Wait for 1 second before moving to the next tutorial
            if (GetTime() - finishes >= 1.0f)
            {
                congratulationsfinished = true;
                std::cout << "Calling update3 from update2 at time: " << GetTime() << std::endl;
                update3(); // Call to update3
            }
        }
        else
        {
            update3(); // Continue with update3 after congratulations are done
        }
    }
}
// void TutorialPlayer::update3()
// {
//     if(!Tut3Done)
//     {
//         DrawText("PRESS SPACE TO SHOOT",0.0f,0.0f,50,WHITE);

//         if(IsKeyDown(KEY_SPACE))
//     {
        
//         if(GetTime()-pressedtime2>=1.0f)
//         {
//             Tut3Done=true;
//             std::cout<<"The tutorial 3 of bullet is completed\n";
//         }
//         std::cout<<"The value of pressed time is "<<pressedtime2<<std::endl;
//         std::cout<<"The value of gettime is "<<GetTime()<<std::endl;
//         std::cout<<"The tutorial 1 of movement is not completed\n";
//     }
//     }
//     else
//     {
//         DrawText("CONGRATULATIONS",550,200,50,WHITE);
//     }
// }

void TutorialPlayer::update3()
{
    std::cout << "update3 is called" << std::endl;

    if (!Tut3Done)
    {
        DrawText("PRESS THE SPACE KEY TO SHOOT BULLETS", 0.0f, 0.0f, 50, WHITE);

        if (IsKeyDown(KEY_SPACE))
        {
            if (!enterkeypressed)
            {
                pressedtime3 = GetTime();
                std::cout << "Space key pressed at time: " << pressedtime3 << std::endl;
                enterkeypressed = true;
            }

            // Create and add a new bullet
            Bullet newBullet;
            newBullet.rect = { FinalRectangle.x + FinalRectangle.width / 2, FinalRectangle.y, (float)B_image.width, (float)B_image.height };
            newBullet.active = true;
            bullets.push_back(newBullet);
        }

        // Update bullet positions and remove inactive bullets
        for (auto& bullet : bullets)
        {
            if (bullet.active)
            {
                bullet.rect.y -= 5; // Move bullets up the screen
                if (bullet.rect.y < -B_image.height)
                {
                    bullet.active = false;
                }
            }
        }

        // Remove inactive bullets from the vector
        bullets.erase(
            std::remove_if(bullets.begin(), bullets.end(), [](const Bullet& b) { return !b.active; }),
            bullets.end()
        );

        // Draw active bullets
        for (const auto& bullet : bullets)
        {
            if (bullet.active)
            {
                DrawRectangleRec(bullet.rect, RED);
            }
        }

        // Mark tutorial 3 as done if space key is held for 1 second
        if (enterkeypressed && GetTime() - pressedtime3 >= 1.0f)
        {
            Tut3Done = true;
            std::cout << "Tutorial 3 of bullet firing is completed\n";
        }
    }
    else
    {
        DrawText("CONGRATULATIONS", 550, 200, 50, WHITE);
        screenchanger=true;
        //finalupdate();
        
    }
}

void TutorialPlayer::finalupdate()
{
    
}
