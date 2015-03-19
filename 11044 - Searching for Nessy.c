#include<stdio.h>

int main (void)
{
    int c, n, m;
    scanf("%d", &c);
    while(c--)
    {
        scanf("%d%d", &n, &m);
        printf("%d\n", (n/3)*(m/3));
    }
    return 0;
}
