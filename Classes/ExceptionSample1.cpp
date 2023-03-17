#include <iostream>
#include <string>
using namespace std;

int ToInches (int cm)
{
	//uncomment this if part to test that you can throw an exception in a 
	//function called in try block

	if (cm == 100)
		throw "you are a winner!";
	
	//Extra: put the above if in try block and have a catch that really catches the exception. See what happens
	//Extra 2: put the above if in try block and have a catch that does not catch the exception. See what happens
	//Extra 3: what if you call ToInches outside of try block? (see end of main)

	return cm/2.54;
}

int main()
{
	int height;
	cin >> height;
	try
	{
		if (height > 300)
			throw "height exceeds maximum";
		if (height < 30)
			throw "height below minimum";
		cout << "Person is " << ToInches(height) << " inches tall" << endl;
	}
	//cout << "Wassup";  //no statements are allowed between try and catch
	catch(const char msg[])
	{
		cout << "Exception occured: " << msg << endl;
	}
	//cout << ToInches(100);
	cout << "Program Stops " << endl;
 	return 0;
}
