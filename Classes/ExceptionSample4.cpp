#include <iostream>
#include <string>
using namespace std;

int ToInches (int cm)
{
	return cm/2.54;
}

int main()
{
	int height;
	string err="Input cannot be below 0";
	try
	{
		cin >> height;
		try
		{
			if (height <= -1)
				throw err; 
			if (height > 300)
				throw "height exceeds maximum";
			if (height < 30)
				throw height;
			cout << "Person is " << ToInches(height) << " inches tall" << endl;
		}
		catch(const char msg[])
		{
			cout << "Exception occured: " << msg << endl;
		}

		cout << "I am in the middle.\n" << endl;
	}
	catch (int i)
	{
		cout << "Exception occured: Height must be greater than " << i << endl;
	}

	//Uncomment this to catch any unhandled exception (the string exception in this case)
	/*catch (...)
	{
		cout << "Houston we have a problem, but I do not know what it is :(\n";
	}*/

	cout << "Program Stops " << endl;

	return 0;
}
