// // #include"upgradebutton.hpp"
// // #include<iostream>

// // upgradebutton::upgradebutton()
// // {
// //     image=LoadTexture("Graphics/play1.png");
// //     InitailRectangle={0.0f,0.0f,(float)(image.width/noofframes),(float)image.height};
// //     FinalRectangle={800.0f,550.0f,(float)(image.width/noofframes)*5.0f,(float)image.height*5.0f};
// // }

// // upgradebutton::~upgradebutton()
// // {
// //     UnloadTexture(image);
// // }

// // void upgradebutton::draw()
// // {
// //     InitailRectangle.x=currentframe*image.width/noofframes;
// //     DrawTexturePro(image,InitailRectangle,FinalRectangle,Vector2{0,0},0.0f,WHITE);
// // }

// // void upgradebutton::update()
// // {
// //     if(IsMouseHovered(FinalRectangle))
// //     {
// //         if(!hoverState)
// //         {
// //             currentframe=1;
// //             hoverState=true;
// //         }
// //     if(IsMouseClicked(FinalRectangle) && !clickState)
// //     {
// //         currentframe=2;
// //         clickState=true;
// //         clicktime=GetTime();
// //         std::cout<<"The button is clicked\n";
// //     }
// //     if(clickState && (GetTime()-clicktime>=delaytime))
// //     {
// //         screenChanger=true;
// //     }
// //     }
// //     else
// //     {
// //         clickState=false;
// //         hoverState=false;
// //         currentframe=0;
// //     }
// // }


// // bool upgradebutton::IsMouseHovered(Rectangle rec)
// // {
// //     return (CheckCollisionPointRec(GetMousePosition(),rec));
// // }

// // bool upgradebutton::IsMouseClicked(Rectangle rec)
// // {
// //     return (CheckCollisionPointRec(GetMousePosition(),rec) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON));
// // }

// // void upgradebutton::reset()
// // {
// //     clickState=false;
// //     hoverState=false;
// //     currentframe=0;
// //     clicktime=0.0f;
// //     screenChanger=false;
// // }

// #include"upgradebutton.hpp"
// #include<raylib.h>
// #include<iostream>


// upgradebutton::upgradebutton()
// {
//     image =LoadTexture("Graphics/play1.png");
//     InitailRectangle={0.0f,0.0f,(float)image.width/noofframes,(float)image.height};
//     FinalRectangle ={800,550,((float)image.width/noofframes)*5.0f,(float)image.height*5.0f};
// }
// upgradebutton::~upgradebutton()
// {
//     UnloadTexture(image);
// }

// void upgradebutton::draw()
// {
//     InitailRectangle.x=currentframe*image.width/noofframes;
//     DrawTexturePro(image,InitailRectangle,FinalRectangle,Vector2{0,0},0,WHITE);
// }

// void upgradebutton::update()
// {
//         if(IsMouseHovered(FinalRectangle))
//         {
//             if(!hoverState)
//             {
//                 currentframe=1;
//                 hoverState=true;
//                 std::cout<<"The mouse is being hovered\n";
//             }
//             if(IsButtonClicked(FinalRectangle) && !clickState)
//             {
//                 currentframe=2;
//                 clickState=true;
//                 clicktime=GetTime();
//                 std::cout<<"The button in clicked\n";
//             }

//             if(clickState && (GetTime()-clicktime>=delaytime))
//             {
//                 screenChanger=true;
//             }
//         } 
//         else
//         {
//             std::cout<<"The mouse is not being hovered\n";
//             hoverState=false;
//             clickState=false;
//             currentframe=0;
//         }
// }

// bool upgradebutton::IsMouseHovered(Rectangle rect)
// {
//     return (CheckCollisionPointRec(GetMousePosition(),rect));
// }

// bool upgradebutton::IsButtonClicked(Rectangle rect)
// {
//     return (CheckCollisionPointRec(GetMousePosition(),rect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON));
// }

// void upgradebutton::reset()
// {
//     currentframe=0;
//     //framecounter=0;
//     hoverState=false;
//     clickState=false;
//     clicktime=0.0f;
//     screenChanger=false;
// }


// #include<raylib.h>
// #include"buttons.hpp"
// #include<iostream>

// upgradebutton::upgradebutton()
// {
//     image=LoadTexture("Graphics/play1.png");
//     InitialRectangle={0.0f,0.0f,(float)(image.width/noofframes),(float)image.height};
//     FinalRectangle={800.0f,550.0f,(float)(image.width/noofframes)*5.0f,(float)image.height*5.0f};
// }

// upgradebutton::~upgradebutton()
// {
//     UnloadTexture(image);
// }

// void upgradebutton::draw()
// {
//     InitialRectangle.x=currentframe*image.width/noofframes;
//     DrawTexturePro(image,InitialRectangle,FinalRectangle,Vector2{0,0},0.0f,WHITE);
// }

#include "upgradebutton.hpp"
#include <iostream>

upgradebutton::upgradebutton() {
    image = LoadTexture("Graphics/play1.png");
    InitialRectangle = {0.0f, 0.0f, (float)(image.width / noofframes), (float)image.height};
    FinalRectangle = {800.0f, 550.0f, (float)(image.width / noofframes) * 5.0f, (float)image.height * 5.0f};
}

upgradebutton::~upgradebutton() {
    UnloadTexture(image);
}

void upgradebutton::draw() {
    InitialRectangle.x = currentframe * image.width / noofframes;
    DrawTexturePro(image, InitialRectangle, FinalRectangle, Vector2{0, 0}, 0.0f, WHITE);
}


