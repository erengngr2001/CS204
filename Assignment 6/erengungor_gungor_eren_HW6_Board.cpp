#include "erengungor_gungor_eren_HW6_Board.h"

template <class Type>
Board<Type>::Board(int row, int cols)
{
	matrixp = new item<Type> * [row];
	for (int i = 0; i < row; i++)
	{
		matrixp[i] = new item<Type>[cols];
	}

	rowNum = row;
	colNum = cols;
}

template <class Type>
Board<Type>::~Board()
{
	for (int i = 0; i < rowNum; i++)
	{
		delete[] matrixp[i];
		matrixp[i] = NULL;
	}
	matrixp = NULL;
}

template <class Type>
Board<Type>::Board(const Board<Type>& copyThis)
{
	matrixp = new item<Type> * [copyThis.rowNum];
	for (int i = 0; i < copyThis.rowNum; i++)
	{
		matrixp[i] = new item<Type>[copyThis.colNum];
		for (int j = 0; j < copyThis.colNum; j++)
		{
			matrixp[i][j] = copyThis.matrixp[i][j];
		}
	}

	rowNum = copyThis.rowNum;
	colNum = copyThis.colNum;
}

template <class Type>
void Board<Type>::displayBoard(void)
{
	int pl1 = 0, pl2 = 0;

	cout << "        ";
	for (int i = 0; i < colNum; i++)
	{
		cout << i << "       ";
	}
	cout << "\n";
	for (int i = 0; i < rowNum; i++)
	{
		cout << i << "       ";
		for (int j = 0; j < colNum; j++)
		{
			cout << "(" << matrixp[i][j].id << "," << matrixp[i][j].value << ")   ";
		}
		cout << "\n";
	}
}

template <class Type>
void Board<Type>::updateBoardCells(int givenid, Type c)
{
	for (int i = 0; i < rowNum; i++)
	{
		for (int j = 0; j < colNum; j++)
		{
			if (givenid == matrixp[i][j].id)
				matrixp[i][j].value = c;
		}
	}
}

template <class Type>
int Board<Type>::getPlayerCellsCount(int givenid)
{
	int ownedCell = 0;

	for (int i = 0; i < rowNum; i++)
	{
		for (int j = 0; j < colNum; j++)
		{
			if (matrixp[i][j].id == givenid)
				ownedCell++;
		}
	}

	return ownedCell;
}

template <class Type>
int Board<Type>::knowTheOwner(int row, int col)
{
	return matrixp[row][col].id;
}

template <class Type>
int Board<Type>::getRowNum()
{
	return rowNum;
}

template <class Type>
int Board<Type>::getColNum()
{
	return colNum;
}

template <class Type>
item<Type>** Board<Type>::getHead()
{
	return matrixp;
}
