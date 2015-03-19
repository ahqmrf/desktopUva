#include<bits/stdc++.h>
#define maxN 26

using namespace std;

int hasEdge[maxN][maxN];
int in[maxN], out[maxN], N;
vector< pair<int, int> > vec;

bool isOk(int &start)
{
    start = -1;
    int save, numIn = 0, numOut = 0;
    for(int i=0; i<maxN; i++)
    {
        if(out[i]) save = i;
        if(in[i] != out[i])
        {
            if(in[i] == out[i] + 1) numIn++;
            else if(in[i]+1 == out[i]) numOut++, start = i;
            else return false;
        }
    }
    if(start == -1) start = save;
    return (numIn <= 1 && numOut <= 1);
}

void dfs(int u)
{
    for(int i = 0; i<maxN; i++)
    {
        if(hasEdge[u][i])
        {
            hasEdge[u][i]--;
            dfs(i);
            vec.push_back(make_pair(u, i));
        }
    }
}

bool possible()
{
    int start;
    if(isOk(start))
    {
        dfs(start);
        return N == vec.size();
    }
    else return false;
}

int main()
{
    char word[1010];
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        memset(hasEdge, 0, sizeof hasEdge);
        memset(in, 0, sizeof in);
        memset(out, 0, sizeof out);
        vec.clear();
        scanf("%d", &N);
        for(int i = 0; i<N; i++)
        {
            scanf("%s", word);
            int first, last, len = strlen(word);
            first = word[0] - 97;
            last = word[len-1] - 97;
            hasEdge[first][last]++, in[last]++, out[first]++;
        }

         puts(possible() ? "Ordering is possible." : "The door cannot be opened.");
    }
    return 0;
}
