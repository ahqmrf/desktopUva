#include<stdio.h>

int main(void)
{
    int count = 2;
    long long int a = 0, b = 1, c;
    long long int male[150], total[150];
    male[0] = 0;
    male[1] = 1;
    total[0] = 1;
    int i = 2;
    while(count!=131)
    {
        c = a + b;
        c++;
        male[i] = c;
        total[i-1] = c;


        a = b;
        b = c;
        i++;
        count++;

    }

    int y;
    while(scanf("%d", &y) == 1 && y != -1)
    {
        printf("%lld %lld\n", male[y], total[y]);
    }
    return 0;
}
