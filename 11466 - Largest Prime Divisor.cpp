#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<string>
#include<cmath>
#include<cstdio>
#include<map>
#define maxN 10001000
#define pb push_back

using namespace std;

bool isP[maxN];
vector<int>prime;


void Sieve()
{
    prime.pb(2);
    memset(isP, true, sizeof(isP));
    isP[0] = isP[1] = false;
    for (int i=4; i<maxN; i+=2) isP[i] = false;
    for (int i=3; i*i<maxN; i+=2)
        if (isP[i]) for (int j=i*i; j<maxN; j+=i+i)
            isP[j] = false;

    for (int i=3; i<maxN; i+=2)
        if (isP[i]) prime.pb(i);


}

int main (void)
{
    Sieve();
    int k = prime.size();
    long long n;
    while(scanf("%lld", &n), n)
    {
        if(n < 0) n*= -1;
        int counts = 0, ans;
        for(int i = 0; i<k && prime[i] <= n; i++)
        {
            if(n%prime[i] == 0)
            {
                counts++;
                while(n%prime[i] == 0 && n > 1)
                {
                    n /= prime[i];
                }
                ans = prime[i];
            }
            if(n == 1) break;
        }

        if(n == 1)
        {
            if(counts > 1) printf("%d\n", ans);
            else printf("-1\n");
        }
        else
        {
            if(counts > 0) printf("%lld\n", n);
            else printf("-1\n");
        }
    }

    return 0;
}

