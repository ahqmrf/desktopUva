#include<stdio.h>

int max(int a, int b)
{
    return (a >= b) ? a : b;
}

int main (void)
{
    int cases, c;
    scanf("%d", &cases);
    for(c = 1; c <= cases; c++)
    {
        int mx = -2147483647, n, a;
        scanf("%d", &n);
        while(n--)
        {
            scanf("%d", &a);
            mx = max(mx, a);
        }
        printf("Case %d: %d\n", c, mx);
    }
    return 0;
}
