#include<stdio.h>
int main (void)
{
    int m, n, i;
    long long res;
    while(scanf("%d%d", &n, &m), n || m)
    {

        if(m > n/2) m = n-m;
        res = 1;

        for(i = 0; i < m; i++)
        {
            res *= (n-i);
            res /= (i+1);
        }
        printf("%lld\n", res);

    }
    return 0;
}
