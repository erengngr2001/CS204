#include <iostream>
#include "linkedlistextra.h"
using namespace std;

LinkedList::LinkedList ()
{
	head = NULL;
	size = 0;
}

/****************************************************************
*			Copy Constrcutor - shallow copy						*
* This function just copies private data members				*
* and may cause problems in certain cases.						*
* First try the program with this and see the problems.			*
* Then use the deep copy constructor provided below and see		*
* that the problems are resolved.								*
* Moreover, compiler's default copy constructor does the same	*
* job with this shallow copy constructor. Try this by removing	*
* both shallow and deep constructors.							*
* In all cases get in the functions during debug (F11) to see	*
* how they behave. Press F11 at the end of the program to see	*
* how destructor is invoked.									*
****************************************************************/
LinkedList::LinkedList (const LinkedList & copy )	
{
	cout << "shallow copy constructor called" << endl;
	head = copy.head;
	size = copy.size;
}

/****************************************************************
*				Copy Constrcutor - deep copy					*
* This is the good copy constrcutor. It copies everything		*
* including the dynamically allocated memory. Try this as well.	*
****************************************************************/
/*LinkedList::LinkedList (const LinkedList  & copy)
{
	cout << "deep copy constructor called" << endl;
	head = copy.createClone();
	size = copy.size;
}*/

//generates a clone of the linked list object by generating new copies of
//each node and connecting them as in the original.
//Returns the head of the clone list.
node * LinkedList::createClone () const
{
	if (head == NULL)  //if list is empty
		return NULL;   //clone is empty as well
	
	//first generate the first clone node and connect to head of clone
	node * headClone = new node (head->info, NULL);
	node * ptr = head->next;  //second node in orig.
	node * ptrClone = headClone; //to track the clone list
   while (ptr != NULL) 
	{
		ptrClone->next = new node (ptr->info, NULL);
		ptr = ptr->next;
		ptrClone = ptrClone->next;
	}
	return headClone;
}


//destructor function visits all nodes and returns to heap.
//sometimes causes problems (assertion failure) when called for an 
//already deleted list. To avoid this lists should not share nodes.
//Thus in the copy constructor and assignment, you have to do deep copy.
LinkedList::~LinkedList ()
{
	cout << "destructor called" << endl;
	node * ptr = head;
    while (ptr != NULL) 
	{
		node * temp = ptr->next;
		delete ptr;
		ptr = temp;
	}
}

void LinkedList::addToBeginning (int n)
{
	node *ptr = new node(n,head);
    head = ptr;	
	size++;
}	

void LinkedList::printList () const
{
	node * ptr = head;
    while (ptr != NULL) 
	{
		cout << ptr ->info << endl;
		ptr = ptr->next;
	}
	cout << endl;
}

void LinkedList::deleteList ()
{
	node * ptr = head;
    while (ptr != NULL) 
	{
		node * temp = ptr->next;
		delete ptr;
		ptr = temp;
	}
	head = NULL;
	size = 0;
}
