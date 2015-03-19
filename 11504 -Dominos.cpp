#include<bits/stdc++.h>
#define maxN 100010

using namespace std;

vector<int>adj[maxN];
bool visited[maxN];
vector<int> topsort;

void dfs(int u)
{
    visited[u] = true;
    for(int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(!visited[v]) dfs(v);
    }
    topsort.push_back(u);
}

int connected_component(int n)
{
    memset(visited, false, sizeof(visited));
    for(int i=1; i<=n; i++)
    {
        if(!visited[i]) dfs(i);
    }

    memset(visited, false, sizeof(visited));
    int counts = 0;
    for(int i=topsort.size()-1; i>=0; i--)
    {
        if(!visited[topsort[i]])
        {
            counts++;
            dfs(topsort[i]);
        }
    }
    return counts;
}

int main()
{
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        while(m--)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
        }

        cout << connected_component(n) << endl;
        for(int i = 0; i<=n; i++) adj[i].clear();
        topsort.clear();
    }
    return 0;
}
