#include<math.h>
#include"raylib.h"
#include<string>
#include<fstream>
#include <vector>
#include <algorithm>


typedef struct Bullet{
    Rectangle rect;
    Vector2 speed;
    bool active;
    Color color;
    Texture2D texture;
    Rectangle frameRec;
} Bullet;  

typedef struct Player
{
    Rectangle rect;
    int speed;
    bool active;
    Color color;
    Texture2D texture;
    Rectangle frameRec;
    Rectangle hitbox;
    int currentFrame;
    int frameCounter;
    int frameSpeed;  // Number of frames to show each frame
}Player;

typedef struct Obstacle{
    Rectangle rect;
    int type;
    int speed;
    bool active;
    Color color;
    Texture2D texture;
    Rectangle frameRec;
    Rectangle hitbox;
}Obstacle;

typedef struct Explosion{
    Rectangle rect;
    int frame;
    int frameCounter;
    bool active;
    Texture2D texture;
    Rectangle frameRec;
} Explosion;



//defines
#define NUM_BULLET 50
#define NUM_OBSTACLES 50
#define NUM_EXPLOSION 50

//global variables
static int screenWidth = 1600;
static int screenHeight = 800;
std::string coinfile = "coin.txt";
std::string highscorefile = "highscore.txt";
int coin;
int score;
int highscore;
float elapsedTime = 0.0f;
std::string coinstr = "Coin:";
std::string scorestr = "Score:";
std::string highscorestr = "High Score:";

bool gameOver = false;

static Player player;
static Bullet bullet[NUM_BULLET];
static Obstacle obstacles[NUM_OBSTACLES];
std::vector<Explosion> explosions;

static int shootRate;
static int activeobstacle;
int x, y;
Texture2D explosionTexture;

//sounds
Sound fxexplosion;
Sound fxbullet;


