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
	cin >> height;
	try
	{
		if (height <= -1)
			throw 0;  //change 0 to a real number (e.g. 0.5) and see that the exception will not be caught
		if (height > 300)
			throw "height exceeds maximum";
		if (height < 30)
			throw "height below minimum";
		cout << "Person is " << ToInches(height) << " inches tall" << endl;
	}
	catch (const char msg[])
	{
		cout << "Exception occured: " << msg << endl;
	}

	//Uncomment the following to see const char * is the same as const char []
	// also try to remove const above and/or below to see how it works. Basically, if you have
	      //have the const version first, since it catches both const and non-const exceptions,
		  //compiler gives error for the non-const catch coming afterward as it is unncessarry. 
	      //However, if you have the non-const catch first and const catch after that, then
	      //program compiles successfully since the first one catches non-const thrown exceptions 
		  //and the second one (const) catches the const thrown exceptions.
	/*catch(const char * msg)
	{
		cout << "Exception occured: " << msg << endl;
	}*/

	catch (int i)
	{
		cout << "Bad input: height cannot be less than " << i << endl;
	}

	cout << "Program Stops " << endl;

	return 0;
}
