#pragma once
//Eren Güngör
//29465
//Lab Section C2
//Homework3 with VS2012


#include <iostream>
#include <string>
using namespace std;

struct node {
	char data;
	node* right;
	node* down;

	node()
	{
		right = NULL;
		down = NULL;
		data = '-';
	}
};

class TwoDLinkedList
{
public:
	TwoDLinkedList();
	void add_row_sorted(string s);
	void displayFullMatrix() const; 
	void displayFullMatrixReversed();
	void display_rows_starting_with(char c) const;
	void display_cols_starting_with(char c) const;
	int delete_rows_starting_with(char c);
	int delete_cols_starting_with(char c);
	void clear();

private:
	node* head;
	void printLine(node* p);
};
