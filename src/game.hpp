#pragma once

int game();

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

void InitGame();
void UpdateGame(void);
void DrawGame(void);
void UpdateDrawFrame(void);
void UnloadGame(void);




