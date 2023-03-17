#include <iostream>
using namespace std;

double max( double d1, double d2 )
{
	if ( d1 > d2 )
		return d1;
	else
		return d2;
}

int max( int i1, int i2 )
{
	if ( i1 > i2 )
		return i1;
	else
		return i2;
}

int main()
{
   int    i = max( 12, 8 );  //calls second one
   double d = max( 17.4, 32.9 ); //calls first one
   //cout << max(12, 33.3);
   return 0;
}
