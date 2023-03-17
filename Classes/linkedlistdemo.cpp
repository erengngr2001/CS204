#include <iostream>
#include "linkedlist.h"
using namespace std;

int main()
{
	linkedlist list;

	for (int k=0; k < 4; k++)  
	{
		list.addToBeginning(k+1);
	}

	list.printList();
}

