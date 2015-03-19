#include<stdio.h>
#include<math.h>

int main (void)
{
    double const logOf2Base10 = log10(2);
    int n, case_no = 0;
    while(scanf("%d", &n) == 1 && n > -1)
    {
        if(n == 1 || n == 0) printf("Case %d: 0\n", ++case_no);
        else
        {
            double num = (double)n;
            double power = log10(num) / logOf2Base10;
            int powerInt = (int) power;
            double powerDouble = (double) powerInt;

            if(powerDouble < power) powerInt++;

            printf("Case %d: %d\n", ++case_no, powerInt);
        }
    }
    return 0;
}
