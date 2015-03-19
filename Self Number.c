#include<stdio.h>
int main (void)
{
    long long int i;
    for(i = 1; i <= 9; i++)
    {
        printf("%lld\n", i);
    }

    for(i = 20; i <= 1000000; i+=11)
    {
        printf("%lld\n", i);
    }
    return 0;
}
