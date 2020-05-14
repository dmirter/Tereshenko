#include "Header.h"
#include <iostream>
using namespace std;

Game initGame(char Userchar) {
	Game begin;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			begin.bord[i][j] = ' ';
		}
	}
	begin.isUserTurn = rand() % 2;
	begin.userChar = Userchar;
	if (Userchar == 'X')
	{
		begin.botChar = '0';
	}
	else
	{
		begin.botChar = 'X';
	}

	begin.status = PLAY;
	updateDisplay(begin);
	return begin;
}

void updateDisplay(const Game game) 
{
	system("CLS");
	cout << "    1   2   3\n  -------------\n";
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << " | ";
		for (int j = 0; j < 3; j++) 
		{
			cout << game.bord[i][j] << " | ";
		}
		cout << "\n  -------------\n";
	}
}

void botTurn(Game* game)
{
	int Count = 0;
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			if (game->bord[i][j] != ' ') Count++;
		}
	}
	if (!Count)
	{
		game->bord[1][1] = game->botChar;
		return;
	}
	Count = 0;
	for (int i = 0; i < 3; i++)
	{
		if (game->bord[i][i] == game->userChar)
		{
			Count++;
		}
		else if (game->bord[i][i] == game->botChar) {
			Count--;
		}
	}
	if (Count == 2)
	{
		for (int l = 0; l < 3; l++) 
		{
			if (game->bord[l][l] == ' ')
			{
				game->bord[l][l] = game->botChar;
				return;
			}
		}
	}
	Count = 0;
	for (int i = 0; i < 3; i++) 
	{
		if (game->bord[i][2 - i] == game->userChar) {
			Count++;
		}
		else if (game->bord[i][2 - i] == game->botChar) {
			Count--;
		}
	}
	if (Count == 2)
	{
		for (int j = 0; j < 3; j++) 
		{
			if (game->bord[j][2 - j] == ' ')
			{
				game->bord[j][2 - j] = game->botChar;
				return;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		Count = 0;
		for (int j = 0; j < 3; j++)
		{
			if (game->bord[i][j] == game->userChar) {
				Count++;
			}
			else if (game->bord[i][j] == game->botChar) {
				Count--;
			}
		}
		if (Count == 2) {
			for (int j = 0; j < 3; j++)
			{
				if (game->bord[i][j] == ' ') 
				{
					game->bord[i][j] = game->botChar;
					return;
				}
			}
		}
	}
	for (int i = 0; i < 3; i++) 
	{
		Count = 0;
		for (int j = 0; j < 3; j++) 
		{
			if (game->bord[j][i] == game->userChar) {
				Count++;
			}
			else if (game->bord[j][i] == game->botChar) {
				Count--;
			}
		}
		if (Count == 2) {
			for (int l = 0; l < 3; l++) 
			{
				if (game->bord[l][i] == ' ') {
					game->bord[l][i] = game->botChar;
					return;
				}
			}
		}
	}
	for (int i = 0; i < 3; i++) 
	{
		Count = 0;
		for (int j = 0; j < 3; j++)
		{
			if (game->bord[i][j] == game->userChar) {
				Count++;
			}
			else if (game->bord[i][j] == game->botChar) {
				Count--;
			}
		}
		if (Count == 1) {
			for (int l = 0; l < 3; l++)
			{
				if (game->bord[i][l] == ' ') 
				{
					game->bord[i][l] = game->botChar;
					return;
				}
			}
		}
	}
	for (int i = 0; i < 3; i++) 
	{
		Count = 0;
		for (int j = 0; j < 3; j++)
		{
			if (game->bord[j][i] == game->userChar) {
				Count++;
			}
			else if (game->bord[j][i] == game->botChar) {
				Count--;
			}
		}
		if (Count == 1) {
			for (int l = 0; l < 3; l++)
			{
				if (game->bord[l][i] == ' ')
				{
					game->bord[l][i] = game->botChar;
					return;
				}
			}
		}
	}
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (game->bord[i][j] == ' ')
			{
				game->bord[i][j] = game->botChar;
				return;
			}
}

void userTurn(Game* game) 
{
	int a, b;
	cout << "Ходите: ";
	cin >> a >> b;
	while (a < 1 || a > 3 || b < 1 || b > 3 || game->bord[a - 1][b - 1] != ' ')
	{
		cout << "Неправильно заданы координаты" << endl;
		cout << "Ходите: ";
		cin >> a >> b;
	}
	game->bord[a - 1][b - 1] = game->userChar;
}

void whoWon(Game* game, int a)
{
	if (a == 3) 
	{
		game->status = USER_WIN;
	}
	else if (a == -3)
	{
		game->status = BOT_WIN;
	}
}

bool updateGame(Game* game)
{
	int count;
	for (int i = 0; i < 3; i++)
	{
		count = 0;
		for (int j = 0; j < 3; j++)
		{
			if (game->bord[i][j] == game->userChar)
			{
				count++;
			}
			else if (game->bord[i][j] == game->botChar)
			{
				count--;
			}
		}
		whoWon(game, count);
	}
	for (int i = 0; i < 3; i++) 
	{
		count = 0;
		for (int j = 0; j < 3; j++) 
		{
			if (game->bord[j][i] == game->userChar)
			{
				count++;
			}
			else if (game->bord[j][i] == game->botChar)
			{
				count--;
			}
		}
		whoWon(game, count);
	}
	count = 0;
	for (int i = 0; i < 3; i++)
	{
		if (game->bord[i][i] == game->userChar)
		{
			count++;
		}
		else if (game->bord[i][i] == game->botChar)
		{
			count--;
		}
	}
	whoWon(game, count);
	count = 0;
	for (int i = 0; i < 3; i++)
	{
		if (game->bord[i][2 - i] == game->userChar)
		{
			count++;
		}
		else if (game->bord[i][2 - i] == game->botChar)
		{
			count--;
		}
	}
	whoWon(game, count);
	if (game->status == PLAY)
	{
		count = 0;
		for (int i = 0; i < 3; i++) 
		{
			for (int j = 0; j < 3; j++) 
			{
				if (game->bord[i][j] == ' ')count++;
			}
		}
		if (!count)
		{
			game->status = NOT_WIN;
			return true;
		}
		game->isUserTurn = !game->isUserTurn;
		return false;
	}
	return true;
}