#include<stdio.h>
#include<string.h>
#include<math.h>

int main (void)
{
    int cases;
    char a[10001];
    scanf("%d", &cases);
    getchar();
    while(cases--)
    {
        gets(a);
        int len = strlen(a);
        double sq = sqrt(len);
        int sq2 = sqrt(len);
        if(sq2 == sq)
        {
            int i, j;
            for(i = 0; i < sq2; i++)
            {
                for(j = i; j < len; j+=sq2)
                {
                    printf("%c", a[j]);
                }
            }

            printf("\n");
        }

        else printf("INVALID\n");
    }
    return 0;
}
