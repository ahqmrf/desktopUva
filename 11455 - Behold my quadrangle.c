#include<stdio.h>

int main (void)
{
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if(a+b+c <= d || a+b+d <= c || a+c+d <= b || b+c+d <= a)
        {
            printf("banana\n");
        }
        else
        {
            if(a == b && b == c && c == d)
            {
                printf("square\n");
            }

            else if((a == b && c == d) || (a == c && b == d) || (a == d && b == c))
            {
                printf("rectangle\n");
            }

            else printf("quadrangle\n");
        }
    }
    return 0;
}
