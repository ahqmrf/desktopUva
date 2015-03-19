#include<bits/stdc++.h>
#define maxN 10000
#define ms(a, value) memset(a, value, sizeof(a))
#define clrv(a) a.clear()

using namespace std;

bool visited[maxN];
vector< pair<int, int> > bridge;
pair<int, int> link;
int dis[maxN], low[maxN], parent[maxN], t;
vector<int> adj[maxN];

void findBridge(int u)
{
    low[u] = dis[u] = ++t;
    visited[u] = true;
    for(int i=0;i<adj[u].size();i++)
    {
        int v = adj[u][i];
        if(!visited[v])
        {
            parent[v] = u;
            findBridge(v);
            low[u] = min(low[u], low[v]);
            if(low[v]>dis[u])
            {
                link.first = u, link.second = v;
                if(u > v) swap(link.first, link.second);
                bridge.push_back(link);
            }
        }
        else if(parent[u] != v) low[u] = min(low[u], dis[v]);
    }
    return;
}

int main ()
{
    int nos;
    while(scanf("%d", &nos)!=EOF)
    {
        ms(visited, false);
        for(int i = 0; i < maxN; i++) clrv(adj[i]);

        for(int i = 0; i < nos; i++)
        {
            int u, v, num;
            scanf("%d (%d)", &u, &num);
            while(num--)
            {
                scanf("%d", &v);
                adj[u].push_back(v);
            }

        }
        t = 0;
        clrv(bridge);
        for(int i = 0; i < nos; i++)
        {
            if(!visited[i]) findBridge(i);
        }

        sort(bridge.begin(), bridge.end());
        printf("%d critical links\n",bridge.size());
        for(int i=0;i<bridge.size();i++)
            printf("%d - %d\n",bridge[i].first,bridge[i].second);
        printf("\n");
    }
    return 0;
}
