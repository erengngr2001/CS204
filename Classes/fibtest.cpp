#include <iostream>
using namespace std;
#include "ctimer.h"
#include "prompt.h"
#include <vector>

// Illustrates "bad" recursion for computing Fibonacci numbers
// also illustrates how to fix this efficiency problem

//Recursive 
int RecFib(int n)
// precondition: 0 <= n
// postcondition: returns the n-th Fibonacci number
{
    if (0 == n || 1 == n)
    {   return 1;
    }
    else
    {   return RecFib(n-1) + RecFib(n-2);
    }
}

//Recursive but the efficiency problem due to multiple calls is now fixed
int RecFibFixed(int n)
// precondition: 0 <= n <= 30
// postcondition: returns the n-th Fibonacci number
{
    static vector<int> storage(31,0);

    if (0 == n || 1 == n)
    {   return 1;
    }
    else if (storage[n] == 0)
    {   storage[n] = RecFibFixed(n-1) + RecFibFixed(n-2);
        return storage[n];
    }
    else
    {   return storage[n];
    }
}

//iterative
int Fib(int n)
// precondition: 0 <= n
// postcondition: returns the n-th Fibonacci number
{
    int first=1, second=1, temp;
    int k;
    for(k=0; k < n; k++)
    {   temp = first;
        first = second;
        second = temp + second;
    }
    return first;
}

int main()
{
    CTimer rtimer,itimer;
	int j;
	int  k;
    int ival,rval;
	int iters = PromptRange("enter # of iterations",1,1000000);
	int limit =  PromptRange("how many Fibonacci numbes to be calculated?",1,30);
    
    for(k = 0; k < iters; k++)
    {   for(j=0; j <= limit; j++)
        {   rtimer.Start();
            rval = RecFib(j); //change the function to RecFibFixed to test the fixed version
            rtimer.Stop();
            itimer.Start();
            ival = Fib(j);
            itimer.Stop();
        }
    }
    cout << iters << " recursive trials " << rtimer.CumulativeTime() << endl;
    cout << iters << " iterative trials " << itimer.CumulativeTime() << endl;
    return 0;
}
