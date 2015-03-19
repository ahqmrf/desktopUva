#include<stdio.h>

int main (void)
{
    int coins[] = {1, 5, 10, 25, 50};
    long long int DP[10000], i, j;
    DP[0] = 1;
    for(i = 0; i < 5; i++)
    {
        for(j = coins[i]; j < 10000; j++)
            DP[j] += DP[j-coins[i]];
    }

    int amount;
    while(scanf("%d", &amount) != EOF)
        printf("%lld\n", DP[amount]);
    return 0;
}
