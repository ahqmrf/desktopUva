#include<bits/stdc++.h>

using namespace std;

int st[20];

void combination(int n, int h, int term, int in)
{
    if(term >= h)
    {
        for(int i=1; i<=n; i++)
            printf("%d",st[i]);
        puts("");
        return;
    }

    for(int i=in; i<=n; i++)
    {
        if(st[i]==1)
        {
            st[i] = 0;
            combination(n, h, term+1, i+1);
            st[i] = 1;
        }
    }
    return;
}

int main()
{
    int cases, n, h;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d%d", &n, &h);
        for(int i=1; i<20; i++)
            st[i]=1;
        combination(n, n-h, 0, 1);
        if(cases) puts("");
    }
    return 0;
}
