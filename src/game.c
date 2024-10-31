#include "../include/game.h"
#include <stdio.h>
#include <stdlib.h>

void initializeGame(Ball *ball, Paddle *leftPaddle, Paddle *rightPaddle)
{
    ball->x = SCREEN_WIDTH / 2;
    ball->y = SCREEN_HEIGHT / 2;
    ball->velocityX = 1;
    ball->velocityY = 1;

    leftPaddle->x = 1;
    leftPaddle->y = SCREEN_HEIGHT / 2 - 2;
    leftPaddle->width = 1;
    leftPaddle->height = 5;

    rightPaddle->x = SCREEN_WIDTH - 2;
    rightPaddle->y = SCREEN_HEIGHT / 2 - 2;
    rightPaddle->width = 1;
    rightPaddle->height = 5;
}

void updateGame(Ball *ball, Paddle *leftPaddle, Paddle *rightPaddle)
{
    ball->x += ball->velocityX;
    ball->y += ball->velocityY;

    if (ball->y <= 0 || ball->y >= SCREEN_HEIGHT - 1)
    {
        ball->velocityY = -ball->velocityY;
    }

    if (ball->x <= leftPaddle->x + leftPaddle->width &&
        ball->y >= leftPaddle->y && ball->y <= leftPaddle->y + leftPaddle->height)
    {
        ball->velocityX = -ball->velocityX;
    }

    if (ball->x >= rightPaddle->x - rightPaddle->width &&
        ball->y >= rightPaddle->y && ball->y <= rightPaddle->y + rightPaddle->height)
    {
        ball->velocityX = -ball->velocityX;
    }
}

void renderGame(Ball *ball, Paddle *leftPaddle, Paddle *rightPaddle)
{
    system("cls"); // Limpa a tela no Windows
    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        for (int j = 0; j < SCREEN_WIDTH; j++)
        {
            if (j == 0 || j == SCREEN_WIDTH - 1)
            {
                printf("|");
            }
            else if (i == ball->y && j == ball->x)
            {
                printf("O");
            }
            else if (j == leftPaddle->x && i >= leftPaddle->y && i < leftPaddle->y + leftPaddle->height)
            {
                printf("#");
            }
            else if (j == rightPaddle->x && i >= rightPaddle->y && i < rightPaddle->y + rightPaddle->height)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void processInput(Paddle *leftPaddle, Paddle *rightPaddle)
{
    if (isKeyPressed('W') && leftPaddle->y > 0)
    {
        leftPaddle->y--;
    }
    if (isKeyPressed('S') && leftPaddle->y < SCREEN_HEIGHT - leftPaddle->height)
    {
        leftPaddle->y++;
    }
    if (isKeyPressed('I') && rightPaddle->y > 0)
    {
        rightPaddle->y--;
    }
    if (isKeyPressed('K') && rightPaddle->y < SCREEN_HEIGHT - rightPaddle->height)
    {
        rightPaddle->y++;
    }
}
