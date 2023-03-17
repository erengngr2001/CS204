#ifndef _LINKEDLISTEXTRAOPER_H
#define _LINKEDLISTEXTRAOPER_H

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
		 LinkedList (const LinkedList &);  //copy constructor 
		 ~LinkedList ();   //destructor
		 void printList() const;
		 void addToBeginning(int n);
		 void deleteList ();
		 const LinkedList & operator = (const LinkedList & rhs);
		 node * createClone () const; //generates the clone of the list and return the clone's head
};

#endif