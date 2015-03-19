#include<stdio.h>

long long int gcd(long long int a, long long int b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}

int main (void)
{
    long long int a, b, c, cases;
    scanf("%lld", &cases);
    while(cases--)
    {
        scanf("%lld / %lld", &a, &b);
        c = gcd(a, b);
        printf("%lld / %lld\n", a/c, b/c);
    }
    return 0;
}
