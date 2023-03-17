#include "erengungor_gungor_eren_HW6_Player.h"

template <class Type>
int Player<Type>::nextid = 1; //set id to 1 for beginning

template <class Type>
Player<Type>::Player(Board<Type>& takeboard) :
	board(takeboard), playerid(nextid)
{
	nextid++; //increment id for any other object creation (to create players with different id's)
}

template <class Type>
bool Player<Type>::updateCell(int row, int col, Type c)
{
	if (board.getHead()[row][col].id == playerid)
	{
		board.getHead()[row][col].value = c;
		return true;
	}
	else if (board.getHead()[row][col].id == 0)
	{
		board.getHead()[row][col].value = c;
		board.getHead()[row][col].id = playerid;
		return true;
	}

	return false;
}

template <class Type>
void Player<Type>::updateMyCells(Type c)
{
	for (int i = 0; i < board.getRowNum(); i++)
	{
		for (int j = 0; j < board.getColNum(); j++)
		{
			if (playerid == board.getHead()[i][j].id)
			{
				board.getHead()[i][j].value = c;
			}
		}
	}
}

template <class Type>
bool Player<Type>::unclaimOwnership(int row, int col)
{
	if (board.getHead()[row][col].id != playerid)
		return false;

	board.getHead()[row][col].id = 0;
}

template <class Type>
void Player<Type>::unclaimOwnerships(void)
{
	for (int i = 0; i < board.getRowNum(); i++)
	{
		for (int j = 0; j < board.getColNum(); j++)
		{
			if (playerid == board.getHead()[i][j].id)
			{
				board.getHead()[i][j].id = 0;
			}
		}
	}
}