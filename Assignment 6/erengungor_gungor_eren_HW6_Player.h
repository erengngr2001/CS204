//Eren Güngör
//29465
//Lab Section C2
//Homework5 with VS2012

#pragma once
#include "erengungor_gungor_eren_HW6_Board.h"

template <class Type>
class Player
{
public:
	//parametric constructor 
	Player(Board<Type> &takeboard);
	//updates the value of (row,col)th cell with given c if ownership matches
	bool updateCell(int row, int col, Type c);
	//updates all owned cells with given c
	void updateMyCells(Type c);
	//releases the ownership of (row,col)th cell, set owner to zero
	bool unclaimOwnership(int row, int col);
	//release all owned cells, set all owners to zero
	void unclaimOwnerships(void);

private:
	Board<Type>& board; //the board which will be used together by both players
	static int nextid; //to keep player id's separately
	int playerid; //id of the player
};

#include "erengungor_gungor_eren_HW6_Player.cpp"

