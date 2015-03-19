#include<stdio.h>

long long int gcd(long long int a, long long int b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}

int main (void)
{
    int n;
    while(scanf("%d", &n) == 1 && n)
    {
        long long int G = 0;
        int i, j;
        for(i = 1; i < n; i++)
        {
            for(j = i+1; j <= n; j++)
            {
                G += gcd(i,j);
            }
        }
        printf("%lld\n", G);
    }


    return 0;
}
