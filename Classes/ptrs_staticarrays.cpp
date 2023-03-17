#include <iostream>
using namespace std;


int main ()
{
	int myarray[10]; //static (a.k.a. built-in) array definition 
	int *ptr; 
	ptr = myarray; //address stored in pointer is the address of the first element in array
	//ptr = &myarray[0];	//equivalent and more clear

	int i, j;

	for (i=0; i<10; i++)
	{
		myarray[i]=i+1;
	}
	//*(myarray+1) = 100;
	for (i=0; i<10; i++)
	{
		cout << ptr[i] << endl;  //same output when you replace ptr[i] with *ptr++    
	}

	int my2d [3][5];  //2D static array definition
	int * ptr2[3];    //to have pointer for this array, we need an array of ptrs for each row
	ptr2[0] = my2d[0];  //and assign each row of 2D array to each element of ptr array
	ptr2[1] = my2d[1];
	ptr2[2] = my2d[2];
						// instead of my2d[i]  &my2d[i][0] would also work

	int **ptr3 = ptr2;  //ptr3 points to the pointer array
							// instead of ptr2  &ptr2[0] would also work

	for (i=0; i<3; i++)
		for (j=0; j<5; j++)
			my2d[i][j] = (i+1)*(j+1);

	cout << "\n\n";
	for (i=0; i<3; i++)
	{
		//int *p = ptr3[i];  //remove the comment sign to reach the elements via pointers
		for (j=0; j<5; j++)
			cout << ptr3[i][j] /* *p++  */ << " ";    //remove the comment sign to reach the elements via pointers
		cout << endl;
	}
	
	return 0;
}
