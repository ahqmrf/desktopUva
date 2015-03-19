#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;

long long int gcd(long long int a, long long int b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}

int main (void)
{
    long long int GCD[200001];
    for(int N=2; N<200001; N++)
    {

        long long int G=0;
        for(int i=1;i<N;i++)
            for(int j=i+1;j<=N;j++)
            {
                G+=gcd(i,j);
            }

        GCD[N] = G;
    }

    cout << GCD[200000] << endl;
    return 0;
}
