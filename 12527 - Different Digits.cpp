#include<map>
#include<cstdio>
#include<iostream>

using namespace std;
#define maxN 5001
bool haha[maxN+1];
int counts[maxN];
void solve()
{
    int p = 0;
    haha[0] = 0;
    for(int i=1; i<maxN; i++)
    {
        map<int, bool> M;
        int N = i;
        bool flag = true;
        while(N)
        {
            int rem = N%10;
            N/=10;
            if(M.find(rem)!= M.end())
            {
                flag = false;
                break;
            }
            else M[rem] = true;
        }
        if(flag)
        {
            p++;
            haha[i] = true;
        }

        counts[i] = p;
    }
}

int main (void)
{
    solve();
    int N, M;
    while(scanf("%d%d", &N, &M)!=EOF)
    {
        int c = 0;
        if(haha[N]) c++;
        c+= counts[M] - counts[N];
        printf("%d\n", c);
    }
}
