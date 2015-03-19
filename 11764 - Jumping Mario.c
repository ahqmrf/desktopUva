#include<stdio.h>

int main (void)
{
    int cases, case_no = 0;
    scanf("%d", &cases);
    while(cases--)
    {
        int n, i, t, high = 0, low = 0;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            int h;
            scanf("%d", &h);
            if(i == 0);
            else
            {
                if(h > t) high++;
                else if(h < t) low++;
            }
            t = h;
        }

        printf("Case %d: %d %d\n", ++case_no, high, low);
    }
    return 0;
}
