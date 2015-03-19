#include<stdio.h>
int main (void)
{
    int xtra, c=1;
    while(scanf("%d", &xtra), xtra >= 0)
    {
        int i, a, created[13], required[12];
        created[0] = xtra;
        for(i=1; i<=12; i++)
        {
            scanf("%d", &created[i]);
        }

        for(i=0; i<12; i++)
        {
            scanf("%d", &required[i]);
        }

        printf("Case %d:\n", c++);
        for(i=0;i<12;i++)
        {
            if(created[i]>=required[i])
            {
                created[i+1] += (created[i]-required[i]);
                printf("No problem! :D\n");
            }
            else
            {
                created[i+1] += created[i];
                printf("No problem. :(\n");
            }
        }
    }
    return 0;
}
