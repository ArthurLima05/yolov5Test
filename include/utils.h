#ifndef UTILS_H
#define UTILS_H
#define WIDTH 80
#define HEIGHT 24

typedef struct
{
    int x, y;
} Ball;

typedef struct
{
    int x, y, length;
} Paddle;

void clear_screen();
void move_cursor(int x, int y);
#endif