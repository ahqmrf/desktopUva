#include<map>
#include<vector>
#include<cstdio>
#include<iostream>
using namespace std;
int main (void)
{
    int n, q;
    while(scanf("%d%d", &n, &q) != EOF)
    {
        map < int, vector<int> > M;
        for(int i = 1; i <= n; i++)
        {
            int a;
            scanf("%d", &a);
            M[a].push_back(i);
        }

        while(q--)
        {
            int a, k;
            scanf("%d%d", &k, &a);
            if(M.find(a) == M.end()) printf("%d\n", 0);
            else {
                if(k > M[a].size()) printf("%d\n", 0);
                else printf("%d\n", M[a][k-1]);
            }
        }


    }

    return 0;
}

