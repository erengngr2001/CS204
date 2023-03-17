//Demonstrates templated linked list class

#include <iostream>
#include <string>
#include "linkedlisttemplate.h"
//#include "linkedlisttemplate.cpp"
using namespace std;

int main()
{
	string baskan[] = {"Ahmet Agaoglu", "Ali Koc", "Burak Elmas", "Ahmet Nur Cebi"};
	LinkedList<string> strlist;	//Linked list object with string element type
	LinkedList<int> intlist;	//Linked list object with integer element type

	for (int k=0; k < 4; k++)  
	{
		strlist.addToBeginning(baskan[k]);
		intlist.addToBeginning(k+1);
	}

	cout << "string list contains:\n";
	strlist.printList();

	cout << "integer list contains:\n";
	intlist.printList();
	
}  

