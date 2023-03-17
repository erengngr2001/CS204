#include "erengungor_eren_gungor_HW3_TwoDLinkedList.h"
//Eren Güngör
//29465
//Lab Section C2
//Homework3 with VS2012

TwoDLinkedList::TwoDLinkedList()
{
	head = NULL; 
}

//Adds each string from file to linkedlist and creates matrix in alphabetically sorted version.
void TwoDLinkedList::add_row_sorted(string s)
{
	
	if (NULL == head) //for the first given word
	{
		node* p = new node;
		for (int i = 0; i < s.length()-1; i++)
		{
			if (0 == i)
			{
				head = p;
			}
			p->data = s[i];
			p->right = new node;
			p = p->right;
			if (s.length() - 2 == i)
			{
				p->data = s[s.length() - 1];
			}
		}
	}
	else //for the rest
	{
		if (s[0] < head->data)
		{
			node* p = head;
			
			node* q = new node;
			for (int i = 0; i < s.length() - 1; i++)
			{
				if (0 == i)
				{
					head = q;
				}
				q->data = s[i];
				q->down = p;
				q->right = new node;
				p = p->right;
				q = q->right;
			}
			q->data = s[s.length() - 1];
			q->down = p;
			
		}
		else
		{
			node* p;
			node* pre_p;
			int precounter = 0;
			pre_p = head; //in order to keep the previous place that p has been
			p = head;
			while ((NULL != p->down) && (s[0] > p->data)) //shift p (followed by pre_p) accordingly to find where to add the new word
			{
				p = p->down;
				if (0 != precounter)
				{
					pre_p = pre_p->down;
				}
				precounter++;
			}
			//add below
			if ((s[0] > p->data)) 
			{
				node* q = new node;
				for (int i = 0; i < s.length()-1; i++)
				{
					q->data = s[i];
					q->down = p->down;
					p->down = q;
					q->right = new node;
					p = p->right;
					q = q->right;
				}
				q->data = s[s.length()-1];
				p->down = q->down;
				p->down = q;
			}
			//add above
			else
			{
				node* q = new node;
				for (int i = 0; i < s.length() - 1; i++)
				{
					q->data = s[i];
					q->down = pre_p->down;
					pre_p->down = q;
					q->right = new node;
					pre_p = pre_p->right;
					q = q->right;
				}
				q->data = s[s.length() - 1];
				q->down = pre_p->down;
				pre_p->down = q;
			}
		}
	}
}

//Displays matrix starting from head.
void TwoDLinkedList::displayFullMatrix() const
{
	node* p = head;
	node* q = p;
	while (NULL != q)
	{
		while (NULL != p)
		{
			cout << p->data;
			p = p->right;
		}
		cout << endl;
		q = q->down;
		p = q;
	}
}

//Displays matrix in the reversed order.
void TwoDLinkedList::displayFullMatrixReversed()
{
	node* p = new node;
	p->down = head;		
	printLine(p);
}

//A helper function for recursion for displayFullMatrixReversed()
void TwoDLinkedList::printLine(node* p)
{
	if (NULL != p->down)
	{
		p = p->down;
		printLine(p);
		node* q = new node;
		q = p;
		while (NULL != q)
		{
			cout << q->data;
			q = q->right;
		}
		cout << endl;
	}
}

//Displays rows starting with char c.
void TwoDLinkedList::display_rows_starting_with(char c) const
{
	node* p = head;
	node* q = NULL;
	while (NULL != p)
	{
		if (c == p->data)
		{
			q = p;
			while (NULL != q)
			{
				cout << q->data;
				q = q->right;
			}
			cout << endl;
		}
		p = p->down;
	}
}

//Displays columns starting with char c.
void TwoDLinkedList::display_cols_starting_with(char c) const
{
	node* p = head;
	node* q = NULL;
	while (NULL != p)
	{
		if (c == p->data)
		{
			q = p;
			while (NULL != q)
			{
				cout << q->data << endl; 
				q = q->down;
			}
		}
		p = p->right;
	}
}

//Deletes rows starting with char c and returns the number of deleted rows.
int TwoDLinkedList::delete_rows_starting_with(char c)
{
	node* prev; //keep track of p
	node* p;
	p = head;
	prev = head;
	int ct = 0;
	
	while (NULL != p)
	{
		if ((c == p->data) && (head == p)) //if head will be deleted
		{
			node* q = head;
			head = head->down;
			prev = p;
			p = p->down;
			while (NULL != q)
			{
				node* toBeDeleted = q;
				q = q->right;
				delete toBeDeleted;
			}
			ct++;
		}
		else if ((c == p->data) && (NULL == p->down)) //if last row will be deleted
		{
			node* q = p;
			p = NULL;
			while (NULL != q)
			{
				node* toBeDeleted = q;
				prev->down = NULL;
				q = q->right;
				delete toBeDeleted;
			}
			ct++;
		}
		else if ((c == p->data)) 
		{
			node* q;
			node* temp;
			temp = prev;
			q = p;
			p = p->down;
			while (NULL != q)
			{
				temp->down = q->down;
				node* toBeDeleted = q;
				q = q->right;
				temp = temp->right;
				delete toBeDeleted;
			}
			ct++;
		}
		else //if the row will not be deleted
		{
			prev = p;
			p = p->down;
		}
	}

	return ct;
}

//Deletes columns starting with char c and returns the number of deleted columns.
int TwoDLinkedList::delete_cols_starting_with(char c)
{
	node* prev; //keep track of p
	node* p;
	p = head;
	prev = head;
	int ct = 0;

	while (NULL != p)
	{
		if ((c == p->data) && (head == p)) //if head will be deleted
		{
			node* q = head;
			head = head->right;
			p = p->right;
			prev = p;
			while (NULL != q)
			{
				node* toBeDeleted = q;
				q = q->down;
				delete toBeDeleted;
			}
			ct++;
		}
		else if ((c == p->data) && (NULL == p->right)) //if last column will be deleted
		{
			node* q = p;
			p = NULL;
			while (NULL != q)
			{
				node* toBeDeleted = q;
				prev->right = NULL;
				q = q->down;
				delete toBeDeleted;
				prev = prev->down;
			}
			ct++;
		}
		else if ((c == p->data)) 
		{
			node* q;
			node* temp;
			temp = prev;
			q = p;
			p = p->right;
			while (NULL != q)
			{
				temp->right = q->right;
				node* toBeDeleted = q;
				q = q->down;
				temp = temp->down;
				delete toBeDeleted;
			}
			ct++;
		}
		else //if the column will not be deleted
		{
			prev = p;
			p = p->right;
		}
	}

	return ct;
}

//Deletes the matrix entirely and exists the program.
void TwoDLinkedList::clear()
{
	while (NULL != head)
	{
		node* q;
		q = head;
		head = head->down;
		while (NULL != q)
		{
			node* toBeDeleted;
			toBeDeleted = q;
			q = q->right;
			delete toBeDeleted;
		}
	}
}