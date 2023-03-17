#include <iostream>
using namespace std;

int myglobal;  //actual global var. definition
			   // add static keyword before int and see what happens

void myfunc ();  //prototype defn.

int main()
{
	myglobal = 7;  //access global var.
	cout << myglobal << endl;
	myfunc();
	cout << myglobal << endl;

	return 0;
}