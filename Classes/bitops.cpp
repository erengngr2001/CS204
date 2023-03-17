#include <iostream>
using namespace std;

int main ()
{
	short nums = -200;
	cout << "hexadecimal: " << hex << nums << "   decimal: " << dec <<  nums << endl;

	unsigned int numi = 0xfd04e0e4;	
	cout << "hexadecimal: " << hex << numi << "   decimal: " << dec << numi << endl;

	cout << "Enter an unsigned integer in hex (you could put 0x to the beginning or not): ";
	cin >> hex >> numi;
	cout << "Decimal equivalent of the number entered: " << numi << endl;

	cout << "-7/2 is "<< -7/2 << "   -7 >> 1 is " << (-7 >> 1) << endl;	
	
	char x,y,z;

	x = 0x33;
	x = (x << 3) | 0x0F;
	y = (x >> 1) & 0x0F;
	z = x && y;

	//Attendance example is below
	unsigned char attendance = 0x00; 
	//let the LSB be for quiz 1, the next one is for quiz 2, . . .  
	//0 means unattended, 1 means attended
	//there are total of  8 quizzes; initally all unattended

	unsigned char mask=0x01;  // 00010000 in binary

	//Draft code showing how attendance array may be filled
	//if attended to quiz 1
	attendance = attendance | mask;  
	//if attended quiz 3
    mask = mask << 2; 	// mask becomes 0000 0100 
	attendance = attendance | mask;   


	//to display attendance information 
	mask=0x01;
	for (int i=1; i <= 8; i++)
	{
		if (attendance & mask) 
			cout << "Student attended quiz number " << i << endl;
		else   
			cout << "Student missed quiz number " << i << endl;
		mask = mask << 1;
	}


	return 0;
}
