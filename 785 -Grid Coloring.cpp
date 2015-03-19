#include<bits/stdc++.h>
using namespace std;

int length, width;
char grid[2000][2000];
char str[2000];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void paint(int x, int y, char mark, char color)
{
    for(int i=0; i<4; i++)
    {
        int r = x + dx[i];
        int c = y + dy[i];
        if(r>=0 && r<length && c>=0 && c<width && grid[r][c] == ' ' && grid[r][c] != mark)
        {
            grid[r][c] = color;
            paint(r, c, mark, color);
        }
    }
}

void dfs()
{
    bool markFound = false;
    char mark, color;

    for(int i=0; i<length; i++)
    {
        width = strlen(grid[i]);
        for(int j=0; j<width; j++)
        {
            if(!markFound && grid[i][j]!='_' && grid[i][j]!=' ')
            {
                markFound = true;
                mark = grid[i][j];
            }
            if(markFound && grid[i][j]!='_' && grid[i][j]!=' ' && grid[i][j]!=mark)
            {
                color = grid[i][j];
                paint(i, j, mark, color);
            }
        }
    }
}

int main()
{
    int i;
    i = width = 0;
    while(gets(str))
    {
        if(str[0]=='_')
        {
            length = i;
            dfs();
			for (int j = 0; j < length; ++j)
            {
				width = strlen(grid[j]);
				for (int k = 0; k < width; ++k)
					printf("%c", grid[j][k]);
				puts("");
			}
			puts(str);
			i = width = 0;
			continue;
        }
        strcpy(grid[i], str);
        int len = strlen(grid[i]);
        if(len > width)
            width = len;
        i++;

    }
    return 0;
}
