#include<bits/stdc++.h>
#define inf 2147483647

using namespace std;

int main ()
{
    int n, m, cs=1;
    while(scanf("%d%d", &n) != EOF)
    {
        vector<int>graph[n+3];
        vector<int>tasks;
        bool taken[n+3];
        map<int, int>indegree;

        memset(taken, false, sizeof(taken));
        map<string, int> indx;
        map<int, string> name;
        for(int i = 0; i<n; i++)
        {
            string x;
            cin >> x;
            indx[x] = i;
            name[i] = x;
        }

        cin >> m;

        while(m--)
        {
            string x, y;
            cin >> x >> y;
            graph[indx[x]].push_back(indx[y]);
            indegree[indx[y]]++;
        }

        for(int i=0; i< n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(!taken[j] && !indegree[j])
                {
                    taken[j] = true;
                    tasks.push_back(j);
                    int lim = graph[j].size();
                    for(int k = 0; k < lim; k++)
                    {
                        indegree[graph[j][k]]--;
                    }
                    break;
                }
            }
        }
        int sz = tasks.size();
        printf("Case #%d: Dilbert should drink beverages in this order:", cs++);
        for(int i = 0; i < sz; i++)
        {
            cout << " " << name[tasks[i]];
        }
        puts(".\n");
        for(int i = 0; i < n; i++) graph[i].clear();
        tasks.clear();
    }
    return 0;
}

