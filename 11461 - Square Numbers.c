#include<stdio.h>
#include<math.h>

int main (void)
{
    int a, b;
    while(scanf("%d%d", &a, &b) == 2 && (a && b))
    {
        int count = (int)sqrt(b) - (int)sqrt(a);
        if((int)sqrt(a)*(int)sqrt(a) == a) count++;

        printf("%d\n", count);

    }

    return 0;

}
