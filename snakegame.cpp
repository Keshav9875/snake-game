// snake game by c++

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

bool gameover = 0;
int height = 20, width = 20;
char name[30];
char fruit = '$';
int x, y, eatx, eaty, score = 0, counttail = 0;
int tailx[100], taily[100];

void create()
{
    cout << "Enter your name:- ";
    cin >> name;
    gameover = 0;
    x = width / 2;
    y = height / 2;

label1:
    eatx = rand() % width;
    if (eatx == 0)
    {
        goto label1;
    }

label2:
    eaty = rand() % height;
    if (eaty == 0)
    {
        goto label2;
    }
}

void panel_draw()
{

    system("cls");
    cout << "=>=>=>=>=>=>=>=>=>=>=>=>SNAKE GAME<=<=<=<=<=<=<=<=<=<=<=<=" << endl
         << endl
         << endl;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
            { // use setconsolcursor position here later.
                cout << "#";
            }
            else
            {
                if (j == x && i == y)
                {
                    cout << "0";
                }
                else if (j == eatx && i == eaty)
                {
                    cout <<fruit;
                }
                else
                {
                    int excutespace = 0;

                    for (int k = 0; k < counttail; k++)
                    {
                        if (j == tailx[k] && i == taily[k])
                        {

                            cout << "o";
                            excutespace = 1;
                        }
                    }
                    if (excutespace == 0)
                    {
                        cout << " ";
                    }
                }
            }
        }
        cout << endl;
    }
    cout << name << "'s"
         << " SCORE:-" << score;
}
void Mainlogic_and_input()
{

    // for tail
    int i;
    int previousx, previousy, previous2x, previous2y;

    previousx = tailx[0];
    previousy = taily[0];
    tailx[0] = x;
    taily[0] = y;

    for (i = 1; i < counttail; i++)
    {
        previous2x = tailx[i];
        previous2y = taily[i];
        tailx[i] = previousx;
        taily[i] = previousy;
        previousx = previous2x;
        previousy = previous2y;
    }

    if (kbhit())
    {
        switch (getch())
        {
        case 'a':
            x--;
            break;
        case 'd':
            x++;
            break;

        case 'w':
            y--;
            break;

        case 'x':
            y++;
            break;

        default:
            break;
        }
    }

    if (x == eatx && y == eaty)
    {

    label3:
        eatx = rand() % width;
        if (eatx == 0)
        {
            goto label3;
        }

    label4:
        eaty = rand() % height;
        if (eaty == 0)
        {
            goto label4;
        }

        score = score + 1;
        counttail++;
    }

    if (x < 1 || x > width - 2 || y < 1 || y > height - 2)
    {

        gameover = 1;
        system("cls");
        getch();
        cout << endl
             << endl
             << "GAME END" << endl;
        cout << name << " score = " << score << endl;
        cout << "Thanks for playing My snake game." << endl;
        cout << "Made by:- keshav garg." << endl;

        getch();
        exit(0);
    }
}

int main()
{
    system("cls");
    system("color 4a");

    cout << "=>=>=>=>=>=>=>=>=>=>=>=>SNAKE GAME<=<=<=<=<=<=<=<=<=<=<=<=" << endl
         << endl
         << endl;
    cout << "The instruction for the snake game are written below please read carefully:- " << endl
         << endl;
    cout << "1.Press the key W for moving upwards." << endl;
    cout << "2.Press the key a for moving Left." << endl;
    cout << "3.Press the key d for moving Right." << endl;
    cout << "4.Press the key x for moving down." << endl;
    cout << "5.If you touch the wall or boundary then gameover." << endl
         << endl
         << endl;
    create();

    system("cls");

    while (gameover != 1)
    {
        panel_draw();
        Mainlogic_and_input();
        for (int i = 0; i < 1000; i++)
        {
            for (int j = 1; j < 10000; j++)
            {
            }
        }
        for (int i = 0; i < 100; i++)
        {
            for (int j = 1; j < 100; j++)
            {
            }
        }

        Sleep(90);
    }

    getch();
    return 0;
}