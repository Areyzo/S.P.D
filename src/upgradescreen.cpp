#include "upgradescreen.hpp"
#include<string>
#include<fstream>
#include<iostream>
using namespace std;

upgradescreen::upgradescreen()
{   
    background = LoadTexture("Graphics/gameres/bg.png");
    scale = 2.0; 
    background1 = LoadTexture("Graphics/gameres/bgupgrade.png");
    scale1 = 2.0; 


    image=LoadTexture("Graphics/block.png");
    InitialRectangle={0.0f,0.0f,(float)image.width/noofframes,(float)image.height};
    FinalRectangle={400,200,(float)image.width/noofframes*(1.0f),(float)image.height*(1.0f)};


    up=LoadTexture("Graphics/upgrade1.png");
    UIR = {0.0f, 0.0f, (float)(up.width / 3), (float)up.height};
    UFR = {650.0f, 550.0f, (float)(up.width / noofframes) * 3.0f, (float)up.height * 3.0f};

    ship1=LoadTexture("Graphics/ship1.png");
    S1IR={0.0f,0.0f,(float)ship1.width/spaceship_totalframe,(float)ship1.height};
    S1FR={710,310,(float)ship1.width/spaceship_totalframe*(3.0f),(float)ship1.height*(3.0f)};

    ship2=LoadTexture("Graphics/ship2.png");
    S2IR={0.0f,0.0f,(float)ship2.width/spaceship_totalframe,(float)ship2.height};
    S2FR={710,310,(float)ship2.width/spaceship_totalframe*(3.0f),(float)ship2.height*(3.0f)};

    ship3=LoadTexture("Graphics/ship3.png");
    S3IR={0.0f,0.0f,(float)ship3.width/spaceship_totalframe,(float)ship3.height};
    S3FR={710,310,(float)ship3.width/spaceship_totalframe*(3.0f),(float)ship3.height*(3.0f)};
}

upgradescreen::~upgradescreen()
{
    UnloadTexture(image);
    UnloadTexture(background);
    UnloadTexture(background1);
    UnloadTexture(up);
    UnloadTexture(ship1);
    UnloadTexture(ship2);
    UnloadTexture(ship3);
}

void upgradescreen::draw()
{   
    DrawTextureEx(background, (Vector2){ 0, scrollingBack}, 0.0f, scale, WHITE);
    DrawTextureEx(background, (Vector2){0, -background.height*scale + scrollingBack }, 0.0f, scale, WHITE);
    DrawTextureEx(background1, (Vector2){ 0, scrollingBack1}, 0.0f, scale1, WHITE);
    DrawTextureEx(background1, (Vector2){0, -background1.height*scale + scrollingBack1 }, 0.0f, scale, WHITE);
    
    InitialRectangle.x=currentframe*image.width/noofframes;
    DrawTexturePro(image,InitialRectangle,FinalRectangle,Vector2{0,0},0.0f,WHITE);
    

}

void upgradescreen::update()
{
    scrollingBack = scrollingBack+0.2f;
     if (scrollingBack >= background.height*scale) scrollingBack = -background.height*scale;
     scrollingBack1 = scrollingBack1+0.4f;
     if (scrollingBack1 >= background1.height*scale1) scrollingBack1 = -background1.height*scale1;

    framecounter++;
    if(framecounter>60/10)
    {
        framecounter=0;
        currentframe++;
        if(currentframe>noofframes-1)
        {
            currentframe=0;
        }
    }
}


void upgradescreen::draw_coins()
{
    std::string coinfile = "coin.txt";
    std::ifstream infile(coinfile);
    std::string coinstr = "Coin:";
    if (infile.is_open()) 
    {
        infile >> coin;
        infile.close();
    } 
    else 
    {
        coin = 0; 
    }

    DrawText(coinstr.c_str(), 1600 - 170, 10, 24, WHITE);
    DrawText(std::to_string(coin).c_str(), 1600 - 70, 10, 24, WHITE);
}

void upgradescreen::coin_updation()
{
    int targetstring=9000;
    int filestring;

    std::ifstream inFile("coin.txt");

    inFile>>filestring;

    inFile.close();

    if(filestring>=targetstring)
    {
        std::cout<<"The coins are enough for the updation\n";
        std::ofstream outFile("coin.txt");

        outFile<<(filestring-targetstring);

        outFile.close();

        coin_counter++;
        if(coin_counter>3)
        {
            coin_counter=3;
        }
        
        std::ofstream SFile("SpaceShip.txt");

        SFile<<coin_counter;

        cout<<"The value of coin_counter is "<<coin_counter<<endl;

        SFile.close();
    }

}


