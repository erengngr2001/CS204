// This program illustrates the IntStack class.
#include "intstack.h"
#include <iostream>
using namespace std;

int main()
{
    IntStack  stack(5);
    int num;
	cout << "Created an empty stack with capacity 5, trying to pop. \n";
	stack.pop(num);
	//cout << num << endl;
    int values[] = {2, 7, 10, 5, 3, 8, 11};

    cout << "\nPushing...\n";
    for (int k = 0; k < 7; k++)
    {
        cout << values[k] << "  ";
        stack.push(values[k]);
		cout << endl;
    }    
    cout << "\nPopping...\n";
    while (!stack.isEmpty())
    {
        stack.pop(num);
        cout << num << endl;
    }
    cout << endl;
	stack.pop(num);
	cout << num << endl;
    return 0;
}