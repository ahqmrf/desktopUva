#include<bits/stdc++.h>

using namespace std;
vector<int> a[1000001];
int main()
{
    int n, q;
    while(scanf("%d%d", &n, &q) == 2)
    {
        int num;
        set<int> hehe;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &num);
            a[num].push_back(i);
            hehe.insert(num);
        }

        int k;
        while(q--)
        {
            scanf("%d%d", &k, &num);
            if(a[num].size() < k) puts("0");
            else printf("%d\n", a[num][k-1]);
        }
        set<int> :: const_iterator it;
        for(it = hehe.begin(); it!=hehe.end(); it++)
            a[*it].clear();
    }
    return 0;
}
