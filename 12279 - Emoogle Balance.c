#include<stdio.h>

int main (void)
{
    int c = 1, n, a, count0, i;
    while(scanf("%d", &n), n)
    {
        count0 = 0;
        for(i=0; i<n; i++)
        {
            scanf("%d", &a);
            if(!a) count0++;
        }
        printf("Case %d: %d\n", c++, n-2*count0);
    }
    return 0;
}
