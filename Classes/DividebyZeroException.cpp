#include <iostream>
using namespace std;

// Class DivideByZeroException definition.
// DivideByZeroException objects should be thrown by functions
// upon detecting division-by-zero exceptions

class DivideByZeroException
{
public:
	// constructor specifies default error message
	DivideByZeroException()
		: message( "attempted to divide by zero" ) {}
	//what returns the message
	char * what() {return message;}
private:
	char * message;
};
 

// perform division and throw DivideByZeroException object if
// divide-by-zero exception occurs
double quotient( int numerator, int denominator )
{
	// throw DivideByZeroException if trying to divide by zero
	if ( denominator == 0 )
	{
		throw DivideByZeroException(); // generate and throw exception object
	}
	
	// return division result
	return (double) numerator / denominator;
} 

int main()
{
	int number1; 
	int number2; 
	double result; 

	cout << "Enter two integers (end-of-file to end): ";

	// enable user to enter two integers to divide
	while ( cin >> number1 >> number2 )
	{
		// try block contains code that might throw exception
		// and code that should not execute if an exception occurs
		try
		{
			result = quotient( number1, number2);
			cout << "The quotient is: " << result << endl;
		} // end try
	
		// exception handler handles a divide-by-zero exception
		catch ( DivideByZeroException myException )
		{
			cout << "Exception occurred: " << myException.what() << endl;
		} // end catch

		cout << "\nEnter two integers (end-of-file to end): ";
	} // end while

	cout << endl;
	return 0; // terminate normally
} // end main
 
 
