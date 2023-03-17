#include <iostream>
using namespace std;
#include "matrixclass.h"

/* Program to show 2d matrix implementation */

int main()
{
	Matrix1D m(5,10);

	m.SetIndex(0,5,33);
	cout << m.GetIndex(0,5) << endl;



	Matrix2D n(5,10);

	n.SetIndex(0,5,33);
	cout << n.GetIndex(0,5) << endl;

	
return 0;
}