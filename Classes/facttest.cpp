#include <iostream>
using namespace std;
#include "ctimer.h"
#include "prompt.h"
#include "bigint.h"

BigInt RecFactorial(int num)
// precondition: 0 <= num
// postcondition: returns num! (num factorial)
{
    if (0 == num)
    {   return 1;
    }
    else
    {   return num * RecFactorial(num-1);
    }
}

BigInt Factorial(int num)
// precondition: 0 <= num
// postcondition: returns num! (num factorial)     
{
    BigInt product = 1;
    int count;
    for(count=1; count <= num; count++)
    {   product *= count;
    }
    return product;
}

int main()
{
    CTimer rtimer,itimer;
    long j,k;
    BigInt rval,ival;
    int iters = PromptRange("enter # of iterations",1,1000000);
    int  limit = PromptRange("upper limit on factorial",0,100);
    
    for(k=0; k < iters; k++)    // compute factorials specified # of times
    {   for(j=0; j <= limit; j++)
        {   rtimer.Start();                   // time recursive version
            rval = RecFactorial(j);
            rtimer.Stop();
            itimer.Start();                   // time iterative version
            ival = Factorial(j);
            itimer.Stop();
        }
    }
    cout << iters << " recursive trials " << rtimer.CumulativeTime() << endl;
    cout << iters << " iterative trials " << itimer.CumulativeTime() << endl;
    return 0;    
}
