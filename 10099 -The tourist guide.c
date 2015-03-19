#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int max(int a, int b)
{
    return a > b? a : b;
}

int min (int a, int b)
{
    return a < b? a : b;
}

int main (void)
{
    int DP[300][300];
    int nov, noe, sn = 1;
    while(scanf("%d%d", &nov, &noe) && (nov||noe))
    {
        int i, j, k;
        for(i = 1; i <= nov; i++)
        {
            for(j = 1; j <= nov; j++)
                DP[i][j] = -2147483647;
            DP[i][i] = 0;
        }
        int a, b, capa;
        while(noe--)
        {
            scanf("%d%d%d", &a, &b, &capa);
            DP[a][b] = DP[b][a] = capa;
        }

        for(i = 1; i <= nov; i++)
            for(j = 1; j <= nov; j++)
                for(k = 1; k <= nov; k++)
                    DP[j][k] = max(DP[j][k], min(DP[j][i], DP[i][k]));
        int start, end, no;
        scanf("%d%d%d", &start, &end, &no);
        printf("Scenario #%d\n", sn++);
        printf("Minimum Number of Trips = %d\n\n",(int)ceil(no*1.00/(DP[start][end]-1)));
    }
    return 0;
}
