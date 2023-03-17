#include <iostream>
using namespace std;

//Demonstrates pointers to functions (a.k.a. function pointers)
//Debug with F11 to see the function calls

int addition (int a, int b)
{
	return a+b; 
}

int subtraction (int a, int b)
{ 
	return a-b; 
}

int operation (int x, int y, int (*fptr)(int,int))
							//a parameter for a function pointer that returns
							//int and takes two int parameters
{
	int g;
	g = (*fptr)(x,y);		//function is called using func. pointer
	return g;
}

int main ()
{
	int (*p)(int, int);		//function pointer variable
	p=&subtraction;			//func. ptr is bound to subtraction func.
	cout << (*p)(10, 20) << endl;  //call to subtraction function using func. ptr
    
	int m,n;
	m = operation (7, 5, &addition); //passing a func. as argument
	n = operation (8,10, &subtraction);
	cout << m << " " << n << endl;
	return 0;
}

