#include<stdio.h>

long long int gcd(long long int a, long long int b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}

int main (void)
{
    long long c, y, i, temp;
    double x, k, a, b;

    while(scanf("%lf%lf", &a, &b) != EOF)
    {
        if(a == b)
        {
            printf("0 1 %.0lf\n", a);
        }

        else
        {
            c = gcd(a, b);

            for(y = 1; ; y++)
            {
                x = ((double)c-b*y)/a;
                temp = x;
                k = temp;
                if(x == k)
                {
                    printf("%lld %lld %lld\n", temp, y, c);
                    break;
                }
            }
        }

    }
    return 0;
}
