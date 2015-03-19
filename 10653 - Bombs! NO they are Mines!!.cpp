#include<queue>
#include<cstdio>
#include<cstring>

using namespace std;

int X[]= {0,0,-1,1};
int Y[]= {1,-1,0,0};

bool visited[1001][1001];
int dist[1001][1001];
int R, C, sx, sy, ex, ey;

struct cell
{
    int x;
    int y;
}s, e;


bool valid(int i, int j)
{
    if(i < 0 || i >= R || j < 0 || j >= C) return false;
    if(visited[i][j]) return false;
    return true;
}

int time()
{
    queue<cell> myq;
    myq.push(s);
    dist[s.x][s.y] = 0;
    while(!myq.empty())
    {
        cell u = myq.front();
        myq.pop();
        if(u.x == e.x && u.y == e.y) return dist[u.x][u.y];
        for(int i = 0; i<4; i++)
        {
            int xx = u.x + X[i], yy = u.y + Y[i];
            if(valid(xx, yy))
            {
                if(visited[xx][yy] == false)
                {
                    visited[xx][yy] = true;
                    dist[xx][yy] = dist[u.x][u.y] + 1;
                    cell niu;
                    niu.x = xx, niu.y = yy;
                    myq.push(niu);
                }
            }
        }
    }
}

int main ()
{
    while(scanf("%d %d",&R,&C)==2)
    {
        if(!R && !C)
            break;
        memset(visited, false ,sizeof visited);
        int num;
        scanf("%d",&num);
        for(int i=1; i<=num; i++)
        {
            int rn, n, cn;
            scanf("%d %d",&rn,&n);
            for(int j=1; j<=n; j++)
            {
                scanf("%d",&cn);
                visited[rn][cn]=true;
            }
        }
        scanf("%d%d", &s.x, &s.y);
        scanf("%d%d", &e.x, &e.y);

        printf("%d\n", time());

    }
    return 0;
}
