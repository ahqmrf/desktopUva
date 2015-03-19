#include<map>
#include<vector>
#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;


int color[200];
bool possible;
vector<int>graph[1000];
void bfs()
{
    queue<int>myqueue;
    memset(color, -1, sizeof(color));
    myqueue.push(0);
    color[0] = 0;

    while(!myqueue.empty())
    {
        int u = myqueue.front();
        myqueue.pop();
        int len = graph[u].size();

        for(int i = 0; i<len; i++)
        {
            if(color[graph[u][i]] == -1)
            {
                if(color[u] == 0)
                {
                    color[graph[u][i]] = 1;
                }
                else color[graph[u][i]] = 0;
                myqueue.push(graph[u][i]);
            }
            else
            {
                if(color[u] == color[graph[u][i]])
                {
                    possible = false;
                    break;
                }
            }
        }
        if(!possible) break;
    }
}

int main (void)
{
    int nvertex, nedge;
    while(scanf("%d", &nvertex), nvertex)
    {
        scanf("%d", &nedge);
        for(int i=0;i<nvertex;i++)
            graph[i].clear();
        for(int i = 0; i<nedge; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        possible = true;
        bfs();
        if(possible) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
    }
    return 0;
}
