#include<stdio.h>

int main (void)
{
    int coins[] = {1, 5, 10, 25, 50};
    long long int DP[31001], i, j;
    DP[0] = 1;
    for(i = 0; i < 5; i++)
    {
        for(j = coins[i]; j < 31001; j++)
            DP[j] += DP[j-coins[i]];
    }

    int amount;
    while(scanf("%d", &amount) != EOF)
    {
        if(DP[amount] == 1) printf("There is only 1 way to produce %d cents change.\n", amount);
        else printf("There are %lld ways to produce %d cents change.\n", DP[amount], amount);
    }

    return 0;
}

