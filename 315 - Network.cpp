#include<bits/stdc++.h>

using namespace std;

bool visited[110], isAP[110];
vector<int>adj[110];
int c, dis[110], low[110], parent[110];

void findAP(int u, int root)
{
    low[u] = dis[u] = ++c;
    visited[u] = true;
    int children = 0, noadj = adj[u].size();
    for(int i = 0; i < noadj; i++)
    {
        int v = adj[u][i];
        if(!visited[v])
        {
            children++;
            parent[v] = u;
            findAP(v, root);
            low[u] = min(low[u], low[v]);
            if(u == root && children > 1) isAP[u] = true;
            else if(u != root && low[v] >= dis[u]) isAP[u] = true;
        }
        else if(parent[u] != v) low[u] = min(low[u], dis[v]);
    }
    return;
}

int main (void)
{
    int nop, case_no = 1;
    while(scanf("%d", &nop), nop)
    {

        for(int i=0;i<=nop;i++) adj[i].clear();
        if(nop == 1)
        {
            string point;
            cin >> point;
            cout << 0 << endl;
            continue;
        }
        getchar();
        string line;
        int a, b;
        while(getline(cin, line))
        {
            istringstream iss(line);
            iss >> a;
            if(a == 0) break;
            while(iss >> b)
            {
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
        }

        memset(visited, false, sizeof(visited));
        memset(isAP, false, sizeof(isAP));
        memset(parent, 0, sizeof(parent));
        memset(dis, 0, sizeof(dis));
        memset(low, 0, sizeof(low));

        c = 0;
        int countAP = 0;
        for(int i=1; i<=nop; i++)
            if(!visited[i]) findAP(i, i);

        for(int i=1; i<=nop; i++)
            if(isAP[i]) countAP++;

        printf("%d\n", countAP);

    }
    return 0;
}

