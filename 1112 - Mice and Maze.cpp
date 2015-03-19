#include<bits/stdc++.h>

using namespace std;

int maze[102][102];

int main()
{
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        int n, exit, m, t;
        memset(maze, 63, sizeof maze);
        scanf("%d\n%d\n%d\n%d\n", &n, &exit, &t, &m);
        n++;
        while(m--)
        {
            int a, b, w;
            scanf("%d %d %d", &a, &b, &w);
            maze[a][b] = w;
        }

        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    maze[i][j] = min(maze[i][j], maze[i][k]+maze[k][j]);

        int nom = 0;
        for(int i = 0; i < n; i++)
        {
            if(maze[i][exit] <= t || i == exit) nom++;
        }

        printf("%d\n", nom);
        if(cases) printf("\n");
    }
    return 0;
}
