#include<stdio.h>

int main (void)
{
    int N;
    while(scanf("%d", &N), N)
    {
        if(N == 1)
        {
            printf("Discarded cards:\n");
            printf("Remaining card: 1\n");
        }

        else if(N == 2)
        {
            printf("Discarded cards: 1\n");
            printf("Remaining card: 2\n");
        }

        else
        {
            int a[N+N], discarded[N-1], last = N - 1, i, count = N-1, j = 0;
            for(i = 0; i < N; i++) a[i] = i + 1;
            i = 0;
            while(count--)
            {
                last++;
                discarded[j] = a[i];
                a[last] = a[i+1];
                j++;
                i += 2;

            }
            int f = 0;

            printf("Discarded cards:");
            for(i = 0; i < j; i++)
            {
                if(f == 1) printf(",");
                f = 1;
                printf(" %d", discarded[i]);
            }
            printf("\nRemaining card: %d\n", a[last]);

        }
    }
    return 0;
}
