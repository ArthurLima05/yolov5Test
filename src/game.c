#include "../include/game.h"
#include "../include/utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <cli.h>

Ball ball;
Paddle player1, player2;

void init_game()
{
    ball.x = WIDTH / 2;
    ball.y = HEIGHT / 2;
    player1.x = 2;
    player1.y = HEIGHT / 2 - 3;
    player1.length = 6;
    player2.x = WIDTH - 3;
    player2.y = HEIGHT / 2 - 3;
    player2.length = 6;
}

void update_game()
{
    ball.x += 1;
    if (check_collision())
    {
        ball.x *= -1;
    }
}

void render_game()
{
    clear_screen();
    move_cursor(ball.x, ball.y);
    printf("O");

    for (int i = 0; i < player1.length; i++)
    {
        move_cursor(player1.x, player1.y + i);
        printf("|");
    }

    for (int i = 0; i < player2.length; i++)
    {
        move_cursor(player2.x, player2.y + i);
        printf("|");
    }
}

void handle_input()
{
    if (cli_key_pressed(CLI_KEY_W))
    {
        if (player1.y > 0)
        {
            player1.y -= 1;
        }
    }
    if (cli_key_pressed(CLI_KEY_S))
    {
        if (player1.y + player1.length < HEIGHT)
        {
            player1.y += 1;
        }
    }

    if (cli_key_pressed(CLI_KEY_UP))
    {
        if (player2.y > 0)
        {
            player2.y -= 1;
        }
    }
    if (cli_key_pressed(CLI_KEY_DOWN))
    {
        if (player2.y + player2.length < HEIGHT)
        {
            player2.y += 1;
        }
    }
}
