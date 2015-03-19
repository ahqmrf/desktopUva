#include<stdio.h>

int main (void)
{
    int cases, case_no = 0, a, b, c;
    scanf("%d", &cases);
    while(cases-- && scanf("%d%d%d", &a, &b, &c) == 3)
    {
        printf("Case %d: ", ++case_no);
        if(a > 20 || b > 20 || c > 20) printf("bad\n");
        else printf("good\n");
    }

    return 0;
}


