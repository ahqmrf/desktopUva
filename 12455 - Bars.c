#include<stdio.h>
int main()
{
    int cases, n, p, pl, i;
    scanf("%d", &cases);
    while(cases--) {
        scanf("%d %d", &n, &p);
        int dp[1005] = {};
        dp[0] = 1;
        while(p--) {
            scanf("%d", &pl);
            for(i = n - pl; i >= 0; i--)
                if(dp[i] && !dp[i+pl])
                    dp[i+pl] = 1;
        }
        printf((dp[n]) ? "YES\n" : "NO\n");
    }
    return 0;
}
