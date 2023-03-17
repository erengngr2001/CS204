#include <iostream>

using namespace std;


int main()
{
	const int num = 10;
	#define TESTDATA 5
	cout << TESTDATA << endl;
	#define TESTDATA 10 //first try as is, then try by removing 10
	cout << TESTDATA << endl; 

	//#undef TESTDATA     // remove the comments to see the effect of #undef
						// when an undefined preprocessor identifier is used in an expression, it is considered as 0 in Visual Studio.
						// This is an unexpected behavior, so please be careful while using an undefined identifier. 
						// This is also a non-standard behavior, so in other compilers, you can see different outcomes.

	#ifdef TESTDATA
		cout << "#ifdef TESTDATA" << endl;
	#endif

	#ifndef COUNT
		cout << "#ifndef COUNT" << endl;
	#endif	

    /* you can use comparison and boolean operators*/
	#if 0 == TESTDATA
		cout << "entered #if" << endl;
	#elif TESTDATA > 5 && TESTDATA <= 10
		cout << "entered #elif" << endl;
	#else
		cout << "entered #else" << endl;
	#endif

	/* You can use expressions */
	#if TESTDATA-5 == 5
		cout << "entered #if again" << endl;
	#endif

	/* use only literals and #defined identifier; using regular variables may not cause an error, but may cause unexpected results*/
	#if num == 10	                  // should be false since num is 10, but evaluates to true since num is not a preprocessor identifier and considered as zero
								  // this behavior is non-standard and in another development environment it may work differently. Thus do not use variables here.
								  // also try using 10 instead 0. This time cout statement will not be included in the translation unit.
		cout << "variable check" << endl;    
	#endif

	return 0;
}