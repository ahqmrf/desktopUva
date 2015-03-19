#include<stdio.h>

int main (void)
{
    int gcd, lcm, cases;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d%d", &gcd, &lcm);
        printf((lcm%gcd)? "-1\n" : "%d %d\n", gcd, lcm);
    }
    return 0;
}
