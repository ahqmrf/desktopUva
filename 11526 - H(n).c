#include<algorithm>
#include<math.h>
#include<stdio.h>

using namespace std;
long long H(int n)
{
    if(n == 0) return 0;
    int lim = (int)floor(sqrt(n)), i;
    long long ans = 0;
    if(lim*lim == n)
    {
        ans+=(n/lim);
        --lim;
    }

    for(i=1;i<=lim;i++)
    {
        ans += (n/i);
        ans +=max(0, n/i-lim);
    }

    return ans;
}

int main (void)
{
    int cases, num;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d", &num);
        printf("%lld\n", H(num));
    }
    return 0;
}
