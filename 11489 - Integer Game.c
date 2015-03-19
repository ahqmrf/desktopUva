#include<stdio.h>
#include<string.h>

int main (void)
{
    int cases, i;
    scanf("%d\n", &cases);
    for(i=1; i<=cases; i++)
    {
        char num[10000], winner[] ={'T', 'S'};
        gets(num);
        int rem[10], has[3];
        memset(rem, 0, sizeof(rem));
        int j, sum = 0, moves = 0;
        for(j=0; num[j]; j++)
        {
            sum += (num[i]-'0');
            rem[num[i]-'0']++;
        }

        has[0] = rem[3] + rem[6] + rem[9];
        has[1] = rem[1] + rem[4] + rem[7];
        has[2] = rem[2] + rem[5] + rem[8];

        if(has[sum%3]) moves = 1, has[sum%3]--;
        if(moves) moves+=has[0];
        if(j-moves==1) moves++;

        printf("Case %d: %c\n", i, winner[moves&1]);

    }
    return 0;
}
