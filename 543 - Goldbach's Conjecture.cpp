#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdio>

using namespace std;
#define MAX 20000000

bool p[MAX];
vector<long long int>primes;

void sieveMethod()
{
    p[0] = p[1] = true;

    for(int i = 4; i < MAX; i += 2)
    {
        p[i] = true;
    }

    int sq = sqrt(MAX);

    for(int i = 3; i < sq; i+=2)
    {
        if(p[i] == true) continue;
        for(int j = i+i; j < MAX; j += i)
        {
            p[j] = true;
        }
    }

    for(int i = 1; i < MAX; ++i)
    {
        if(p[i] == false) primes.push_back(i);
    }

}

int main (void)
{
    sieveMethod();

    long long int n;
    while(scanf("%lld", &n) == 1 && n)
    {
        bool flag = true;
        for(int i = 0; ; ++i)
        {
            int a = primes[i];
            int b = n - a;
            if(p[b] == false){
                cout << n << " = " << a << " + " << b << endl;
                flag = false;
                break;
            }
        }

        if(flag) cout << "Goldbach's conjecture is wrong." << endl;
    }



    return 0;
}

