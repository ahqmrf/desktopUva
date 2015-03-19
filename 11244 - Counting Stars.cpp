#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int di[] = { -1, 0, 1, 0, 1, 1, -1, -1 };
int dj[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
int coun;
bool flag[200][200];
char grid[200][200];
int N, M;
bool found;
void dfs(int i, int j)
{
    flag[i][j]=false;

    for(int k=0; k<8; k++)
    {
        int x = i+di[k];
        int y = j+dj[k];
        if(x<0||y<0||x>=N||y>=M) continue;
        if(grid[x][y]=='*' && flag[x][y])
        {
            found = true;
            dfs(x, y);
        }
    }
}
int main (void)
{
    while(scanf("%d%d", &N, &M)==2 && (M && N))
    {
        for(int i=0; i<N; i++) scanf("%s", grid[i]);

        memset(flag, true, sizeof(flag));
        int stars = 0;
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
            {
                found = false;
                if(grid[i][j]=='*' && flag[i][j])
                {
                    dfs(i,j);
                    if(!found) stars++;
                }
            }

        printf("%d\n", stars);
    }
    return 0;
}

