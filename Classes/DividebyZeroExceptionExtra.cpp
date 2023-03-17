#include <iostream>
using namespace std;


class NoJob
{
public:
	NoJob() {cout << "NoJob constructor.\n"; x=0;}
	~NoJob() {cout << "NoJob destructor.\n";}
private:
	int x;
};

// Class DivideByZeroException definition.
// DivideByZeroException objects should be thrown by functions
// upon detecting division-by-zero exceptions
class DivideByZeroException
{
public:
	// constructor specifies default error message
	DivideByZeroException()
		: message( "attempted to divide by zero" ) 
		{cout << this << " Constructor\n";} //also display a message to track constructor calling
	//what returns the message
	char * what() {return message;}
	  
	// It is better to have a copy constructor
	// Try having and not having copy constructor
	DivideByZeroException(const DivideByZeroException & copy)
	{
		cout << this << " Copy Constructor\n";
		message = copy.message;
	}
	
	~DivideByZeroException() {cout << this << " Destructor\n";}  //to track down how the destructor is called
private:
	char * message;
};
 

// perform division and throw DivideByZeroException object if
// divide-by-zero exception occurs
double quotient( int numerator, int denominator )
{
	NoJob h; //dummy task, to test stack unwinding
	
	// throw DivideByZeroException if trying to divide by zero
	if ( denominator == 0 )
	{
		//throw DivideByZeroException(); // generate and throw exception object

		//alternative is to generate an object first and then to throw it
		//uncomment the following block and comment the above line to test this
		//also try these by having and not having copy constructor
		DivideByZeroException myException;
		throw myException;
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
		catch ( DivideByZeroException /* & */ myException )  
				//alternatively try to have reference parameter here and try these in combination of other cases
		{
			cout << "Exception occurred: " << &myException << ": " <<  myException.what() << endl;
		} // end catch

		cout << "\nEnter two integers (end-of-file to end): ";
	} // end while

	cout << endl;
	return 0; // terminate normally
} // end main
 
 
