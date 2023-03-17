#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#define USEMALLOC
using namespace std;

int main()
{
	int i;
	const int NUMITEMS = 5;

	#ifdef USEMALLOC	//using malloc for array definition
		int capacity = NUMITEMS * sizeof (double);
		double * dptr = (double *) malloc (capacity);
	#else				//using calloc for array definition
		double * dptr = (double *) calloc (NUMITEMS, sizeof (double));
	#endif


	for (i=0; i<NUMITEMS; i++)
	{
		dptr[i] = i + 0.1;
	}

	dptr[1] += 3.1;

	for (i=0; i<NUMITEMS; i++)
	{
		cout << dptr[i] << endl;
	}
	cout << endl;

	free(dptr);  //return the allocated memory to heap

	return 0;
}
