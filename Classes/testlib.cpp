#include "staticlib.h"
#include "iostream"

using namespace std;

int main()
{
	int num1, num2;
	cout << "Enter two numbers to add up" << endl;
	cin >> num1 >> num2;
	cout << myadd(num1,num2) << endl;

	return 0;
}