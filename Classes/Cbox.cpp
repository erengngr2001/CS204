#include <iostream>
using namespace std;

class CBox {
 public: 

#ifdef NOT
	//base class constructor
	CBox ()
	{
		cout << "\nCBox default constructor called" << endl ;
		m_length  = 1;
		m_breadth = 1;
		m_height  = 1; 
	};
#endif

	CBox (double lv = 1.0, double bv = 1.0, double hv = 1.0):
	//CBox (double lv, double bv, double hv):
		m_length(lv), m_breadth(bv), m_height(hv)
	{
		cout << "\nCBox constructor called" << endl ;
	};

	//copy constructor = equivalent to what the compiler would give
	CBox(const CBox & initB)
	{
		cout << "\nCBox copy constructor called" << endl ;

		m_length = initB.m_length;
		m_breadth = initB. m_breadth ;
		m_height  = initB.m_height; 
	}
	
	//try the effect of having virtual keyword here
	virtual double Volume() const
	{ return m_length*m_breadth*m_height;}

	protected:
		double m_length;
		double m_breadth;
		double m_height;
};

//Derived class --------------------------------------------------
class CCandyBox : public CBox
{
 public: 

	// if you do not have default values, this constructor is not considered 
	// as a default constructor
	CCandyBox (double lv, double bv, double hv, char *label = "Candy")
		: CBox(lv,bv,hv)
	{	
		cout << "CCandyBox constructor called" << endl ;
		m_label = new char [strlen(label)+1];
		strcpy (m_label, label);
	}

	//copy constructor that does the intended job
	//Try this by commenting :CBox(initCB) line. This way, base class (CBox) copy constructor is not called, 
	//but its default constructor is called, which causes to set the dimensions of the copy constructed object to all 1.0.  
	CCandyBox (const CCandyBox & initCB)
		:CBox(initCB)    
	{	
		cout << "CCandyBox copy constructor called" << endl ;
		m_label = new char [strlen(initCB.m_label)+1];
		strcpy (m_label, initCB.m_label);
	}

	//override Volume functions - returns reduced volume due to padding
	//virtual keyword is optional here but it is a good practice to use
	virtual double Volume() const
	{ return 0.85*m_length*m_breadth*m_height;}

	void ChangeLabel(char *label = "Candy")
	{
		free(m_label);
		m_label = new char [strlen(label)+1];
		strcpy (m_label, label);
	}

	protected:
		char * m_label;
};

//----------------------------------------------------------------
int main()
{
	CBox b1(2,3);
	CBox b2;

	CCandyBox cb1 (2.0, 2.0, 4.0, "Choc.");	//allocates memory for the label
	CCandyBox cb2(cb1);			//calls the copy constructor

	//change the label of cb2; since e new memory area is allocated for 
	//the label of cb2, this change does not affect cb1
	cb2.ChangeLabel("firstChocolateBox");

	//Demonstrations of Polymorphism
	cout << "\n*****************************************************" << endl;
	cout << "*************** Polymorphism Demos ******************" << endl;
	cout << "*****************************************************" << endl;
	//Assignment to base class has problems 
	cout << endl << "Volume test with assignment cb2 to b2 *****" << endl;
	b2 = cb2;
	cout  << "b2's (cb2's) volume should be (13.6): " << b2.Volume() << endl;
	//Pointers to Base and Derived Classes -------------------
	//try this with and without declaring Volume() function of the base class virtual
	cout << endl << "Volume test with pointers to b1 and cb1" << endl;
	CBox * ptr;
	ptr = &b1;
	cout  << "b1's volume should be (6): " << ptr->Volume() << endl;

	ptr = &cb1;
	cout  << "cb1's volume should be (13.6): " << ptr->Volume() << endl;

	//Pointers to Dynamic Base and Derived Classes Objects -----
	//try this with and without declaring Volume() function of the base class virtual
	CBox * p_b = new CBox(4, 4, 4);
	CCandyBox * p_c = new CCandyBox(4, 4, 4);
	cout << endl << "Volume test with pointers to dynamic objects - before assignment" << endl;
	cout  << "cbox's volume should be (64): " << p_b->Volume() << endl;
	cout  << "Candybox's volume should be (54.4): " << p_c->Volume() << endl;
	
	cout << endl << "Volume test with pointers to dynamic objects - after assignment" << endl;
	p_b = p_c;
	cout  << "cbox's volume should be (54.4): " << p_b->Volume() << endl;
	cout  << "Candybox's volume should be (54.4): " << p_c->Volume() << endl;


return 0;
}	