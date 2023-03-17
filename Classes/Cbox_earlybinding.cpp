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

	void ShowVolume() const
	{
		cout << "\tShowVolume result is: " << Volume() << endl << endl;
	}

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
	CCandyBox (const CCandyBox & initCB):
		CBox(initCB)
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

	CCandyBox cb1 (2.0, 2.0, 4.0, "Choc.");	//allocates memory for the label

	cout  << "b1 volume should be (6): " << b1.Volume() << endl;
	b1.ShowVolume();

	//Lets see the effect of virtual --------------------------
	cout  << "cb1 volume should be (13.6): " << cb1.Volume() << endl;
	cb1.ShowVolume();

return 0;
}	