#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdio>
#define MAX 200000000


using namespace std;

bool p[MAX];


void sieveMethod()
{
    p[0] = p[1] = true;

    for(int i = 4; i < MAX; i += 2)
    {
        p[i] = true;
    }

    int sq = sqrt(MAX);

    for(int i = 3; i <= sq; i+=2)
    {
        if(p[i] == true) continue;
        for(int j = i*i; j <= MAX; j += 2*i)
        {
            p[j] = true;
        }
    }


}

int main (void)
{
    sieveMethod();
    vector<int>primes;
    for(int i = 2; i < MAX; i++)
    {
        if(p[i] == false) primes.push_back(i);
    }

    int s = primes.size();
    cout << s << endl;
    int n, m, cases, c = 1;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d %d", &m, &n);
        printf("Case %d:\n", c++);
        if((m > n && p[m] == false) || n == 0)  printf("Impossible to divide\n");
        else if(m == n && p[m] == false) printf("1\n");
        else
        {
            int P;
            if(p[m] == false) P = m;
            else
            {
                for(int i = 0; i < s && m >= primes[i]; i++)
                {
                    if(m % primes[i] == 0){
                        P = primes[i];
                        break;
                    }
                }
            }


            if(P > n)  printf("Impossible to divide\n");
            else if(P == n) printf("1\n");
            else
            {
                int cnt = 0;
                int M  = P, j;
                while(m%P == 0 && m > 0){
                    cnt++;
                    m/= P;
                }

                int t = 1111111, d = 0;
                for(j = 1.0; ; j+=1.0)
                {
                    if(t == 0) break;
                    t = n/M;
                    d = d+ t;
                    M*=P;
                }
                if(cnt > 0) d/= cnt;
                printf("%d\n", d);
            }
        }
    }

    return 0;

}



