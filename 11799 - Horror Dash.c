#include<stdio.h>
int main ()
{
    int i, cases, a, max, n;
    scanf("%d", &cases);
    for(i = 1; i <= cases; i++)
    {
        max = 0;
        scanf("%d", &n);
        while(n--)
        {
            scanf("%d", &a);
            if(a >= max) max = a;
        }
        printf("Case %d: %d\n", i, max);
    }
    return 0;
}
