// This program reads an infix expression and calculates
// the result using stacks. For the sake on simplicity in expression parsing
// we assume that expression is a valid postfix expression.
// We also assume single digit operands in the expression so that we can read char by char

#include <iostream>
#include "DynIntStack.h"
using namespace std;

int main()
{
    DynIntStack stack;
	char token;
	int rhs, lhs, result;  

	cout << "Please enter postfix expression:  ";
	while (cin >> token)  //as long as there is input
	{
		if (token >= '0' && token <= '9')   //if digit
		{
			stack.push(token - '0');  //push it to stack
		}
		else     //if operator
		{
			stack.pop(rhs);
			stack.pop(lhs);  // pop two operands
			//and apply the operations. Result is pushed to the stack
			if (token == '+')         
				stack.push(lhs + rhs);
			else if (token == '-')
				stack.push(lhs - rhs);
			else if (token == '*')
				stack.push(lhs * rhs);
			else if (token == '/')
				stack.push(lhs / rhs);
		}
	}

	//after while, the dtack contains only the final result
	//pop it and display
	stack.pop(result); 
	cout << "result is: " << result << endl;

 
    return 0;
}