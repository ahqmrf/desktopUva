#include<stdio.h>

int main (void)
{
    int cases, case_no = 0;
    scanf("%d", &cases);

    while(cases--)
    {
        int n, k, p, player;
        scanf("%d%d%d", &n, &k, &p);

        player = k + p;

        while(player > n) player = player-n;

        printf("Case %d: %d\n", ++case_no, player);
    }
    return 0;
}
