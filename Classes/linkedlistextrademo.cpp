#include <iostream>
#include "linkedlistextra.h"
using namespace std;

/************************************************************************
* This function is to show the effect of using reference and value		*
* parameters for the classes. When you use reference or const-reference	*
* parameter, the argument is not copied to the parameter, thus copy		*
* constructor is not invoked. However if you pass a class parameter by	*
* value, implicitly the copy constructor is invoked. If you use default	*
* or shallow copy constructor, when list is destructed at the end of the*
* function original list is also destructed and this causes a problem.	*
* Thus it is always better to use reference or const-reference			*
* parameters for classes. Using deep copy constructor also solves the	*
* problem of value parameters.											*
*																		*
* Try this function with the different combinations of					*
* value, reference and const-reference parameters, and shallow and		*
* deep copy constructors.												*
************************************************************************/
void Print (const LinkedList & list)
{
	list.printList();
}


int main()
{

	
	LinkedList list1;
	
	//uncomment the following code to see destructor is called when a dynamically allocated object is deleted.

	/*LinkedList * p = new LinkedList;
	p->addToBeginning(10);
	p->printList();
	delete p;*/

	for (int k=0; k < 4; k++)  
	{
		list1.addToBeginning(k+1);
	}



	//Uncomment the next line to test the effect of Print function (see the description above at the definition of Print
	//Print(list1);
	
	list1.printList();
	/************************************************************************
	* In the following piece of code, if we use default/shallow copy		*
	* constructor, then when we delete list1, the list of list2 is also		*
	* deleted. Then, program crashes when list2 is being printed.			*
	*																		*
	* Actually even if we do not print list2 and/or delete list1, program   *
	* crashes or shows an abnormal behavior in debug mode.                  *
	* This is due to trying to delete the memory locations of the list	    *
	* twice (one for list1, one for list2)	by the destructor.		        *
	*																		*
	* For deep constructor, there are no such problems. Try it with deep	*
	* copy constructor as well.												*
	************************************************************************/
	
	 /*LinkedList list2(list1);
	 list1.deleteList();
	 list2.printList();*/

	//LinkedList list3;  //uncomment this in the first trial to see the effect of destructing different objects

}   //Debug with F11 at the end of program to see how destructor is invoked 
	//automatically

