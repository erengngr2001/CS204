#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

struct node {
	int info;
	node *next; 

	node ()
	{}

	node (const int & s, node * link)
		: info(s), next (link)
	{}
};

class linkedlist 
{
	private:
		node * head;
	public:
		 linkedlist ();
		 void printList();
		 void addToBeginning(int n);
};

#endif