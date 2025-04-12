#include<stdio.h>
#include<windows.h>

void gotoXY(int x, int y);
void BackGround();
void StudentNumber();

int main()
{
    BackGround();
    StudentNumber();
    gotoXY(0, 21);
}

void gotoXY(int x, int y)
{
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void BackGround()
{
    int i=20, j=80;
    gotoXY(0, 0);
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

void StudentNumber()
{
    gotoXY(10, 3);
    printf("\033[41m\033[37m³ª°Ç¿ì\033[0m");
    gotoXY(10, 4);
    printf("\033[40m\033[1;34m20251406\033[0m");
}