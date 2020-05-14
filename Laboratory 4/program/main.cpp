#include "Header.h"
#include <iostream>
#include <time.h>
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    char choose;
    cout << "� ��� 0?: ";
    cin >> choose;
    while (choose != 'X' && choose != '0') 
    {
       cout << "� ��� 0?: ";
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
        cout << "������";
    }
    else if (mainGame.status == BOT_WIN)
    {
        cout << "���������";
    }
    else
    {
        cout << "�����";
    }
}