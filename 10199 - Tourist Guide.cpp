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
        map<string, int> mpin;
        map<int, string> mpname;
        for(int i = 0; i<nop; i++)
        {
            string name;
            cin >> name;
            mpin[name] = i;
            mpname[i] = name;
        }
        int noe;
        for(int i=0;i<nop;i++) adj[i].clear();
        scanf("%d", &noe);
        while(noe--)
        {
            string a, b;
            cin >> a >> b;
            adj[mpin[a]].push_back(mpin[b]);
            adj[mpin[b]].push_back(mpin[a]);
        }

        memset(visited, false, sizeof(visited));
        memset(isAP, false, sizeof(isAP));
        memset(parent, 0, sizeof(parent));
        memset(dis, 0, sizeof(dis));
        memset(low, 0, sizeof(low));
        vector<string> APs;
        c = 0;
        for(int i=0; i<nop; i++)
            if(!visited[i]) findAP(i, i);

        for(int i=0; i<nop; i++)
            if(isAP[i]) APs.push_back(mpname[i]);

        if(case_no>1) cout<<"\n";
        cout << "City map #" << case_no++ <<": ";
        cout << APs.size() << " camera(s) found\n";

        sort(APs.begin(), APs.end());
        for(int i=0; i<APs.size(); i++)
            cout << APs[i] << endl;

    }
    return 0;
}

