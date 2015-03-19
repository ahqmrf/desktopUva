#include<stdio.h>
#include<math.h>

int main (void)
{
    long long int N, sq, ans;
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%lld", &N);
        sq = sqrt(1+8*N);
        ans = (sq-1)/2;
        printf("%lld\n", ans);
    }
    return 0;
}
