#include <iostream>
#include <string>
using namespace std;

void PrintReversed()
{
    string word;
    if (cin >> word)           // reading succeeded?
    {  
		PrintReversed();        // print the rest reversed
	    cout << word << endl;   // then print the word
    }
}

int main()
{
    PrintReversed();
	return 0;
}
