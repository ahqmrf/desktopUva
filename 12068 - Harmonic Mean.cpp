#include<cstdio>

using namespace std;

long long LCM (long long a, long long b, long long lcm)
{
    if(lcm % a == 0 && lcm%b == 0) return lcm;
    else lcm++;
    return LCM(a, b, lcm);
}

long long GCD(long long a, long long b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;

}

int main (void)
{
    int N, a[100000], cases;
    scanf("%d", &cases);
    for(int c = 1; c<=cases; c++)
    {
        scanf("%d", &N);
        long long lcm = 1;
        for(int i = 0; i<N; i++)
        {
            scanf("%d", &a[i]);
            lcm = (lcm / GCD(lcm, a[i])) * a[i];
        }


        long long sum = 0;
        for(int i = 0; i<N; i++)
        {
            sum += (lcm/a[i]);
        }
        lcm *= N;
        long long gcd = GCD(lcm, sum);
        sum /= gcd;
        lcm /= gcd;

        printf("Case %d: %lld/%lld\n",c, lcm, sum);
    }
    return 0;
}

