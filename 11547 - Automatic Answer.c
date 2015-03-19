#include<stdio.h>
int main (void)
{
    int cases;
    scanf("%d", &cases);

    while(cases--)
    {
        long long int n;
        scanf("%lld", &n);
        n *= 567;
        n /= 9;
        n += 7492;
        n *= 235;
        n /= 47;
        n -= 498;
        n = n%100;
        n /= 10;

        if(n < 0) n *= -1;
        printf("%lld\n", n);

    }
    return 0;
}
