#include<stdio.h>
#include<string.h>


int main (void)
{
    int n;


    while(scanf("%d", &n) == 1 && n){
        int space = 1, i, j;
        int c[n+1];
        memset(c, 0, sizeof(c));

        for(i = 0; i < n; ++i)
        {
            int a;

            scanf("%d", &a);

            c[a]++;
        }

        for(i= 1; i <= n; ++i)
        {
            for(j = 0; j < c[i]; ++j)
            {
                if(space == 2) printf(" ");
                printf("%d", i);
                space = 2;
            }
        }
        printf("\n");


    }
    return 0;
}
