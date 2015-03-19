#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

char boggle[5][5];
bool flag[5][5];
int now, word_length;
char word[20];
bool found;

int di[] = { -1, 0, 1, 0, 1, 1, -1, -1 };
int dj[] = { 0, 1, 0, -1, 1, -1, 1, -1 };

void dfs(int i, int j, int len)
{
    if(len == word_length-1) found = true;
    if(found) return;

    for(int k=0; k<8; k++)
    {
        int x = i+di[k];
        int y = j+dj[k];
        if(x<0||x>3||y<0||y>3) continue;
        if(flag[x][y] && boggle[x][y]==word[len+1])
        {
            flag[x][y] = false;
            dfs(x, y, len+1);
            flag[x][y] = true;
        }
    }
}



int main (void)
{
    int cases;
    scanf("%d", &cases);
    for(int c=1; c<=cases; c++)
    {
        int score = 0;
        memset(flag, true, sizeof(flag));
        for(int i=0; i<4; i++)
        {
            scanf("%s", boggle[i]);
        }

        scanf("%d", &now);
        for(int i=0; i<now; i++)
        {
            scanf("%s", word);
            word_length = strlen(word);
            found = false;

            for(int i=0; i<4; i++)
            {
                for(int j =0; j<4; j++)
                {
                    if(boggle[i][j]==word[0])
                    {
                        flag[i][j] = false;
                        dfs(i, j, 0);
                        flag[i][j] = true;
                    }
                }
            }

            if(found)
            {
                if (word_length <= 4) score++;
                else if (word_length == 5) score += 2;
                else if (word_length == 6) score += 3;
                else if (word_length == 7) score += 5;
                else if (word_length >= 8) score += 11;
            }
        }

        printf("Score for Boggle game #%d: %d\n",c, score);

    }

    return 0;

}
