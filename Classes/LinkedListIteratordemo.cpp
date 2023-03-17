#include <iostream>
#include "linkedlistiterator.h"
using namespace std;

// demo of linked list iterator class

void Print(const LinkedList & theList)
{
    LinkedListIterator iter (theList);  //binding the iterator object to list
	
	//theList.addToBeginning (200);  //does not compile with const parameter.
						//remove const and try. What do you expect to display?
						//Is first node 200 or not?
	
	//LinkedListIterator iter2(iter); //this line shows the default copy constructor. 
				//decomment this statement and change "iter"s with "iter2" in the rest of 
				//this function. Default copy constructor makes shallow copy
				//but this is what we want here. 
	
	for(iter.Init(); iter.HasMore(); iter.Next())
	{  
		cout << iter.Current() << endl;
    }
    cout  << "size = " << theList.length() << endl << endl;
}

//The following function and loop exemplifies how to update the linked list elements through iterator. 
//This can be done only if Current() returns a reference.
//Change the definition of Current() to make this work.
/*void IncrementAll (const LinkedList & theList)
{
    LinkedListIterator iter (theList);  //binding the iterator object to list

	for(iter.Init(); iter.HasMore(); iter.Next())
	{  
		iter.Current()++;	
    }
}*/

int main()
{
	LinkedList list1;

	for (int k=0; k < 4; k++)  
	{
		list1.addToBeginning(k+1);
	}

	//IncrementAll(list1);  //to demonstrate changing 

	cout << "content of list1 (using free Print function):\n";
	Print(list1);

	cout << "content of list1 (using printList member function):\n";
	list1.printList();
	
	return 0;
}  

