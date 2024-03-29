// TicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


class Board
{
public:
	string board[3][3] = { "_","_","_","_","_","_","_","_","_" };
	string falseBoard[3][3] = { "_","_","_","_","_","_","_","_","_" };
	int turn = 0;
	int falseTurn = 1;
	int count = 1;
	int valueA[3][3][10];

	void Display(string board[3][3]);
	void PlayerTurn(string player);
	void setValues(int across, int down, string player, string board[3][3]);
	int Win(string player, string board[3][3]);
	int RecursiveWinCheck();
	int OWinCheck();

};


class Turn
{
public:
	int turn = 0;
	void NextTurn();

};

void Turn::NextTurn()
{
	turn = turn + 1;
}


void Board::Display(string board[3][3])
{
	cout << endl << "  Row:" << endl;
	cout << "      +---+---+---+" << endl;
	cout << "   0  | " << board[0][0] << " | " << board[1][0] << " | " << board[2][0] << " |" << endl;
	cout << "      +---+---+---+" << endl;
	cout << "   1  | " << board[0][1] << " | " << board[1][1] << " | " << board[2][1] << " |" << endl;
	cout << "      +---+---+---+" << endl;
	cout << "   2  | " << board[0][2] << " | " << board[1][2] << " | " << board[2][2] << " |	" << endl;
	cout << "      +---+---+---+" << endl;
	cout << "         Column:  " << endl;
	cout << "        0   1   2  " << endl;
}
void Board::setValues(int across, int down, string player, string board[3][3])
{
	board[across][down] = player;
}
int Board::Win(string player, string board[3][3])
{
	for (size_t i = 0; i < 3; i++)
	{

		if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
		{
			if (board != falseBoard)
			{
				cout << player << " wins" << endl;
			}
			if (player == "X")
			{
				return 10;
			}
			else
			{
				return -10;
			}
		}
		if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
		{
			if (board != falseBoard)
			{
				cout << player << " wins" << endl;
			}
			if (player == "X")
			{
				return 10;
			}
			else
			{
				return -10;
			}
		}
	}
	if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
	{
		if (board != falseBoard)
		{
			cout << player << " wins" << endl;
		}
		if (player == "X")
		{
			return 10;
		}
		else
		{
			return -10;
		}
	}
	if (board[2][0] == player && board[1][1] == player && board[0][2] == player)
	{
		if (board != falseBoard)
		{
			cout << player << " wins" << endl;
		}
		if (player == "X")
		{
			return 10;
		}
		else
		{
			return -10;
		}
	}
	else if (board[0][0] != "_" && board[1][0] != "_" && board[2][0] != "_" && board[0][1] != "_" && board[1][1] != "_" && board[2][1] != "_" && board[0][2] != "_" && board[1][2] != "_" && board[2][2] != "_")
	{
		if (board != falseBoard)
		{
			cout << "Draw" << endl;
		}
		return 0;
	}
	return 2;
}
int Board::RecursiveWinCheck()
{

	string player;
	int valueWin;
	int valuef = 0;
	int valueX = 10;
	int valueO = -10;
	int place[2];

	if (turn % 2 == 0 && board[1][1] == "_")
	{
		board[1][1] = "O";
		falseBoard[1][1] = "O";
		return 0;
	}


	for (int i = 0; i < 3; i++)
	{
		for (int I = 0; I < 3; I++)
		{
			if (falseBoard[i][I] == "_")
			{
				if (falseTurn % 2 == 0)
				{
					player = "X";
				}
				else
				{
					player = "O";
				}

				falseBoard[i][I] = player;

				valueWin = Win(player, falseBoard);
				if (valueWin != 2)
				{
					falseBoard[i][I] = "_";
					return valueWin;
				}

				falseTurn++;
				count++;
				valueA[i][I][count - 1] = RecursiveWinCheck();
				falseTurn++;
				count--;
				falseBoard[i][I] = "_";
			}

		}

	}

	if (count == 1)
	{
		for (int c = 0; c < 3; c++)
		{
			for (int C = 0; C < 3; C++)
			{
				if (board[c][C] == "_")
				{
					if (valueX >= valueA[c][C][count])
					{
						valueX = valueA[c][C][count];
						place[0] = c;
						place[1] = C;
					}

				}

			}

		}

		board[place[0]][place[1]] = "O";
		falseBoard[place[0]][place[1]] = "O";
		for (size_t i = 0; i < 3; i++)
		{
			for (size_t I = 0; I < 3; I++)
			{
				for (size_t ii = 0; ii < 10; ii++)
				{
					valueA[i][I][ii] = NULL;
				}
			}

		}
	}
	else
	{
		for (int c = 0; c < 3; c++)
		{
			for (int C = 0; C < 3; C++)
			{
				if (falseTurn % 2 == 1)
				{
					if (valueA[c][C][count] >= -10 && valueA[c][C][count] <= 10)
					{
						if (valueX >= valueA[c][C][count])
						{
							valueX = valueA[c][C][count];
						}
					}
				}
				else
				{
					if (valueA[c][C][count] >= -10 && valueA[c][C][count] <= 10)
					{
						if (valueO <= valueA[c][C][count])
						{
							valueO = valueA[c][C][count];
						}
					}
				}
			}

		}
		if (falseTurn % 2 == 1)
		{
			return valueX;

		}
		else
		{
			return valueO;

		}

	}
	return 0;
}
int Board::OWinCheck()
{
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == "O" && board[i][1] == "O" && board[i][2] == "_") {
			board[i][2] = "O";
			return 0;
		}
		if (board[i][0] == "O" && board[i][1] == "_" && board[i][2] == "O") {
			board[i][1] = "O";
			return 0;
		}
		if (board[i][0] == "_" && board[i][1] == "O" && board[i][2] == "O") {
			board[i][0] = "O";
			return 0;
		}
		if (board[0][i] == "O" && board[1][i] == "O" && board[2][i] == "_") {
			board[2][i] = "O";
			return 0;
		}
		if (board[0][i] == "O" && board[1][i] == "_" && board[2][i] == "O") {
			board[1][i] = "O";
			return 0;
		}
		if (board[0][i] == "_" && board[1][i] == "O" && board[2][i] == "O") {
			board[0][i] = "O";
			return 0;
		}
	}
	if (board[0][0] == "O" && board[1][1] == "O" && board[2][2] == "_") {
		board[2][2] = "O";
		return 0;
	}
	if (board[0][0] == "O" && board[1][1] == "_" && board[2][2] == "O") {
		board[1][1] = "O";
		return 0;
	}
	if (board[0][0] == "_" && board[1][1] == "O" && board[2][2] == "O") {
		board[0][0] = "O";
		return 0;
	}
	if (board[0][2] == "O" && board[1][1] == "O" && board[2][0] == "_") {
		board[2][0] = "O";
		return 0;
	}
	if (board[0][2] == "O" && board[1][1] == "_" && board[2][0] == "O") {
		board[1][1] = "O";
		return 0;
	}
	if (board[0][2] == "_" && board[1][1] == "O" && board[2][0] == "O") {
		board[0][2] = "O";
		return 0;
	}
	else {
		return 1;
	}
}
void Board::PlayerTurn(string player)
{
	int across;
	int down;
	string playerX = "X";
	cout << player << " turn" << endl;
	cout << "input the column from 0-2 starting from the left" << endl;
	cin >> across;
	cout << "input the row from 0-2 starting from the top" << endl;
	cin >> down;
	if (board[across][down] == "_")
	{
		setValues(across, down, player, board);
		setValues(across, down, player, falseBoard);
	}
	else
	{
		system("cls");
		Display(board);
		cout << " That space taken already!!! " << endl;
		PlayerTurn(player);
	}
}
int main()
{

	string board[3][3] = { "_","_","_","_","_","_","_","_","_" };
	string playerX = "X";
	string playerO = "O";
	string player;
	Turn turncount;
	Board Game;

	while (Game.Win(player, Game.board) == 2)
	{

		if (Game.turn % 2 == 1)
		{
			player = playerO;

		}
		else
		{
			player = playerX;
		}
		Game.turn++;
		system("cls");
		Game.Display(Game.board);
		if (player == "X")
		{
			Game.PlayerTurn(player);
		}
		else
		{
			cout << "before" << endl;
			Game.OWinCheck();
			Game.RecursiveWinCheck();
			cout << "after" << endl;

		}

	}
	system("cls");
	Game.Display(Game.board);
	Game.Win(player, Game.board);
	return 0;
}
