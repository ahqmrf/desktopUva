#include<stdio.h>

int remainder(int n, int k)
{
    return n%k;
}

int division(int n, int k)
{
    return n/k;
}


int main(void)
{
    int n, m, k, t;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d%d%d", &n, &m, &k);
        int N = n+m;
        int count = 0;

        while(1)
        {
            int d = division(N, k);
            if(d == 0) break;
            count += d;
            N = remainder(N,k) + d;
        }

        printf("%d\n", count);
    }

    return 0;
}


