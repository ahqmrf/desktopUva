#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>

using namespace std;
#define MAX 10000002

bool prime[MAX];

void sieveMethod()
{
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;

    for(int i = 4; i < MAX; i += 2) prime[i] = false;
    int sq = sqrt(MAX);
    for(int i = 3; i < sq; i+=2)
        if(prime[i])
            for(int j = i*i; j < MAX; j += 2*i) prime[j] = false;

}

int main (void)
{
    sieveMethod();
    for(int i = 1; i < 100; ++i)
    {
        if(prime[i] ) cout << i << endl;
    }
    return 0;
}
