#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define f(x) (a*(x)*(x)*(x)*(x)+b*(x)*(x)*(x)+c*(x)*(x)+d*(x)+e)
#define df(x) (a*4*(x)*(x)*(x)+b*3*(x)*(x)+c*2*(x)+d)

int main (void)
{
    int a, b, c, d, e;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
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