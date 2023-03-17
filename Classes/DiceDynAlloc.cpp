#include <iostream>
#include "dice.h"
using namespace std;

Dice * MakeDie(int n)
//return pointer to n sided object
{
	Dice nSided(n);
	return &nSided;
	//Dice * dice_ptr = new Dice (n);		   
	//return dice_ptr;
}

int main()
{
	Dice * cube = MakeDie (4);			
	Dice * tetra = MakeDie (6);
	cout << cube->NumSides()<<endl;
}
