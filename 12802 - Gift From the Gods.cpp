#include<bits/stdc++.h>
#define maxN 1000001

using namespace std;

bool prime[maxN];
bool palprime[maxN];

void sieve()
{
    memset(prime, true, sizeof prime);
    memset(palprime, false, sizeof palprime);
    prime[0] = false;

    for(int i = 4; i<maxN; i+=2) prime[i] = false;
    for(int i = 3; i*i<maxN; i+=2)
        if(prime[i])
            for(int j=i*i; j<maxN; j+= 2*i)
                prime[j] = false;

    for(int i = 1; i<maxN; i++)
    {
        if(prime[i])
        {
            stringstream ss;
            string s;
            ss << i;
            ss >> s;
            reverse(s.begin(), s.end());
            int num = atoi(s.c_str());
            if(num == i) palprime[i] = true;
        }
    }
}

int main()
{
    sieve();
    int num;
    while(scanf("%d", &num))
    {
        printf("%d\n", num*2);
        if(palprime[num]) break;
    }
    return 0;
}

