#include<stdio.h>
int main (void)
{
    int a, b, c, d, L;
    while(scanf("%d%d%d%d%d", &a, &b, &c, &d, &L) == 5)
    {
        if(a == 0 && (b == 0 && (c == 0 && (d == 0 && L == 0)))) break;
        int count = 0, i;
        for(i = 0; i <= L; i++)
        {
            long long int f = a*i*i  + b*i + c;
            if(f % d == 0) count++;
        }

        printf("%d\n", count);
    }
    return 0;
}
