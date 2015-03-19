#include <iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include <cstdlib>
#define MAX 1000000
using namespace std;
char is_prime[MAX];
int prime_series[100000000], limit;
int N[1000000], mu[1000000];
void sieve()
{
    register int k, i=2, j, x;
    memset(is_prime, 1 , MAX);
    x=sqrt(MAX);
    ///for even number
    for(j=i*i ; j<=MAX; j+=i)
        is_prime[j]=0;
    for(i=3; i<=x; )
    {
        for(j=i*i; j<=MAX; j+=(i*2))
            is_prime[j]=0;
        i++;
        while(is_prime[i]!=1)
            i++;
    }
    ///saving the prime number
    for(i=2, k=0; i<=MAX ; i++)
    {
        if(is_prime[i]==1)
        {
            prime_series[k++]=i;
        }
    }
    limit=k;             ///for saving the last index
}

void factor (int num)
{
    int j, k, x, flag;
    register int i, now, cnt;
    //x=sqrt(num)
    now=num;
    for(i=0, flag=1, cnt=0; prime_series[i]*prime_series[i]<=now; i++)
    {
        if(now%prime_series[i]==0)
        {
            now/=prime_series[i];
            while(now%prime_series[i]==0)
            {
                flag=0;
                break;
                now/=prime_series[i];
            }
            if(flag==0)
            {
                mu[num]=0;
                break;
            }
            cnt++;
        }
    }
    if(now>1 && flag==1)
        cnt++;
    if(cnt%2==0 && flag==1)
        mu[num]=1;
    else if(cnt%2==1 && flag==1)
        mu[num]=-1;

    return;
}
int main()
{
    sieve();
    register int i, j, k;
    int num;
    N[1]  =1;
    mu[1] =1;
    for(i=2; i<=1000000; i++)
    {
        if(is_prime[i]==1)
            mu[i]=-1;
        else
        {
            factor(i);
        }
        N[i]=N[i-1]+mu[i];
    }

    while(scanf("%d", &num)!=EOF)
    {
        if(num==0)
            break;
        printf("%8d%8d%8d\n", num, mu[num], N[num]);
    }
}
