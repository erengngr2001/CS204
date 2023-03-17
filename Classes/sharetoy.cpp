#include <iostream>
#include <string>
using namespace std;

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//Program to show how to share an object (e.g. toy) between instances of a class,
//without each of them making a separate copy for themselves. The Naive (not working),
//REFVAR (using a reference variable, working) and POINTER (using pointers, working)
//solutions are provided.
//From Tapestry.
//Project author: B. Yanikoglu
//Modified by: A. Levi
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//Uncomment only one 
//#define REFVAR
//#define POINTER
#define NAIVE

/******************************** TOY CLASS *******************/
/* Toy class */
class Toy   // kids play with toys
{
  public:
    Toy (const string& name);
    void Play();        // prints a message
    void Breaks();		// the toy breaks
  private:
    string myName;		//name of toy
    bool   myIsWorking;	//working condition
};

//constructor
Toy::Toy(const string& name)
 : myName(name), myIsWorking(true)
{ }

// post: toy is played with, message printed
void Toy::Play()
{   
    if (myIsWorking)
    {   cout << "this " << myName << " is so fun :-)" << endl;
    }
    else
    {   cout << "this " << myName << " is broken :-(" << endl;
    }
}

void Toy::Breaks()
// post: toy is broken
{
    myIsWorking = false;
    cout << endl << "oops, this " << myName << " just broke" << endl << endl;
}



/******************************** KID CLASS *********************/
/* Kid class with 3 different declaration to share the same toy */

#if defined(NAIVE)
// NAIVE version below 
class Kid
{
  public:
    Kid (const string & name, Toy & toy);
    void   Play();        // plays with own toy
  private:
    string myName;		//name of the kid
	Toy myToy;			//creates a local copy, this is problematic 
};

//constructor
Kid::Kid(const string & name, Toy & toy)
 : myName(name), myToy(toy)
{ }

void Kid::Play()
// post: kid plays and talks about it
{
   cout << "My name is " << myName << ", ";
   myToy.Play();
}
#elif defined(REFVAR)
// Reference variable version below 
class Kid
{
  public:
    Kid (const string & name,  Toy & toy);
    void   Play();        // plays with toy
  private:
    string myName;		  //name of the kid
    Toy & myToy;	//reference variable for an external Toy object
};

//constructor
Kid::Kid(const string & name,  Toy & toy)
 : myName(name), myToy(toy)
{ }

void Kid::Play()
// post: kid plays and talks about it
{
   cout << "My name is " << myName << ", ";
   myToy.Play();
}

#elif defined(POINTER)
//POINTER version below
class Kid
{
  public:
    Kid (const string& name, Toy * toy);
    void   Play();        // plays with toy
  private:
    string myName;		  //name of the kid
    Toy *myToy;		//pointer to an external Toy object
};

//constructor
Kid::Kid(const string & name,Toy * toy)
 : myName(name), myToy(toy)
{ }

void Kid::Play()
// post: kid plays and talks about it
{
   cout << "My name is " << myName << ", ";
   myToy->Play();
}

#endif

int main()
{
	//lets have a toy
    Toy atoy("ball");

#if defined(NAIVE) || defined(REFVAR) 
			//Naive and Ref. var. versions are the same 
    Kid erich("erich", atoy);
    Kid katie("katie", atoy);
	erich.Play(); katie.Play();
    atoy.Breaks();     // the toy is now broken
    erich.Play(); katie.Play();  

#elif defined(POINTER)
	Kid erich("erich", &atoy);
    Kid katie("katie", &atoy);
	erich.Play(); katie.Play();
    atoy.Breaks();     // the toy is now broken
    erich.Play(); katie.Play();  

#endif

    return 0;
}
