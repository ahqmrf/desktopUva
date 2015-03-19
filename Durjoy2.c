#include<stdio.h>

int main (void)
{
    int min = 2147483647, a;

    while(scanf("%d", &a) == 1, a)
    {
        if(a < min) min = a;
    }

    printf("%d\n", min);
    return 0;
}
