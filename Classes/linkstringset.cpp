#include "linkstringset.h"

/*******************************************************************/
/* Constructor */
LinkStringSet::LinkStringSet()
  : myFirst(new Node("header",0)),
    mySize(0)
{
   // header node created
}

/*******************************************************************/
/* Simple accessors */

int LinkStringSet::size() const
{
    return mySize;
}

/*******************************************************************/
/* Code for finding and inserting */

bool LinkStringSet::contains(const string& s) const
{
    Node * temp = findNode(s);
    return temp != 0;
}

/*-------------------------------------------*/
LinkStringSet::Node * LinkStringSet::findNode(const string& s) const
// post: returns pointer to node before s or NULL/0 if !contains(s)
{
    Node * list = myFirst; // list non-zero
    
    while (list->next != 0 && list->next->info != s)
    {   list = list->next;
    }
    if (list->next == 0) return 0;
    return list;
}

/*-------------------------------------------*/
void LinkStringSet::insert(const string & s)
{
    if (! contains(s))
    {   myFirst->next = new Node(s,myFirst->next);
        mySize++;
    }
}

/*******************************************************************/
/* Copy constructor */
LinkStringSet::LinkStringSet(const LinkStringSet& set)
  : myFirst(new Node("header",set.clone())),
    mySize(set.size())
{
    // initializer list made deep copy
}

/*******************************************************************/
const LinkStringSet&
LinkStringSet::operator = (const LinkStringSet& set)
{
    if (&set != this)
    {   reclaimNodes(myFirst->next);
        myFirst->next = set.clone();
        mySize = set.size();
    }
    return *this;
}

/*-------------------------------------------*/
LinkStringSet::Node * LinkStringSet::clone() const
{
    Node front("front",0);   // node, not pointer, anchors copy
    Node * last = &front;    // be wary of using address of operator!
    
    Node * temp = myFirst->next;
    while (temp != 0)
    {   last->next = new Node(temp->info,0);
        last = last->next;
        temp = temp->next;
    }
    return front.next;
}

/*******************************************************************/
/* Code for erasing, deleting ...                                  */

/* Erase a particular entry by deleting its node*/
void LinkStringSet::erase(const string& s)
{
    Node * temp = findNode(s);
	//temp points to node before s
    if (temp != 0)
    {   Node * removal = temp->next;
        temp->next = removal->next;
        delete removal;    // can we reuse this?
        mySize--;
    }
}

/*-------------------------------------------*/
/* Free the storage of the nodes, only       */
void LinkStringSet::reclaimNodes(Node * ptr)
{
    if (ptr != 0)
    {   reclaimNodes(ptr->next);
        delete ptr;
    }
}

/*-------------------------------------------*/
/* Free the storage and set the set to empty */
void LinkStringSet::clear()
{
    reclaimNodes(myFirst->next);
    myFirst->next = 0;           // nothing in the set
    mySize = 0;
}

/*-------------------------------------------*/
/* You still need the destructor, even with all the above, 
since the compiler only expects/knows this one */
LinkStringSet::~LinkStringSet()
{
    reclaimNodes(myFirst);
    myFirst = 0;
}