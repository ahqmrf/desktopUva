#include<map>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;
map<int, int>visited;
int node, ttl;

void bfs(int start, map <int,vector<int> > graph)
{
    queue<int> s;
    s.push(start);
    visited[start]=0;
    while (s.empty() == false)
    {
        int top = s.front();
        s.pop();
        int size = graph[top].size();
        for(int i=0;i<size;i++)
        {
            int n =graph[top][i];
            if(!visited.count(n))
            {
                visited[n]=visited[top]+1;
                s.push(n);
            }
        }
    }
}

int main (void)
{
    int nop, cs=1;
    while(scanf("%d", &nop), nop)
    {
        map<int, vector<int> > m;
        int node1, node2;
        for(int i=0; i<nop; i++)
        {
            scanf("%d%d", &node1, &node2);
            m[node1].push_back(node2);
            m[node2].push_back(node1);
        }

        while(scanf("%d%d", &node, &ttl) && (ttl!=0||node!=0))
        {
            visited.clear();
            map <int,int>::const_iterator itr;
            bfs(node, m);
            int un = 0;
            for(itr = visited.begin(); itr != visited.end(); ++itr)
            {
                if((*itr).second>ttl) un++;
            }
            un += m.size()-visited.size();
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",cs++,un,node,ttl);
        }

    }
    return 0;
}
