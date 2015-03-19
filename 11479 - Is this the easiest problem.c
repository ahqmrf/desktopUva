#include<stdio.h>

int main (void)
{
    long long int i, t, a, b, c;
    scanf("%lld", &t);
    for(i = 1; i <= t; i++)
    {
        scanf("%lld%lld%lld", &a, &b, &c);
        printf("Case %lld: ", i);
        if(a >= b+c || b >= a+c || c >= a+b)
        {
            printf("Invalid\n");
        }

        else if( a <= 0 || b <= 0 || c <= 0)
        {
            printf("Invalid\n");
        }

        else
        {
            if(a == b && b == c)
            {
                printf("Equilateral\n");
            }

            else if( a ==b || a == c || b == c)
            {
                printf("Isosceles\n");
            }

            else printf("Scalene\n");
        }
    }

    return 0;
}
