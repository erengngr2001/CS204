#include <iostream>
using namespace std;

int gint;

void f1 ()
{
	int aint;
	static int sint;
	int * p = new int;
	cout << "address of global: " << &gint << endl;
	cout << "address of static: " << &sint << endl;
	cout << "address of auto: " << &aint << endl;
	cout << "address of dynamically allocated: " << p << endl;
	cout << "address of pointer variable: " << &p << endl;
}

int main()
{
	f1();
	return 0;
}