#include<stdio.h>
int main (void)
{
    int m, n;
    while(scanf("%d%d", &n, &m), n || m)
    {
        if(m == 0) printf("1\n");
        else{
            if(m > n/2) m = n-m;
            long long int res = 1;
            int i;
            for(i = 0; i < m; i++)
            {
                res *= (n-i);
                res /= (i+1);
            }
            printf("%lld\n", res);
        }
    }
    return 0;
}
