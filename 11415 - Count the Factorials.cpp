#include<bits/stdc++.h>
#define maxN 3000000

using namespace std;

bool is_prime[maxN];
int factors[maxN];


void sieve()
{
    is_prime[0] = is_prime[1] = true;

    for(int i=2; i<maxN; i++)
    {
        if(!is_prime[i])
        {
            factors[i] = 1;
            for(int j=i<<1; j<maxN; j+=i)
            {
                is_prime[j] = true;
                for(int k=j; k%i==0; k/=i)
                {
                    factors[j]++;
                }

            }
        }
    }
}

int main ()
{
    sieve();
    for(int i=2; i<maxN; i++)
    {
        factors[i] += factors[i-1];
    }
    int c, n;
    scanf("%d", &c);
    while(c--)
    {
        scanf("%d", &n);
        printf("%d\n", (int)(upper_bound(factors, factors+maxN, n) - factors));
    }
    return 0;
}

