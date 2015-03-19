#include<stdio.h>

int main ()
{
    int c, x, y, z, ans;
    scanf("%d", &c);
    while(c--)
    {
        scanf("%d%d%d", &x, &y, &z);
        ans = z*(x+(x-y))/(x+y);
        if(ans < 0) printf("0\n");
        else printf("%d\n", ans);
    }
    return 0;
}
