
//Eren Güngör
//29465
//Lab Section C2
//Homework4 with VS2012

#include <iostream>	
#include <string>
#include "eren_gungor_erengungor_HW4_DynStackHW4.h"
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
	ifstream input;
	bool isFail = false; //checks if an error is given whilst reading or not
	string filename;
	int linenumber = 1, prevLinenumber, failureLine;
	char ch, prevch, failurech;
	//open .cpp files to read
	cout << "Please enter the file name: ";
	cin >> filename;
	input.open(filename.c_str());
	while (input.fail())
	{
		cout << "File not found." << endl;
		cout << "Please enter the file name: ";
		cin >> filename;
		input.open(filename.c_str());
	}

	//create an empty DynStack object to create Stack
	DynStack myStack;

	//start reading "input".cpp
	while (input.get(ch))
	{
		if (!isFail) //if an error is given, stop
		{
			if ('\n' == ch)
			{
				linenumber++;
			}
			else if ('{' == ch || '[' == ch || '(' == ch || ')' == ch || ']' == ch || '}' == ch)
			{
				if ('{' == ch || '[' == ch || '(' == ch)
				{
					myStack.push(ch, linenumber);
					cout << "Found the opening symbol " << ch << " at line " << linenumber << endl;
				}
				else if (')' == ch)
				{
					if (!myStack.isEmpty())
					{
						myStack.pop(prevch, prevLinenumber);
						if ('(' == prevch) //match the symbol with its previously read pair
						{
							cout << "Found the closing symbol " << ch << " at line " << linenumber << " which closes the opening symbol " << prevch << " at line " << prevLinenumber << endl;
						}
						else //if last unclosed opening symbol does not match with new symbol
						{
							isFail = true;
							cout << "ERROR!!! Found the closing symbol " << ch << " at line " << linenumber << " but the last unclosed opening symbol " << prevch << " at line " << prevLinenumber << endl;
						}
					}
					else { //if there are an extra closing symbol
						isFail = true;
						cout << "ERROR!!! Found the closing symbol " << ch << " but there are no unclosed opening symbols!";
					}
				}
				else if (']' == ch)
				{
					if (!myStack.isEmpty())
					{
						myStack.pop(prevch, prevLinenumber);
						if ('[' == prevch) //match the symbol with its previously read pair
						{
							cout << "Found the closing symbol " << ch << " at line " << linenumber << " which closes the opening symbol " << prevch << " at line " << prevLinenumber << endl;
						}
						else //if last unclosed opening symbol does not match with new symbol
						{
							isFail = true;
							cout << "ERROR!!! Found the closing symbol " << ch << " at line " << linenumber << " but the last unclosed opening symbol " << prevch << " at line " << prevLinenumber << endl;
						}
					}
					else { //if there are an extra closing symbol
						isFail = true;
						cout << "ERROR!!! Found the closing symbol " << ch << " but there are no unclosed opening symbols!";
					}
				}
				else if ('}' == ch)
				{
					if (!myStack.isEmpty())
					{
						myStack.pop(prevch, prevLinenumber);
						if ('{' == prevch) //match the symbol with its previously read pair
						{
							cout << "Found the closing symbol " << ch << " at line " << linenumber << " which closes the opening symbol " << prevch << " at line " << prevLinenumber << endl;
						}
						else //if last unclosed opening symbol does not match with new symbol
						{
							isFail = true;
							cout << "ERROR!!! Found the closing symbol " << ch << " at line " << linenumber << " but the last unclosed opening symbol " << prevch << " at line " << prevLinenumber << endl;
						}
					}
					else { //if there are an extra closing symbol
						isFail = true;
						cout << "ERROR!!! Found the closing symbol " << ch << " but there are no unclosed opening symbols!";
					}
				}
			}
		}
	}

	if (!isFail && myStack.isEmpty()) //if everything is normal
	{
		cout << "File processed successfully. No errors were found." << endl;
	}
	else if (!isFail && !myStack.isEmpty()) //if there are unclosed symbols
	{
		cout << "ERROR!!! The following opening symbols were not closed:" << endl;
		while (!myStack.isEmpty())
		{
			myStack.pop(prevch, prevLinenumber);
			cout << "   Symbol " << prevch << " at line " << prevLinenumber << endl;
		}
	}

	input.close();
	return 0;
}