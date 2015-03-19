#include<cstdio>
using namespace std;
int main (void)
{
    long long N, M;
    while(scanf("%lld%lld", &N, &M)==2)
    {
        if(M==0) printf("1\n");
        else
        {
            long long ans=1, c=N-M+1;;
            for(long long i=N; i>=c; i--)
            {
                ans *= i;
                while(ans%10==0) ans/=10;
                ans %= 1000000000;
            }
            printf("%lld\n", ans%10);
        }
    }
    return 0;
}

