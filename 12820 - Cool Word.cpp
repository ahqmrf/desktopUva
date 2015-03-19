#include<bits/stdc++.h>

using namespace std;

int main()
{
    int N, k = 1;
    while(scanf("%d", &N) == 1)
    {
        char word[30];
        int cool = 0;
        while(N--)
        {
            scanf("%s", word);
            int f[60], c = 0;
            memset(f, 0, sizeof f);
            set<int> s;
            for(int i = 0; word[i]; i++)
            {
                f[word[i]-65]++;
            }
            for(int i = 0; i< 60; i++)
            {
                if(f[i])
                {
                    c++;
                    s.insert(f[i]);
                }
            }
            int sz = s.size();
            if(sz != 1 && sz == c) cool++;
        }
        printf("Case %d: %d\n", k++, cool);
    }
    return 0;
}
