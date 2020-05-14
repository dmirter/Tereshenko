#include "Header.h"
#include <iostream>
#include <time.h>
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    char s;
    cout << "Õ èëè 0?: ";
    cin >> s;
    while (s != 'X' && s != '0') 
    {
       cout << "Õ èëè 0?: ";
       cin >> choose;
    }
    Game game = initGame(s);
    while (!updateGame(&game))
    {
        if (game.isUserTurn)
        {
            userTurn(&game);
        }
        else
        {
            botTurn(&game);
        }

        updateDisplay(game);
    }
    if (game.status == USER_WIN)
    {
        cout << "Ïîáåäà";
    }
    else if (game.status == BOT_WIN)
    {
        cout << "Ïîðàæåíèå";
    }
    else
    {
        cout << "Íè÷üÿ";
    }
}
