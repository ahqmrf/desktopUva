#include<math.h>
#include<stdio.h>
int main (void)
{
    int num, i;
    while(scanf("%d", &num) == 1)
    {
        if(num == 0) break;
        int f = 0;
        if(num < 0)
        {
            printf("%d = -1", num);
            num *= -1;
            f = 1;
        }
        else printf("%d =", num);
        int sq = sqrt(num);
        for(i = 2; i <= sq; i++)
        {
            if(num % i == 0)
            {
                if(f)printf(" x %d", i);
                else
                {
                    printf(" %d", i);
                    f = 1;
                }
                num /= i;
                i--;
            }

        }

        if(num > 1)
        {
            if(f)printf(" x %d", num);
            else printf(" %d", num);
        }
        printf("\n");
    }
    return 0;
}
