#include<stdio.h>

int main (void)
{
    int coins[] = { 2000, 1000, 400, 200, 100 , 40, 20, 10, 4, 2 ,1 };
    long long int DP[30001], i, j;
    DP[0] = 1;
    for(i = 0; i < 11; i++)
    {
        for(j = coins[i]; j <= 7500; j++)
            DP[j] += DP[j-coins[i]];
    }

    double amount;
    while(scanf("%lf", &amount) == 1 && amount != 0.0)
    {
        long long int ret = amount * 20;
        long long int r = DP[ret];
        printf("%6.2lf%17lld\n", amount, r);
    } 
    return 0;
}
