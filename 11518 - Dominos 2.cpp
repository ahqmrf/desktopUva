#include<bits/stdc++.h>
#define maxN 10010
#define SET(a, b) memset(a, b, sizeof(a))

using namespace std;

vector<int> adj[maxN];
bool visited[maxN];
int total;

void dfs(int u)
{
    if(!visited[u]) total++;
    visited[u] = true;
    for(int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(!visited[v]) dfs(v);
    }
}

int main ()
{
    int cases, n, m, l;
    scanf("%d", &cases);
    while(cases--)
    {
        SET(visited, false);
        total = 0;
        scanf("%d%d%d", &n, &m, &l);
        while(m--)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            adj[x].push_back(y);
        }

        int domino;
        while(l--)
        {
            scanf("%d", &domino);
            dfs(domino);
        }
        printf("%d\n", total);
        for(int i = 0; i<=n; i++) adj[i].clear();
    }
    return 0;
}
