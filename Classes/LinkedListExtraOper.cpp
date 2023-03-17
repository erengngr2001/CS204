#include <iostream>
#include "linkedlistextraoper.h"
using namespace std;

//default constructor
LinkedList::LinkedList ()
{
	head = NULL;
	size = 0;
}

//Copy constructor for shallow copy.
//You may either have this of deep copy version below.
//You may also delete both and the definition in class definition
//to see the default copy constructor works exactly as this shallow one.
/*LinkedList::LinkedList (const LinkedList & copy)
{
	head = copy.head;
	size = copy.size;
	cout << "shallow copy constructor called, head= " << head << endl;
}*/


//Copy constructor for deep copy
LinkedList::LinkedList (const LinkedList & copy)
{
	head = copy.createClone();
	size = copy.size;
	cout << "deep copy constructor called, head= " << head << endl;
}

//destructor function visits all nodes and returns to heap
LinkedList::~LinkedList ()
{
	cout << "destructor called for list with head= " << head << endl;
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


const LinkedList & LinkedList::operator = (const LinkedList & rhs)
{
	if (this != &rhs)
	{
		deleteList(); // same as this->deleteList()
		head = rhs.createClone();
		size = rhs.size;
	}
	return *this;
}


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