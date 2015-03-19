#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
long long int k;
void PrintCombination(int coins[], int counts[], int startIndex, int amount)
{
    if(startIndex >= 5) // we have processed all coins
    {
        k++;
        return;
    }
    if(startIndex == 4)
    {
        if(amount%coins[startIndex] == 0)
        {
            counts[startIndex] = amount/coins[startIndex];
            PrintCombination(coins, counts, startIndex+1, 0);
        }
    }
    else
    {
        for(int i = 0; i <= amount/coins[startIndex]; i++)
        {
            counts[startIndex] = i;
            PrintCombination(coins, counts, startIndex+1, amount - coins[startIndex]*i);
        }
    }
}

int main (void)
{
    int amount;
    while(scanf("%d", &amount))
    {
        int coins[] = {50, 25, 10, 5, 1};
        int counts[5];
        k = 0;
        PrintCombination(coins, counts, 0, amount);
        printf("%lld\n", k);
    }
}
