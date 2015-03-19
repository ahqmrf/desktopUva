#include<bits/stdc++.h>

using namespace std;


bool valid;
int sx, sy;
char puzzle[5][6];

bool isvalid(int x, int y)
{
    if(x > 4 || x < 0 || y > 4 || y < 0) return false;
    return true;
}

void makechange(char ch)
{
    int x, y;
    if(ch == 'A')
    {
        x = sx;
        y = sy - 1;
    }

    else if(ch == 'B')
    {
        x = sx;
        y = sy + 1;
    }

    else if(ch == 'L')
    {
        x = sx - 1;
        y = sy;
    }

    else if(ch == 'R')
    {
        x = sx + 1;
        y = sy;
    }
    valid = isvalid(x, y);
    if(valid)
    {
        swap(puzzle[y][x], puzzle[sy][sx]);
        sx = x;
        sy = y;
    }
}

int main()
{
    int cs = 1;
    while(1)
    {
        bool found = false;

        for(int i=0; i<5; i++)
        {
            gets(puzzle[i]);
            if(!strcmp(puzzle[0], "Z")) return 0;
            if(!found)
                for(int j=0; j<5; j++)
                {
                    if(puzzle[i][j] == ' ')
                    {
                        sx = j;
                        sy = i;
                        found = true;
                        break;
                    }
                }
        }

        char command;
        valid = true;
        while(scanf("%c", &command));
        {
            if(command=='0') break;
            if(!valid) continue;
            makechange(command);
        }
        if(cs > 1) printf("\n");
        printf("Puzzle #%d:\n", cs++);
        if(valid)
        {
            for(int i = 0; i<5; i++)
            {
                for(int j = 0; j<4; j++) printf("%c ", puzzle[i][j]);
                printf("%c\n", puzzle[i][4]);
            }
        }
        else printf("This puzzle has no final configuration.\n");
        getchar();
    }
    return 0;
}

