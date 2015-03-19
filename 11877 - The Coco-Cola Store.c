#include<stdio.h>

int main (void)
{
    int n;
    while(scanf("%d", &n), n)
    {
        if(n == 1 || n==2) printf("0\n");
        else printf("%d\n", n/2);
    }
    return 0;
}