void InitGame(void){
    shootRate = 0;
    activeobstacle = 5;

    //initilize player
    player.rect.x = 800;
    player.rect.y = 600;
    player.rect.height = 150;
    player.rect.width = 150;
    player.hitbox.x = 830;
    player.hitbox.y = 610;
    player.hitbox.height = 140;
    player.hitbox.width = 90;
    player.speed = 8;
    player.color = YELLOW;

    //initilizing texture
    player.texture = LoadTexture("gameres/ship3.png");
    player.frameRec = { 0.0f, 0.0f, (float)player.texture.width / 3, (float)player.texture.height };
    player.currentFrame = 0;
    player.frameCounter = 0;
    player.frameSpeed = 7;  // Adjust this to control the animation speed

    //initalize obstacles
    for (int i = 0; i < NUM_OBSTACLES; i++)
    {   
        obstacles[i].type = GetRandomValue(0,1);
        if(obstacles[i].type == 0){
            obstacles[i].rect.width = GetRandomValue(70,120);
            obstacles[i].rect.height = GetRandomValue(70,120);
            obstacles[i].hitbox.width = obstacles[i].rect.width;
            obstacles[i].hitbox.height = obstacles[i].rect.height;
        }
        else{
            obstacles[i].rect.width = GetRandomValue(120,180);
            obstacles[i].rect.height = GetRandomValue(120,180);
            obstacles[i].hitbox.width = obstacles[i].rect.width;
            obstacles[i].hitbox.height = obstacles[i].rect.height;
        }
        obstacles[i].rect.y = GetRandomValue(-screenHeight, -20);
        obstacles[i].rect.x = GetRandomValue(0,screenWidth-obstacles[i].rect.width);
        obstacles[i].hitbox.x = obstacles[i].rect.x;
        obstacles[i].hitbox.y = obstacles[i].rect.y;
        obstacles[i].speed = 8;
        obstacles[i].active = true;
        obstacles[i].color = RED;
         //initilizing texture
        
        if(obstacles[i].type == 0)
            obstacles[i].texture = LoadTexture("gameres/astroid.png");
        else
            obstacles[i].texture = LoadTexture("gameres/satallite.png");
        obstacles[i].frameRec = { 0.0f, 0.0f, (float)obstacles[i].texture.width, (float)obstacles[i].texture.height };
    }
    
    //initilize bullet
    for (int  i = 0; i < NUM_BULLET; i++)
    {
        bullet[i].rect.x=800;
        bullet[i].rect.y=700;
        bullet[i].rect.height=30;
        bullet[i].rect.width=20;
        bullet[i].speed.x=0;
        bullet[i].speed.y=-10;
        bullet[i].active = false;
        bullet[i].color = GREEN;
        //initilizing texture
        bullet[i].texture = LoadTexture("gameres/bullet.png");
        bullet[i].frameRec = { 0.0f, 0.0f, (float)bullet[i].texture.width, (float)bullet[i].texture.height };
    }


    // Read coin from file
    std::ifstream infile(coinfile);
    if (infile.is_open()) {
        infile >> coin;
        infile.close();
    } else {
        coin = 0; // Initialize to 0 if file doesn't exist
    }
    // Read high score from file
    std::ifstream highscorefile_in(highscorefile);
    if (highscorefile_in.is_open()) {
        highscorefile_in >> highscore;
        highscorefile_in.close();
    } else {
        highscore = 0; // Initialize to 0 if file doesn't exist
    }
    //player frames
    // Update animation frame
    player.frameCounter++;
    if (player.frameCounter >= (60 / player.frameSpeed)) {
        player.frameCounter = 0;
        player.currentFrame++;
        if (player.currentFrame > 2) player.currentFrame = 0;
        player.frameRec.x = (float)player.currentFrame * (float)player.texture.width / 3;
    }
    score = 1;

    explosionTexture = LoadTexture("gameres/explosion.png");
    fxexplosion = LoadSound("gameres/explosion.wav");
    //bullet sound
    fxbullet =LoadSound("gameres/bullet.mp3");
    
};
void UpdateGame(void){

    score++;
      // Increase difficulty every 1000 points
    if (score % 1000 == 0) {
        activeobstacle++;
        for (int i = 0; i < activeobstacle; i++) {
            obstacles[i].speed += 2;  // Increase obstacle speed by 2
        }
    }

    //player movement
    if(IsKeyDown(KEY_A)){
        player.rect.x  -=player.speed;
        player.hitbox.x  -=player.speed;
    }
    if(IsKeyDown(KEY_D)){
        player.rect.x  +=player.speed;
        player.hitbox.x  +=player.speed;
    }

    //wall behavour
    if(player.rect.x<0){
        player.rect.x = (screenWidth-player.rect.width);
        player.hitbox.x = screenWidth-player.hitbox.width;
    }
    if(player.rect.x+player.rect.width>=screenWidth){
        player.rect.x = 0;
         player.hitbox.x = 0;
    }

    //player animation update
     player.frameCounter++;
    if (player.frameCounter >= (60 / player.frameSpeed)) {
        player.frameCounter = 0;
        player.currentFrame++;
        if (player.currentFrame > 2) player.currentFrame = 0;
        player.frameRec.x = (float)player.currentFrame * (float)player.texture.width / 3;
    }

    //enemy behivour
    for (int i = 0; i < activeobstacle; i++)
    {
       if(obstacles[i].active){
        obstacles[i].rect.y += obstacles[i].speed;
        obstacles[i].hitbox.y +=obstacles[i].speed;
       }
       if(obstacles[i].rect.y>screenHeight){
        obstacles[i].rect.x = GetRandomValue(0,screenWidth);
        obstacles[i].rect.y = GetRandomValue(-screenHeight, -20);
        obstacles[i].hitbox.x = obstacles[i].rect.x;
        obstacles[i].hitbox.y = obstacles[i].rect.y; 
       }
       //player collision
       if(CheckCollisionRecs(obstacles[i].hitbox,player.hitbox)){
        gameOver = true;
       }

    }
    

    
    //bullet inilization
    if (IsKeyDown(KEY_SPACE)){

        shootRate +=5;

        for (int i = 0; i < NUM_BULLET; i++)
        {
            if(!bullet[i].active && shootRate % 40 == 0){
                 PlaySound(fxbullet);
                bullet[i].rect.x = (player.rect.x+(player.rect.width/2)-(bullet[i].rect.width/2));
                bullet[i].rect.y = player.rect.y-(player.rect.height/4);
                bullet[i].active = true;
                break;
            }
        }
         
    }
    //shoot logic
    for (int i = 0; i < NUM_BULLET; i++)
    {
        if(bullet[i].active){   
            //movement
            
            bullet[i].rect.y += bullet[i].speed.y;

            if(bullet[i].rect.y <= 0)//goes above screen
            {
                bullet[i].active = false;
                shootRate = 0;
            }
            //collision
            for (int  j = 0; j < activeobstacle; j++)
            {
                 if (obstacles[j].active)
                {
                    if(CheckCollisionRecs(bullet[i].rect,obstacles[j].hitbox)){
                        bullet[i].active = false;
                        //explosion inatilize
                        Explosion explosion = { 
                            obstacles[j].rect,
                            0,
                            0, 
                            true, 
                            explosionTexture, 
                            {0, 0, 64, 64} };
                        explosions.push_back(explosion);
                        obstacles[j].rect.x = GetRandomValue(0,screenWidth-player.rect.width);
                        obstacles[j].hitbox.x = obstacles[j].rect.x;
                        obstacles[j].rect.y = -obstacles[j].rect.height;
                        obstacles[j].hitbox.y = obstacles[j].rect.y;
                        coin ++;
                        //explosion sound
                         PlaySound(fxexplosion);
                        //explosion
                        
                        
                    }
                }
        
            }
        }
    }
    // Update explosions
    for (Explosion& explosion : explosions) {
        if (explosion.active) {
            explosion.frameCounter++;
            if (explosion.frameCounter >= 5) {  // Adjust this value to control animation speed
                explosion.frameCounter = 0;
                explosion.frame++;
                if (explosion.frame >= 8) {
                    explosion.active = false;  // Explosion animation finished
                } else {
                    explosion.frameRec.x = explosion.frame * 64;
                }
            }
        }
    }
}

