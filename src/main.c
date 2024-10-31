#include "../include/game.h"
#include "../include/utils.h"
#include <unistd.h> // Para `Sleep` no Windows

int main()
{
    Ball ball;
    Paddle leftPaddle, rightPaddle;

    initializeGame(&ball, &leftPaddle, &rightPaddle);

    while (1)
    {
        processInput(&leftPaddle, &rightPaddle);
        updateGame(&ball, &leftPaddle, &rightPaddle);
        renderGame(&ball, &leftPaddle, &rightPaddle);
        usleep(100); // Pausa de 100ms
    }

    return 0;
}
