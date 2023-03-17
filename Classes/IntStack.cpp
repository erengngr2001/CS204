#include <iostream>
#include "intstack.h"
using namespace std;

//*******************
// Constructor      *
//*******************

IntStack::IntStack(int size)
{
	stackArray = new int[size]; 
	stackSize = size; 
	top = -1;
}

//*************************************************
// Member function push pushes the argument onto  *
// the stack.                                     *
//*************************************************

void IntStack::push(int num)
{
	if (isFull())
	{
		cout << "The stack is full.\n";
	}
	else
	{
		top++;
		stackArray[top] = num;
	}
}

//****************************************************
// Member function pop pops the value at the top     *
// of the stack off, and copies it into the variable *
// passed as an argument.                            *
//****************************************************

void IntStack::pop(int &num)
{
	if (isEmpty())
	{
		cout << "The stack is empty.\n";
	}
	else
	{
		num = stackArray[top];
		top--;
	}
}

//***************************************************
// Member function isFull returns true if the stack *
// is full, or false otherwise.                     *
//***************************************************

bool IntStack::isFull(void)
{
	bool status;

	if (top == stackSize - 1)
		status = true;
	else
		status = false;

	return status;
}

//****************************************************
// Member funciton isEmpty returns true if the stack *
// is empty, or false otherwise.                     *
//****************************************************
bool IntStack::isEmpty(void)
{
	bool status;

	if (top == -1)
		status = true;
	else 
		status = false;

	return status;
}
