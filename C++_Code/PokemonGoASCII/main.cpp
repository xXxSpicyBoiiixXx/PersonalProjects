#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Graphics.h"


void ShowConsoleCursor(bool showFlag);

using namespace std;

int main()
{
    string name;

    cout << "Enter in your name: ";

    cin >> name;

    ShowConsoleCursor(false);

    bool hit;

    Graphics console(name);

    console.draw();

    int count = 0;
    char a;

    while(a != 'q')
    {
        if(kbhit())
        {
            a = getch();
        }
        else
        {
            a = '`';
        }

        if(a != '`')
        {
            console.move(a);
            hit = true;
        }
        if(console.eventTriggered() && hit)
        {
            console.event();
            console.draw();
            hit = false;
        }

        if(rand()%112816 == 0 && count > 10)
        {
            count = 0;
            console.movePokemon();
        }
        else
        {
            count ++;
        }
    }

    return 0;
}
