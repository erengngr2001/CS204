#ifndef _LINKEDLISTEXTRA_H
#define _LINKEDLISTEXTRA_H

struct node {
	int info;
	node *next; 

	node ()
	{}

	node (const int & s, node * link)
		: info(s), next (link)
	{}
};

class LinkedList 
{
	private:
		node * head;
		int size;
	public:
		 LinkedList ();
		 LinkedList (const LinkedList & );  //copy constructor
		 ~LinkedList ();
		 void printList() const;
		 void addToBeginning(int n);
		 void deleteList ();
		 node * createClone () const; 
			//generates the clone of the list and return the clone's head
};


#endif