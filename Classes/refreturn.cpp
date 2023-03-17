#include "iostream"
#include "string"
using namespace std;


//change the function header to
//    const string & f2 (string * p)
//and
//    string f2 (string * p)
//to see what happens
string & f2 (string * p)
{
	*p = "CS204"; //changes the content in memory location
	return *p; //and return it (memory allocated before calling)
}

//same task as above but for ints 
int & f2 (int * p)
{
	*p = 204;
	return *p;
}

int main ()
{

	string * sp = new string;
	f2(sp)[2] = 'a';  //works as intended only if f2 returns reference (non const)
	cout << *sp << endl;

	int * ip = new int;
	f2(ip) += 250;
	cout << endl << *ip << endl;
	return 0;
}