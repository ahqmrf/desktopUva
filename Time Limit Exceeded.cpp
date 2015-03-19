#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

#define LL long long
#define MAX 10001000



bool p[MAX];
LL prime[1000000], k = 0;
void sieveMethod()
{
    prime[0] = 2;
    p[0] = p[1] = true;
    LL i;

    for(i = 4; i < MAX; i += 2)
    {
        p[i] = true;
    }



    for(i = 3; i < MAX; i+=2)
    {
        if(p[i] == true) continue;
        k++;
        prime[k] = i;
        for(int j = i+i; j < MAX; j += i)
        {
            p[j] = true;
        }
    }

}

int main (void)
{
    sieveMethod();
    LL n, i, j, a, c;
    while(scanf("%lld", &n), n)
    {
        if(n < 0) n*= -1;
        c = 0;
        for(i = 0; i <= k && prime[i]<= n && n > 1; i++)
        {
            if(n%prime[i] == 0)
            {
                c++;
                while(n > 1 && n%prime[i] == 0)
                {
                    n /= prime[i];
                }
                a = prime[i];
            }
            if(n == 1) break;
        }

        if(n == 1)
        {
            if(c > 1) printf("%lld\n", a);
            else printf("-1\n");
        }

        else
        {
            if(c > 0) printf("%lld\n", n);
            else printf("-1\n");
        }

    }
    return 0;
}

