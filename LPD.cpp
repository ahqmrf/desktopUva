#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<string>
#include<cmath>
#include<cstdio>
#include<map>
#define maxN 5000001

#define pb push_back

using namespace std;

bool isP[maxN];
int cDP[maxN];
vector<int>prime;


void Sieve()
{
    memset(isP, true, sizeof(isP));
    isP[0] = isP[1] = false;
    for (int i=4; i<maxN; i+=2) isP[i] = false;
    for (int i=3; i*i<maxN; i+=2)
        if (isP[i]) for (int j=i*i; j<maxN; j+=i+i)
            isP[j] = false;
    prime.pb(2);
    for (int i=3; i<maxN; i+=2)
        if (isP[i]) prime.pb(i);


}

void countDeP()
{
    int c = 0, s = prime.size();
    cDP[0] = cDP[1] = 0;
    for(int i = 2; i<maxN; i++)
    {
        int SOfPF = 0;
        for(int j = 0; j<s && prime[j]<i; j++)
        {
            if(i%prime[j] == 0) SOfPF += prime[j];
        }
        if(isP[SOfPF]) c++;
        cDP[i] = c;
    }
}

int main (void)
{
    Sieve();
    countDeP();
    int a, b;
    while(scanf("%d%d", &a, &b), a)
    {
        printf("%d\n", cDP[b]-cDP[a-1]);
    }
    return 0;
}

