#include <iostream>
using namespace std;

void print_table(int** values,  int num_rows, int num_cols) 
{ 
	int i, j; 
	for (i = 0; i < num_rows; i++) { 
		for (j= 0 ; j< num_cols ; j++) 
			cout << values[i][j] << " "; 
		cout << endl;
	} 
} 

int main()
{
	int **    nums; 
	int rows, columns, i,j; 

	cout<< "Enter the number of rows: "; 
	cin >> rows; 
	cout<< "Enter the number of columns: "; 
	cin >> columns; 

	/************ Allocate Memory for the 2d Array ************/
	// nums is an array of int pointers 
	nums = new int*  [rows]; 
	
	// each nums [i] is an array of ints. 
	for (i = 0; i<rows; i++) 
		nums[i] = new int  [columns]; 
	

	/******************* Read In the Entries ******************/
	cout << "Enter the elements" << endl; 

	for (i = 0; i < rows; i++) 
	{
		for (j= 0 ; j< columns ; j++) 
		{  
			cout<< '[' << i << ',' << j << "]: ";
			cin >> nums[i][j];
			cout<< endl; 
		} 
	}
	
	// Print the whole matrix table
	print_table(nums, rows, columns); 

	// Returning memory to free heap for reuse 
	for (i = 0; i< rows; i++) 
		delete [] nums[i]; 
	delete [] nums; 

return 0;
}