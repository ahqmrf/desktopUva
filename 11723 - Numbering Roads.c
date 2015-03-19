#include<stdio.h>

int main (void)
{
    int R, N, D, i;
    for(i = 1; scanf("%d%d", &R, &N) && R;)
    {
        printf("Case %d: ", i++);
        D = (R-1)/N;
        printf(D>26 ? "impossible\n" : "%d\n", D);

    }
    return 0;
}

