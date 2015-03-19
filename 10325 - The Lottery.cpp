#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

long long GCD(long long a, long long b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;

}


long long LCM (long long a, long long b)
{
    return (a*b)/GCD(a, b);
}

int main (void)
{
    int N, M;

    while(scanf("%d%d", &N, &M)!=EOF)
    {
        long long lcm = 1, a;
        long long nLottery = N;
        vector<long long>nums;
        for(int i = 0; i<M; i++)
        {
            scanf("%lld", &a);


        }



        printf("%lld\n", nLottery);
    }
    return 0;
}
