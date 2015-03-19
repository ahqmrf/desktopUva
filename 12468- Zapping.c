#include<stdio.h>

int main (void)
{
    int a, b;
    while(scanf("%d%d", &a, &b) == 2 && !(a == -1 && b == -1))
    {
        if(a == b) printf("0\n");
        else if(a < b)
        {
            int count = b - a;
            int count2 = a + 100 - b;
            if(count <= count2) printf("%d\n", count);
            else printf("%d\n", count2);
        }
        else
        {
            int count = a - b;
            int count2 = b + 100 - a;
            if(count <= count2) printf("%d\n", count);
            else printf("%d\n", count2);
        }
    }
    return 0;
}
