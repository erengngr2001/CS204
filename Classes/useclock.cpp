#include <iostream>
using namespace std;

#include "clockt.h"

// test program for ClockTime class

int main()
{
	//uncomment to to test reading objects using the overloaded >> operator
	/*ClockTime t1;
	cin >> t1;
	cout << "t1: " << t1 << endl;*/
	

    int h,m,s;
    cout << "enter two sets of 'h m s' data " << endl
         << "Enter non integers to terminate program." << endl << endl;

    while (cin >> h >> m >> s)
    {   ClockTime a(s,m,h);
        cin >> h >> m >> s;
        ClockTime b(s,m,h);
        ClockTime c;
		c = a + b;
        
        cout << a << " + " << b << " = " << c << endl;
		cout << "3 hours later: " << 3 + c << endl;
    }
    return 0;
}
