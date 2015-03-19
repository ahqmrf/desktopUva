#include<iostream>
#include<cmath>
#include<cstdio>
#define MAXN 1000001

using namespace std;
int *nPrimeFactors;
int *primeFactor;
void sieve()
{
    primeFactor = new int[MAXN];
    for (int i = 2; i * i < MAXN; i++)
        if (primeFactor[i] == 0)
            for (int j = i * i; j < MAXN; j += i)
                primeFactor[j] = i;

    for (int i = 2; i < MAXN; i++)
        if (primeFactor[i] == 0)
            primeFactor[i] = i;

    nPrimeFactors = new int[MAXN];
    nPrimeFactors[0] = nPrimeFactors[1] = 0;
    for (int i = 2; i < MAXN; i++)
        nPrimeFactors[i] = 1 + nPrimeFactors[i / primeFactor[i]];

}

int main ()
{
    sieve();
    for(int i = 2; i < 11; i++)
    {
        cout << nPrimeFactors[i] << endl;
    }
    int n;
    while(scanf("%d", &n), n)
    {
        printf("%d : %d\n",n, nPrimeFactors[n]);
    }
    return 0;
}
