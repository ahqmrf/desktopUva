#include<stdio.h>

int main (void)
{
    int n, a[150], i, j, k, count;

    while(scanf("%d", &n) == 1)
    {
        count = 0;
        for(i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        k = n/2;

        for(i = 0; i < n; i++)
        {
            for(j = i + 1; j < n; j++)
            {
                if ( a[i] < a[j] ) count++;
            }
        }

        printf("%d\n", count);
    }
    return 0;
}
