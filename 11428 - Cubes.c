#include<stdio.h>
int main()
{
    int N;
    while(scanf("%d", &N), N)
    {
        int i, j, found = 0;
        for(i = 1; i<60; i++)
        {
            for(j = 0; j <= i; j++)
            {
                if(N == i*i*i - j*j*j)
                {
                    found = 1;
                    break;
                }
            }
            if(found) break;
        }
        if(found) printf("%d %d\n", i, j);
        else printf("No solution\n");
    }
    return 0;
}
