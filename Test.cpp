#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<sstream>

using namespace std;
#define MAX 1000000

bool p[MAX];

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

}

int main (void)
{
    sieveMethod();
    int n;
    while(scanf("%d", &n) == 1 && n)
    {
        if(p[n] == false) printf("%7d %7d\n", n, n);
        else{
            int a = n;
            while(1)
            {
                stringstream ss;
                ss << n;
                string str;
                ss >> str;
                int l = str.length();
                int sum = 0;
                for(int i = 0; i < l; i++)
                {
                    sum += (str[i] - '0');
                }

                if(p[sum] == false)
                {
                    printf("%7d %7d\n", a, sum);
                    break;
                }

                if(sum < 10)
                {
                    printf("%7d    none\n", a);
                    break;
                }

                n = sum;
            }
        }
    }

    return 0;

}
