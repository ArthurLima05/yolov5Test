#include "../include/keyboard.h"
#include "../include/utils.h"
#include <conio.h>

int isKeyPressed(char key)
{
    if (_kbhit())
    {
        char ch = _getch();
        return ch == key;
    }
    return 0;
}

void clear_screen()
{
    system("cls");
}
