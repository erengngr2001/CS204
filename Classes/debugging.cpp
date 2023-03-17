#include <iostream>
#include <cassert>
using namespace std;

/***********************************************************
This program shows various debug alternatives that students can 
play with. Build and run in both debug and release configurations.
Refer to corresponding lecture notes.
Author: Berrin Yanikoglu
Date: 24/2/2005
Modified: Albert Levi
Date: 04/07/2011
Bugs: No known
***********************************************************/ 


/***********************************************************/
// a function you received from a colleague, you don't know 
//fully what it does
/***********************************************************/

void func1(int & n) 
{
	n = 1;
}

/***********************************************************/
//main function
/***********************************************************/
void main()
{

int count = 0;	

#ifdef _DEBUG
//this code will be executed under the DEBUG config. only
	#define DEBUG1	//won't be defined under Release config.
	//#define DEBUG2	//won't be defined under Release config.
#endif

#ifdef DEBUG1
	//this code will be executed under the DEBUG config. only
	cout << "debugging comment conditioned on DEBUG1" << endl;
#endif

	func1(count);  //count becomes 1

#ifdef DEBUG2
	//this code will be executed if DEBUG2 is defined
	cout << "debugging comment conditioned on DEBUG2"<< endl;
#endif


	assert(count == 0);   //in debug mode program will crash here
						  //in release mode it will not crash

}