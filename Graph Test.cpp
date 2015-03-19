#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<string>
#include<cstring>
#define INF 2147483647

using namespace std;

int X[6]= {0,0,0,-1,0,1};
int Y[6]= {0,0,-1,0,1,0};
int Z[6]= {1,-1,0,0,0,0};

char graph[30][30][30];
int visited[30][30][30];
int L, R, C;

struct vertex
{
    int a;
    int b;
    int c;
}source, destination;


bool valid(int i, int j, int k)
{
    if(i < 0 || i >= L || j < 0 || j >= R || k < 0 || k >= C) return false;
    if(graph[i][j][k] == '.' || graph[i][j][k] == 'E') return true;
    return false;
}

int bfs(vertex source)
{
    queue<vertex> myQ;
    myQ.push(source);
    visited[source.a][source.b][source.c] = 0;
    while(!myQ.empty())
    {
        vertex u = myQ.front();
        myQ.pop();
        if(u.a == destination.a && u.b == destination.b && u.c == destination.c)
        {
            return visited[u.a][u.b][u.c];
        }

        for(int i = 0; i<6; i++)
        {
            int x = u.a + X[i], y = u.b + Y[i], z = u.c + Z[i];
            vertex niu;
            if(valid(x, y, z))
            {
                if(visited[x][y][z] == -1)
                {
                    visited[x][y][z] = visited[u.a][u.b][u.c] + 1;
                    vertex newV;
                    newV.a = x, newV.b = y, newV.c = z;
                    myQ.push(newV);
                }
            }
        }
    }
    return -1;
}

int main (void)
{
    while(scanf("%d%d%d", &L, &R, &C) == 3)
    {
        if(L == 0 && R == 0 && C == 0) break;

        memset(visited, -1, sizeof(visited));
        for(int i = 0; i<L; i++)
        {
            for(int j = 0; j < R; j++)
            {
                for(int k = 0; k < C; k++)
                {
                    cin >> graph[i][j][k];
                    if(graph[i][j][k] == 'S')
                    {
                        source.a = i;
                        source.b = j;
                        source.c = k;
                    }

                    else if(graph[i][j][k] == 'E')
                    {
                        destination.a = i;
                        destination.b = j;
                        destination.c = k;
                    }

                }
            }
        }
        int result = bfs(source);
        if(result == -1) printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n", result);
    }
    return 0;
}
