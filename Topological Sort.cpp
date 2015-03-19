#include<bits/stdc++.h>
#define inf 2147483647

using namespace std;

bool visited[1000];
vector<int>graph[1000];
vector<int>tasks;
void dfs(int u)
{
    visited[u] = true;
    int noadjv = graph[u].size();
    for(int i = 0; i < noadjv; i++)
    {
        int v = graph[u][i];
        if(!visited[v])
        {
            dfs(v);
        }
    }
    tasks.push_back(u);

}

int main ()
{
    int n, m;
    while(scanf("%d%d", &n, &m) && (n||m))
    {
        int a, b;
        memset(visited, false, sizeof(visited));

        while(m--)
        {
            scanf("%d%d", &a, &b);
            graph[a-1].push_back(b-1);
        }

        for(int i=0; i< n; i++)
        {
            if(!visited[i]) dfs(i);
        }

        for(int i = tasks.size() - 1; i >= 0; i--)
        {
            if(i == 0) printf("%d\n", tasks[i]+1);
            else printf("%d ", tasks[i]+1);
        }
        for(int i = 0; i < n; i++) graph[i].clear();
        tasks.clear();
    }
    return 0;
}
