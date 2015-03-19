#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cmath>

#define mx 1048576

using namespace std;

bool notPrime[mx+1], notCompPrime[mx+1];

void sieve()
{
    notPrime[0] = notPrime[1] = true;
    int lim = sqrt(mx);
    for(int i = 2; i<=lim; i++)
    {
        if(!notPrime[i])
        {
            for(int j=i*i; j<=mx; j+=i)
            {
                notPrime[j] = true;
            }
        }
    }

    notCompPrime[0] = notCompPrime[1] = notCompPrime[2] = notCompPrime[3] = true;

    for(int i=4; i<=mx; i++)
    {
        if(notPrime[i] && !notCompPrime[i])
        {
            for(int j=i*2; j<=mx; j+=i)
            {
                notCompPrime[j] = true;
            }
        }
    }
}


int main (void)
{
    sieve();
    int K, num, ncp;
    while(scanf("%d", &K) != EOF)
    {
        ncp = 0;
        while(K--)
        {
            scanf("%d", &num);
            if(notPrime[num] && !notCompPrime[num]) ncp++;
        }
        printf("%d\n", ncp);
    }
    return 0;
}
