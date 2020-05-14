#include "Header.h"
#include <iostream>
#include <time.h>
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    char choose;
    cout << "Х или 0?: ";
    cin >> choose;
    while (choose != 'X' && choose != '0') 
    {
       cout << "Х или 0?: ";
       cin >> choose;
    }
    Game mainGame = initGame(choose);
    while (!updateGame(&mainGame))
    {
        if (mainGame.isUserTurn)
        {
            userTurn(&mainGame);
        }
        else
        {
            botTurn(&mainGame);
        }

        updateDisplay(mainGame);
    }
    if (mainGame.status == USER_WIN)
    {
        cout << "Победа";
    }
    else if (mainGame.status == BOT_WIN)
    {
        cout << "Поражение";
    }
    else
    {
        cout << "Ничья";
    }
}