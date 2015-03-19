#include<cstring>
#include<queue>
#include<cstdio>

using namespace std;

int X[]= {0,0,-1,1};
int Y[]= {1,-1,0,0};
char maze[1001][1001];
bool visited[1001][1001];

struct stuff
{
    int x;
    int y;
    int t;
    char id;
} Joe, Fire;

int r, c;

bool inside(int i, int j)
{
    if(i < 0 || i >= r || j < 0 || j>= c) return false;
    return true;
}

int main (void)
{
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        memset(visited, false, sizeof(visited));
        queue<stuff> myq;
        scanf("%d%d", &r, &c);
        for(int i = 0; i < r; i++) scanf("%s", maze[i]);
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(maze[i][j] == '#') visited[i][j] = true;
                else if(maze[i][j] == 'F')
                {
                    Fire.x = i;
                    Fire.y = j;
                    Fire.t = 0;
                    Fire.id = 'F';
                    visited[i][j] = true;
                    myq.push(Fire);
                }
                else if(maze[i][j] == 'J')
                {
                    Joe.x = i;
                    Joe.y = j;
                    Joe.t = 0;
                    Joe.id = 'J';
                    visited[i][j] = true;
                }
            }
        }

        myq.push(Joe);
        int ans = -1;
        while(!myq.empty())
        {
            stuff u, v;
            u = myq.front();
            myq.pop();
            for(int i = 0; i < 4; i++)
            {
                v = u;
                v.t++;
                v.x += X[i], v.y += Y[i];
                if(inside(v.x, v.y))
                {
                    if(visited[v.x][v.y]) continue;
                    visited[v.x][v.y] = true;
                    myq.push(v);
                }
                else if(v.id == 'J')
                {
                    ans = v.t;
                    break;
                }
            }
            if(ans != -1) break;
        }
        if(ans == -1) puts("IMPOSSIBLE");
        else printf("%d\n", ans);
    }
    return 0;
}
