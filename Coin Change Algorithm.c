#include<stdio.h>
int i;
int Count(int Sum,int coins[], int n, int index,int curSum)
{
    int count=0;

    if (index >= n)
        return 0;

    int sumNow = curSum + coins[index];
    if (sumNow > Sum)
        return 0;
    if (sumNow == Sum)
        return 1;

    for (i = index+1; i < n;i++)
        count+=Count(Sum,coins, n, i,sumNow);

    return count;
}


int main (void)
{
    int coins[]={1,4, 6, 2, 3, 5};
    int count=0;
    int n = 6;

    for (i=0;i<n;i++)
    {
        count=count+Count(9,coins, n, i,0);
    }

    printf("%d\n", count);

    return 0;
}
