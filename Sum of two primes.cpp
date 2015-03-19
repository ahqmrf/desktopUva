#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<string>
#include<cmath>
#include<cstdio>
#include<map>
#define maxN 100000001
#define pb push_back

using namespace std;

bool isP[maxN];
vector<int>prime;
int n, x;

void Sieve() {
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

bool Check() {
    if (n%2) {
        x = 2;
        return isP[n-x];
    }
    int p = int(upper_bound(prime.begin(), prime.end(), n/2) - prime.begin());
    for (; p>=0; p--)
        if (isP[n-prime[p]]) {
            if (prime[p] == n - prime[p]) continue;
            x = min(prime[p], n-prime[p]);
            return true;
        }
    return false;
}

void main() {

    Sieve();
    while (scanf("%d", &n)!=EOF) {
        if (Check()) printf("%d is the sum of %d and %d.\n", n, x, n-x);
        else printf("%d is not the sum of two primes!\n", n);
    }
}