bool upgradescreen::IsButtonClicked(Rectangle rect)
{
    return (CheckCollisionPointRec(GetMousePosition(),rect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON));
}


void upgradescreen::draw_up()
{
    UIR.x=ucf*up.width/3;
    DrawTexturePro(up,UIR,UFR,Vector2{0,0},0.0f,WHITE);
}


void upgradescreen::finaldrawing()
{
    std::cout << "finaldrawing() function entered" << std::endl;
    switch(coin_counter)
    {
        case 1:
    {
        s1_draw();
        s1_update();
        cout<<"The value of coin counter is "<<coin_counter<<endl;
        cout<<"In CASE 1\n";
        break;
    }
    case 2:
    {
        s2_draw();
        s2_update();
        break;
    }
    case 3:
    {
        s2_draw();
        s2_update();
        break;
    }
    default:
    {
        cout<<"Value doesn't match\n";
        break;
    }
    }
    
}

void upgradescreen::initialdrawing()
{
    int counter;
    std::ifstream File("SpaceShip.txt");

    File>>counter;

    File.close();

    switch(counter)
    {
        case 1:
    {
        s1_draw();
        s1_update();
        cout<<"The value of coin counter is "<<coin_counter<<endl;
        cout<<"In CASE 1\n";
        break;
    }
    case 2:
    {
        s2_draw();
        s2_update();
        break;
    }
    case 3:
    {
        s3_draw();
        s3_update();
        break;
    }
    default:
    {
        cout<<"Value doesn't match\n";
        break;
    }
    }

}

void upgradescreen::up_up()
{
    initialdrawing();
    if(!up_clickState && IsButtonClicked(UFR))
    {
        ucf=1;
        up_clickState=true;
        up_clicktime1=GetTime();
        std::cout<<"The second frame is displayed\n";
        std::cout<<"The time when the button is clicked is "<<up_clicktime1<<std::endl;
    }

    if(up_clickState && (GetTime()-up_clicktime1>=up_delaytime1))
    {
        ucf=2;
        up_clicktime2=GetTime();
        coin_updation();
        s_screenchange=true;
        up_clickState=false;
        std::cout<<"The thrid/first frame is displayed\n";
        std::cout<<"The time when the button is clicked is "<<up_clicktime2<<std::endl;
    }

    if(s_screenchange && (GetTime()-up_clicktime2>=up_delaytime2))
    {
        finaldrawing();
        std::cout << "finaldrawing() called, coin_counter = " << coin_counter << std::endl;
        std::cout<<"The shapeship is changed\n";
        //s_screenchange=false;
        
    }
}

void upgradescreen::s1_draw()
{
    S1IR.x=ship1.width*s1_currentframe/(spaceship_totalframe);
    DrawTexturePro(ship1,S1IR,S1FR,Vector2{0,0},0.0f,WHITE);
}

void upgradescreen::s1_update()
{
    s1_framecounter++;
    if(s1_framecounter>=60/10)
    {
        s1_framecounter=0;
        s1_currentframe++;
        if(s1_currentframe>spaceship_totalframe-1)
        {
            s1_currentframe=0;
        }
    }
}

void upgradescreen::s2_draw()
{
    S2IR.x=ship2.width*s2_currentframe/(spaceship_totalframe);
    DrawTexturePro(ship2,S2IR,S2FR,Vector2{0,0},0.0f,WHITE);
}

void upgradescreen::s2_update()
{
    s2_framecounter++;
    if(s2_framecounter>=60/10)
    {
        s2_framecounter=0;
        s2_currentframe++;
        if(s2_currentframe>spaceship_totalframe-1)
        {
            s2_currentframe=0;
        }
    }

}

void upgradescreen::s3_draw()
{
    S3IR.x=ship3.width*s3_currentframe/(spaceship_totalframe);
    DrawTexturePro(ship3,S3IR,S3FR,Vector2{0,0},0.0f,WHITE);
}

void upgradescreen::s3_update()
{
    s3_framecounter++;
    if(s3_framecounter>=60/10)
    {
        s3_framecounter=0;
        s3_currentframe++;
        if(s3_currentframe>spaceship_totalframe-1)
        {
            s3_currentframe=0;
        }
    }

}
