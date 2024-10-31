#ifndef GAME_H
#define GAME_H

#include "keyboard.h"

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24

typedef struct
{
    int x, y;
    int velocityX, velocityY;
} Ball;

typedef struct
{
    int x, y;
    int width, height;
} Paddle;

void initializeGame(Ball *ball, Paddle *leftPaddle, Paddle *rightPaddle);
void updateGame(Ball *ball, Paddle *leftPaddle, Paddle *rightPaddle);
void renderGame(Ball *ball, Paddle *leftPaddle, Paddle *rightPaddle);
void processInput(Paddle *leftPaddle, Paddle *rightPaddle);

#endif // GAME_H
