#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

#define Maximum 31623

int isPrimeWithinMax[Maximum];
int primeNumbers[4000];
int i, j, k ;


void sieve()
{
    primeNumbers[0] = 2;
    k = 1;
    memset(isPrimeWithinMax, 0, sizeof(isPrimeWithinMax));
    isPrimeWithinMax[0] = isPrimeWithinMax[1] = 1;
    for(i = 4; i < Maximum; i += 2) isPrimeWithinMax[i] = 1;
    for(i = 3; i*i <Maximum; i+=2)
    {
        if(isPrimeWithinMax[i] == 0)
        {
            for(j = i*i; j < Maximum; j += i+i) isPrimeWithinMax[j] = 1;
        }
    }

    for(i = 3; i < Maximum; i+=2)
    {
        if(isPrimeWithinMax[i] == 0)
        {
            primeNumbers[k] = i;
            k++;
        }
    }
}

int isPrime(int num)
{
    if(num < Maximum) return isPrimeWithinMax[num];
    int sroot = (int) sqrt(num);
    for(i = 0; i < k && primeNumbers[i] <= num; i++)
        if(num % primeNumbers[i] == 0) return 1;
    return 0;
}

int Mod(int x, int n, int M)
{
    if(n == 0) return 1;
    else if(n%2 == 0)
    {
        int y = Mod(x, n/2, M);
        return (y*y) % M;
    }

    else return ((x%M) * Mod(x, n-1, M)) % M;
}

int main (void)
{
    sieve();
    int a, p;

    while(scanf("%d %d", &p, &a) && (a || p))
    {
        if(isPrime(p) == 0 || Mod(a, p, p) != a) printf("no\n");
        else printf("yes\n");
    }
    return 0;
}
