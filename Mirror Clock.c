#include<stdio.h>

int main (void)
{
    int hour, minute, cases, h, m;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d:%d", &hour, &minute);
        if(minute == 0)
        {
            if(hour == 12) h = 12;
            else h = 12 - hour;

            m = 0;
        }

        else
        {
            if(hour == 12)
            {
                h = 11;
            }

            else
            {
                h = 12 - hour;
                h--;
                if(h == 0) h = 12;
            }
            m = 60 - minute;
        }

        if(h < 10) printf("0%d:", h);
        else printf("%d:", h);
        if(m < 10) printf("0%0d", m);
        else printf("%d", m);
        printf("\n");

    }

    return 0;
}
