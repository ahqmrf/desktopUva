#include<stdio.h>

int main()
{
    int cycle = 300, fibonacciSum[301];
    fibonacciSum[0] = 0;
    fibonacciSum[1] = 1;
    fibonacciSum[2] = 2;
    int a = 1, b = 1, c, i;
    for(i = 3; i<301; i++)
    {
        c = (a + b) % 100;
        fibonacciSum[i] = fibonacciSum[i-1] + c;
        a = b;
        b = c;
    }
    const int FR = fibonacciSum[300];
    long long int L, U, ans;
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%lld %lld", &L, &U);
        ans = fibonacciSum[U%300] + FR*(U/300) - (fibonacciSum[(L-1)%300] + FR*((L-1)/300));
        printf("%lld\n", ans);
    }

    return 0;
}

