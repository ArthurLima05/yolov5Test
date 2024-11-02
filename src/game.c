#include "../include/game.h"
#include "../include/utils.h"
#include <ncurses.h>
#include <stdlib.h>
#include "../include/screen.h"

void initializeGame(Ball *ball, Paddle *leftPaddle, Paddle *rightPaddle)
{
    ball->x = COLS / 2; // Centraliza a bola
    ball->y = LINES / 2;
    ball->dx = 1; // Direção inicial da bola
    ball->dy = 1;

    leftPaddle->x = 1;             // Posição do paddle esquerdo
    leftPaddle->y = LINES / 2 - 1; // Centraliza verticalmente
    leftPaddle->width = 1;         // Largura do paddle
    leftPaddle->height = 3;        // Altura do paddle

    rightPaddle->x = COLS - 2;      // Posição do paddle direito
    rightPaddle->y = LINES / 2 - 1; // Centraliza verticalmente
    rightPaddle->width = 1;         // Largura do paddle
    rightPaddle->height = 3;        // Altura do paddle
}
void renderGame(Ball *ball, Paddle *leftPaddle, Paddle *rightPaddle)
{
    clearScreen(); // Limpa a tela

    // Renderiza a bola
    mvprintw(ball->y, ball->x, "O");

    // Renderiza o paddle esquerdo
    for (int i = 0; i < leftPaddle->height; i++)
    {
        mvprintw(leftPaddle->y + i, leftPaddle->x, "|"); // Exibe o paddle esquerdo
    }

    // Renderiza o paddle direito
    for (int i = 0; i < rightPaddle->height; i++)
    {
        mvprintw(rightPaddle->y + i, rightPaddle->x, "|"); // Exibe o paddle direito
    }

    refresh(); // Atualiza a tela
}
void updateGame(Ball *ball, Paddle *leftPaddle, Paddle *rightPaddle)
{
    // Atualiza a posição da bola
    ball->x += ball->dx;
    ball->y += ball->dy;

    // Verifica colisão com o teto e o chão
    if (ball->y <= 0 || ball->y >= LINES - 1)
    {
        ball->dy *= -1; // Inverte a direção
    }

    // Verifica colisão com paddles
    if (ball->x <= leftPaddle->x + leftPaddle->width &&
        ball->y >= leftPaddle->y &&
        ball->y < leftPaddle->y + leftPaddle->height)
    {
        ball->dx *= -1; // Inverte a direção horizontal
    }

    if (ball->x >= rightPaddle->x - rightPaddle->width &&
        ball->y >= rightPaddle->y &&
        ball->y < rightPaddle->y + rightPaddle->height)
    {
        ball->dx *= -1; // Inverte a direção horizontal
    }

    // Reseta a bola se ela sair pela esquerda ou direita
    if (ball->x < 0 || ball->x >= COLS)
    {
        ball->x = COLS / 2;
        ball->y = LINES / 2;
    }
}