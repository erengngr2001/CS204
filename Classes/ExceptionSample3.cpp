#include <iostream>
#include <string>
using namespace std;

// shows strict type matching need between throw and catch
//no implicit typecasting is done.
int main()
{
	int input;
	string s="yadda yadda";
	cin >> input;
	try
	{
		if (input == 1)
			throw 1.1; 
		if (input == 2)
			throw 2;
		if (input == 3)
			throw "bla bla";
		if (input == 4)
			throw s;
	}

	/*comment out one of the following catches each time to see
	typecasting is not performed between throw and catch*/

	catch (double i)
	{
		cout << "Double exception handler" << endl;
	}

	catch (int i)
	{
		cout << "Integer exception handler" << endl;
	}

	catch(const char msg[])
	{
		cout << "char array exception handler" << endl;
	}

	catch(string s)
	{
		cout << "String exception handler" << endl;
	}

	return 0;
}
