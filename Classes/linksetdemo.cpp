#include <iostream>
using namespace std;
#include "linkstringset.h"

// demo of string sets implemented with linked lists

void Print(const LinkStringSet& set)
{
    LinkStringSetIterator it(set);
    for(it.Init(); it.HasMore(); it.Next())
    {   
		cout << "\t" << it.Current() << endl;
    }
    cout  << endl << "---------- size = " << set.size() << endl << endl<<endl;
}

int main()
{
    LinkStringSet a,b;
    
    a.insert("apple");
    a.insert("cherry");
    cout << "a : "; Print(a);
    b = a;
    cout << "b : "; Print(b);
    a.clear();
    cout << "a : "; Print(a);
    cout << "b : "; Print(b);

	LinkStringSet c;
	c.insert("watermelon");
	c.insert("apricot");
	//Iterate over list c and append " seed" to the end of info field of each node
	//define and undefine the preprocessor identifier UPDATELIST and see Current()
	//affects the outcome.
	LinkStringSetIterator itr(c);
    for(itr.Init(); itr.HasMore(); itr.Next())
    {   
		itr.Current().append(" seed");
	    
		//alternative implementation of above using reference variable
		/*string & currentInfo= itr.Current();
		currentInfo.append(" seed");*/

    }
	cout << "after update\nc : ";
	Print(c);

    return 0;
}
