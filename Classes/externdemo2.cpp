#include <iostream>
using namespace std;

extern int myglobal;  //extern definition

void myfunc ()
{
	myglobal++;
	cout << myglobal << endl;
}