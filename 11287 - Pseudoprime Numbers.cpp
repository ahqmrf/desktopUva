#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdio>
#define maxN 31623
#define pb push_back

using namespace std;

bool p[maxN];
vector<int>prime;

void Sieve() {
    memset(p, true, sizeof(p));
    p[0] = p[1] = false;
    for (int i=4; i<maxN; i+=2) p[i] = false;
    for (int i=3; i*i<maxN; i+=2)
        if (p[i]) for (int j=i*i; j<maxN; j+=i+i)
            p[j] = false;
    prime.pb(2);
    for (int i=3; i<maxN; i+=2)
        if (p[i]) prime.pb(i);
}


bool isPrime(int num)
{
    if(num < maxN) return p[num];
    int rt = (int) sqrt(num);
    for(int i = 0; i< prime.size() && prime[i] <= rt; i++)
    {
        if(num % prime[i] == 0) return false;
    }
    return true;

}

long long Mod(long long x, int n, int M)
{
    if(n == 0) return 1;
    else if(n%2 == 0)
    {
        long long y = Mod(x, n/2, M);
        return (y*y) % M;
    }

    else return ((x%M) * Mod(x, n-1, M)) % M;
}

int main (void)
{
    Sieve();

    int a, k;
    while(scanf("%d %d", &k, &a) && (k||a))
    {
        bool f;
        if (isPrime(k)) f = false;
        else f = (Mod(a, k, k)==a);
        if (f) puts("yes");
        else puts("no");
    }
    return 0;
}

