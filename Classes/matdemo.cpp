#include <iostream>
#include <string>
#include <iomanip>     // for setw
using namespace std;
#include <vector>

//
//// demonstrate class matrix
//
void Print(const vector<vector<int>> & mat)
{
    for (int j=0; j < mat.size(); j++)
    {   
		for (int k=0; k < mat[0].size(); k++)
        {   
			cout << setw(4) << mat[j][k];
        }
        cout << endl;
    }
}

void SumDiagonal(const vector<vector<int>> & mat)
{
		int sumdiag = 0;
		for (int k=0; k < mat[0].size(); k++)
		{
			sumdiag += mat[k][k];
		}
		cout << "sum of diagonal is " << sumdiag << endl;
}

void SumColumn(const vector<vector<int>> & mat)
{
	for (int j=0; j < mat[0].size(); j++)
	{
		int sum = 0;
		for (int k=0; k < mat.size(); k++)
		{
			sum += mat[k][j];
		}
		cout << "sum of column " << j << " is " << sum << endl;
	}
}

int main()
{
	int j,k;
    int rows, cols;
    cout << "row col dimensions: ";
    cin >> rows >> cols;
	vector<vector<int>> mat(rows, vector<int>(cols));
	// a vector of vector<int> who has row many elements, which are vector<int>, all 0

    for (j=0; j < rows; j++)	// fill matrix
    {
		for (k=0; k < cols; k++)
        {
			mat[j][k] = (j+1)*(k+1);
        }
    }

    Print(mat);
	cout << "\n\n";

	SumColumn(mat);

	if (rows == cols)// diagonal only occurs in a square matrix
	{
		cout << "\n";
		SumDiagonal(mat);
	}

	//
	// 4 possible matrix declarations
	//
	vector<vector<int>> mat1;   //empty matrix with no rows and columns
	cout << "Printing original mat1" << endl;
    Print(mat1);
	cout << "\n\n";

	//adding elements to mat1
	for (j=0; j < rows; j++)	
    {
		vector<int> temp;  //creating an empty temporary vector
		for (k=0; k < cols; k++)
        {
			temp.push_back((j+1)*(k+1));  // and fill it up
        }
		mat1.push_back(temp);  //then add it as the jth row 
    }

	cout << "Printing mat1 after filling up" << endl;
    Print(mat1);
	cout << "\n\n";


	vector<vector<int>> mat2(rows);  //a matrix with rows amount of rows but all empty
	cout << "Printing original mat2" << endl;
    Print(mat2);
	cout << "\n\n";

	//adding elements to each row
    for (j=0; j < rows; j++)	
    {
		for (k=0; k < cols; k++)  // fiil the jth row
        {
			mat2[j].push_back((j+1)*(k+1));  
        }
    }
	cout << "Printing mat2 after filling up" << endl;
    Print(mat2);
	cout << "\n\n";
	
	vector<vector<int>> mat3(rows, vector<int>(cols));  //a matrix with rows rows and cols columns; all zero
	cout << "Printing mat3" << endl;
    Print(mat3);
	cout << "\n\n";

	vector<vector<int>> mat4(rows, vector<int>(cols, -1)); //a matrix with rows rows and cols columns; all -1
	cout << "Printing mat4" << endl;
    Print(mat4);
	cout << "\n\n";


	cout << "\n";
	cin.ignore();
	cin.get();
    return 0;    
}
