#include<stdio.h>
long long int Mod(long long int x, long long int n, long long int M)
{
    if(n == 0) return 1;
    else if(n%2 == 0)
    {
        int y = Mod(x, n/2, M);
        return (y*y) % M;
    }

    else return ((x%M) * Mod(x, n-1, M)) % M;
}

int main (void)
{
    long long int a, p, c;
    while(scanf("%lld %lld", &p, &a) == 2)
    {
        if(a == 0 && p == 0) break;
        c = Mod(a, p, p);
        printf("%lld %lld\n", c, a);
        if(c == a) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}

