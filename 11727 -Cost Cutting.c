#include<stdio.h>
int main (void)
{
    int cases, case_no = 0;
    scanf("%d", &cases);
    while(cases--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);

        printf("Case %d: ", ++case_no);
        if(a >= b && a <= c) printf("%d\n", a);
        else if(a >= c && a <= b) printf("%d\n", a);
        else if(b >= c && b <= a) printf("%d\n", b);
        else if(b >= a && b <= c) printf("%d\n", b);
        else if(c >= a && c <= b) printf("%d\n", c);
        else if(c >= b && c <= a) printf("%d\n", c);
    }


    return 0;
}
