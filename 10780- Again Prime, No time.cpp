#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>

#define maxN 5001
#define INF 2000000000

using namespace std;
vector<int>prime;
bool isPrime[maxN];

void Sieve()
{
   memset(isPrime, true, maxN);
   isPrime[0] = isPrime[1] = false;
   for (int i=2, lm=(int)sqrt(maxN); i<=lm; i++)
      if (isPrime[i]) for (int j=i*i; j<maxN; j+=i)
         isPrime[j] = false;
   for(int i = 2; i<maxN; i++)
      if (isPrime[i]) prime.push_back(i);
}
int findPower(int num, int div)
{
    int kount = 0, c = div;
    while(c <= num)
    {
        kount+=(num/c);
        c*=div;
    }
    return kount;
}

int solve(int n, int m)
{
    int ans = INF;
    int c = 0;
    while(m>1)
    {
        if(m%prime[c] == 0)
        {
            int powerM = 0;
            while(m%prime[c] == 0)
            {
                powerM++;
                m/=prime[c];
            }
            int powerN = findPower(n, prime[c]);
            if(powerN < powerM) return -1;
            ans = min(ans, powerN/powerM);
        }
        c++;
    }
    if(ans == INF) return -1;
    return ans;
}

int main (void)
{
    Sieve();
    int n, m, cases;
    scanf("%d", &cases);
    for(int i=1; i<=cases; i++)
    {
        scanf("%d%d", &m, &n);
        int ans = solve(n, m);
        printf("Case %d:\n", i);
        if(ans >0) printf("%d\n", ans);
        else printf("Impossible to divide\n");
    }
    return 0;
}
