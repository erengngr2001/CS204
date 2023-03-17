#include <iostream>
#include "linkedlistextraoper.h"
using namespace std;

//debug with F11 to see how the functions are invoked

int main()
{
	LinkedList list1, list3;

	for (int k=0; k < 4; k++)  
	{
		list1.addToBeginning(k+1);
	}

	cout << "list1 contains:\n";
	list1.printList();
	

	LinkedList list2(list1); 
	cout << "list2 is created from list1 using copy constructor\n";
	list2.printList();
	
	list3 = list1; 
	cout << "list1 is assigned to list3\n";
	list3.printList();
	
	list1.deleteList();
	cout << "list1 is deleted\n";

	cout << "\nlist2 contains:\n";
	list2.printList();

	cout << "\nlist3 contains:\n";
	list3.printList();

	list1.addToBeginning(100);
	list1.addToBeginning(50);
	cout << "list1 is reinitialized and contains:\n";
	list1.printList();

	list2 = list1; // same as list2.operator = (list1);
	cout << "list1 is assigned to list2\n";
	cout << "list2 contains:\n";
	list2.printList();
	
	//also try list3 =list2 = list1; and display list3 and list2
	list3 = list2 = list1;
	cout << "list1 is assigned to list2 and list3\n";
	cout << "list2 contains:\n";
	list2.printList();
	cout << "list3 contains:\n";
	list3.printList();

	cout << "list2 is assigned to itself\n";
	cout << "list2 contains:\n";
	list2 = list2;      //try this also after deleting
					//if (this != &rhs) at operator definition
	list2.printList();
	

	/* ALSO TRY
	   - change deep copy to shallow copy constructor
	   - change "const LinkedList &" return type of assignment operator to  "LinkedList" return type
	       - this invokes copy constructor at return time and destructor for the value returned at the end of statement
	   with these changes, list3 = list1; assignment causes a copy constructed linked list to be returned (which contains the same nodes of list3 due to shallow copy)
	   and this copy constructed list is destructed after assignment. Thus list3 contains a destructed list. 
	*/
}  

