#include<bits/stdc++.h>

using namespace std;


bool valid;
int sx, sy;

bool isvalid(int x, int y)
{
    if(x > 4 || x < 0 || y > 4 || y < 0) return false;
    return true;
}

void makechange(char ch, vector<string> &puzzle)
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
        vector<string> puzzle(5);
        for(int i=0; i<5; i++)
        {
            getline(cin, puzzle[i]);
            if(!puzzle[0].compare("Z")) return 0;
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
        while(cin>>command)
        {
            if(command=='0') break;
            if(!valid) continue;
            makechange(command, puzzle);
        }
        if(cs > 1) cout << endl;
        cout << "Puzzle #" << cs++ << ":" << endl;
        if(valid)
        {
            for(int i = 0; i<5; i++)
            {
                for(int j = 0; j<4; j++) cout << puzzle[i][j] << " ";
                cout << puzzle[i][4] << endl;
            }
        }
        else cout << "This puzzle has no final configuration." << endl;
        getchar();
    }
    return 0;
}
