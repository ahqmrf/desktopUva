#include<bits/stdc++.h>
#define maxN 1000

using namespace std;

struct node
{
    int r,c,cost;

    node(){
    }

    node(int _r, int _c, int _cost){
        r=_r;
        c=_c;
        cost=_cost;
    }

    bool operator < (node X) const{
        return cost>X.cost;
    }
};


bool visited[maxN][maxN];
int minCost[maxN][maxN];
int cost[maxN][maxN];
int N, M;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool isvalid(int i, int j)
{
    if(i<0 || j<0 || i>=N || j>=M) return false;
    return true;
}

void dijkstra()
{
    minCost[0][0] = cost[0][0];
    priority_queue<node> Q;
    Q.push(node(0, 0, cost[0][0]));

    while(1)
    {
        node u = Q.top();
        Q.pop();

        if(!visited[u.r][u.c])
        {
            visited[u.r][u.c] = true;
            if(u.r == N-1 && u.c == M-1)
            {
                printf("%d\n", u.cost);
                break;
            }

            for(int i=0; i<4; i++)
            {
                int a = u.r + dx[i];
                int b = u.c + dy[i];

                if(isvalid(a, b) && (minCost[a][b] == -1 || minCost[a][b] > minCost[u.r][u.c]+cost[a][b]))
                {
                    minCost[a][b] = minCost[u.r][u.c]+cost[a][b];
                    Q.push(node(a, b, minCost[a][b]));
                }
            }
        }

    }
}

void setMaze()
{
    for(int i=0;i<N;i++) fill(minCost[i],minCost[i]+M,-1);
    for(int i=0;i<N;i++) fill(visited[i],visited[i]+M,false);
}

int main(void)
{
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d%d", &N, &M);
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                scanf("%d", &cost[i][j]);
        setMaze();
        dijkstra();
    }
    return 0;
}
