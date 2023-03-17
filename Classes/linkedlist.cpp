#include <iostream>
#include "linkedlist.h"
using namespace std;

linkedlist::linkedlist ()
{
	head = NULL;
}


void linkedlist::addToBeginning (int n)
{
	node *ptr = new node(n,head);
    head = ptr;		
}	

void linkedlist::printList ()
{
	node * ptr = head;
    while (ptr != NULL) 
	{
		cout << ptr ->info << endl;
		ptr = ptr->next;
	}
	cout << endl;
}


