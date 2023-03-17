//Eren Güngör
//29465
//Lab Section C2
//Homework5 with VS2012

#pragma once

#include <iostream>
using namespace std;

//items with which the board will be filled
template <class Type>
struct item
{
	int id; //owner of the item (0,1 or 2)
	Type value; //value that the item keeps

	item()
	{
		id = 0;
	}
};

template <class Type>
class Board
{
public:
	//parametric constructor 
	Board(int row, int cols);
	//destructor
	~Board();
	//deep copy constructor
	Board(const Board<Type>& copyThis);
	//displays the board in 2D matrix form
	void displayBoard(void);
	//updates all the cells that given player owns with the value c
	void updateBoardCells(int givenid, Type c);
	//displays how many cells given player has
	int getPlayerCellsCount(int givenid);
	//displays the owner of (row,col)th cell
	int knowTheOwner(int row, int col);
	//getter function for row number
	int getRowNum();
	//getter function for column number
	int getColNum();
	//getter function for pointer pointer that leads to the board
	item<Type>** getHead();

private:
	item<Type>** matrixp; //pointer to pointer that allows access to the board
	int rowNum; //total row number
	int colNum; //total column number
};

#include "erengungor_gungor_eren_HW6_Board.cpp"