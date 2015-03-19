#include<stdio.h>
#include<string.h>
#define maxN 1000005

char str[maxN];
int  dP[maxN];


int main(void)
{
    int c = 1;
    while(scanf("%s", str) != EOF)
    {
        int sl = strlen(str);
        dP[0] = 1;
        int i, j, k, q;
        for(k = 1; k < sl; k++)
            dP[k] = (str[k] == str[k-1]) ? dP[k-1]+1 : 1;
        printf("Case %d:\n", c++);
        scanf("%d", &q);
        while(q--)
        {
            scanf("%d%d", &i, &j);
            if(i > j)
            {
                int t = i;
                i = j;
                j = t;
            }

            printf((j-i+1 <= dP[j]) ? "Yes\n" :"No\n");
        }
    }
    return 0;
}