void DrawGame(void){
    BeginDrawing();

    ClearBackground(BLACK);

    //drawing player
     DrawRectangleRec(player.hitbox,CLITERAL(Color){ 255, 255, 255, 1 });
     DrawTexturePro(
        player.texture, 
        player.frameRec, 
        (Rectangle){player.rect.x, player.rect.y, player.rect.width, player.rect.height}, 
        (Vector2){0, 0}, 
        0.0f, 
        WHITE
    );
        

    //darwing obstacle
    for (int i = 0; i < activeobstacle; i++)
    {
       if (obstacles[i].active)
       {    elapsedTime = GetTime();
          DrawRectanglePro({
            obstacles[i].hitbox.x,
            obstacles[i].hitbox.y,
            obstacles[i].hitbox.width,
            obstacles[i].hitbox.height},
            {obstacles[i].hitbox.width/2, obstacles[i].hitbox.height/2},
             45*elapsedTime, 
            CLITERAL(Color){ 255, 255, 255, 1 });
          DrawTexturePro(
            obstacles[i].texture,
            obstacles[i].frameRec,
            obstacles[i].rect, 
            {obstacles[i].rect.width/2, obstacles[i].rect.height/2},
            45*elapsedTime, 
             WHITE);
       }
       
    }
    

    for (int i = 0; i < NUM_BULLET; i++)
    {
       if(bullet[i].active){
            DrawTexturePro(bullet[i].texture, bullet[i].frameRec, bullet[i].rect, {0,0}, 0.0f, WHITE);
       }
    }

    //explosion
     for (Explosion& explosion : explosions) {
        if (explosion.active) {
            //DrawTextureRec(explosion.texture, explosion.frameRec, { explosion.rect.x, explosion.rect.y }, WHITE);
            DrawTexturePro(explosion.texture,explosion.frameRec, explosion.rect, {0,0}, 0.0f, WHITE);
        }
    }

    //score and coin
    DrawText(coinstr.c_str(),(screenWidth-150),0,20,WHITE);
    DrawText(std::to_string(coin).c_str(),(screenWidth-70),0,20,WHITE);
    DrawText(scorestr.c_str(),(screenWidth-150),20,20,WHITE);
    DrawText(std::to_string(score).c_str(),(screenWidth-70),20,20,WHITE);
    DrawText(highscorestr.c_str(),(screenWidth-200),40,20,WHITE);
    DrawText(std::to_string(highscore).c_str(),(screenWidth-70),40,20,WHITE);
    
    EndDrawing();
}
void UpdateDrawFrame(void){
    UpdateGame();
    DrawGame();
}
void UnloadGame(void){
    //unload texture
     UnloadTexture(player.texture);
     for (int i = 0; i < NUM_OBSTACLES; i++) {
        UnloadTexture(obstacles[i].texture);
    }
       UnloadTexture(explosionTexture);
       //unload sounds
       UnloadSound(fxexplosion);
       UnloadSound(fxbullet);

    // Save the coin count to the file
    std::ofstream outfile(coinfile);
    if (outfile.is_open()) {
        outfile << coin;
        outfile.close();
    } 
    // Save the high score to the file if it's been updated
    if (score > highscore) {
        std::ofstream highscorefile_out(highscorefile);
        if (highscorefile_out.is_open()) {
            highscorefile_out << score;
            highscorefile_out.close();
        }
    }  
}


int main(){
    InitWindow(screenWidth,screenHeight,"bullet screen");
    InitAudioDevice(); // Initialize the audio device
    //initilize game
    InitGame();

    SetTargetFPS(60);

    while (!WindowShouldClose()&&  !gameOver)//
    {
        UpdateDrawFrame();
       
    }

    if (gameOver) {
        while (!WindowShouldClose()) {
            // Final draw to show game over screen
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Game Over!", screenWidth / 2 - MeasureText("Game Over!", 40) / 2, screenHeight / 2 - 20, 40, RED);
        EndDrawing();
        }
    }
    
    UnloadGame(); 
    CloseAudioDevice();
    CloseWindow();
    return 0;
}