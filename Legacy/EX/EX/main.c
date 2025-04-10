#include <windows.h>
#include <stdio.h>

void gotoXY(int x, int y);
void printMap();
void keyStar(int x, int y);

int main()
{
    printMap();
    keyStar(10, 10);

    return 0;
}

void gotoXY(int x, int y)
{
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void printMap()
{
    gotoXY(0, 0);
    int i = 20, j = 80;
    while (i)
    {
        j = 80;
        while (j)
        {
            printf("\033[44m \033[0m");
            j = j - 1;
        }
        printf("\n");
        i = i - 1;
    }
}

void keyStar(int x, int y)
{
    gotoXY(x, y);
    char c = '[';
    int i = 5;
    int j = 5;
    while (j)
    {
        while (i)
        {
            c = _getch();
            if (c == 'q')
            {
                i = 0;
            }

            if (c == 'a')
            {
                printf("\033[43m\033[32m*\033[0m");
            }

            if (c == '\r')
            {
                y = y + 1;
                gotoXY(x, y);
            }
            i = i - 1;
        }
        y = y - 1;
        gotoXY(x, y);
        j = j-1;
    }

}
