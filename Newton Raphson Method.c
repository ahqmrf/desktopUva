#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define f(x) ((x)*(x)-3*(x)+2)
#define df(x) (2*(x)-3)

int main (void)
{
    double x0 = 3.0;
    double x;
    int count = 1;
    while(1)
    {
        x = x0 - (f(x0)/df(x0));
        if(fabs(x0-x) < 0.1E-5) break;
        x0 = x;
        count++;
    }

    printf("%d %g\n",count, x);

    return 0;
}
