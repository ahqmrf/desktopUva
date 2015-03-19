#include<bits/stdc++.h>

using namespace std;

int main()
{
    int N, c = 1;
    int a[110];
    while(scanf("%d", &N)!=EOF)
    {
        bool is = true;

        for(int i = 0; i<N; i++)
        {
            scanf("%d", &a[i]);
            if(a[i] < 1 || (i>0 && a[i] <= a[i-1])) is = false;
        }
        set<int> s;

        for(int i = 0; i<N && is; i++)
        {
            for(int j = i; j<N; j++)
            {
                int sum = a[i] + a[j];
                if(s.find(sum) != s.end())
                {
                    is = false;
                    break;
                }
                else s.insert(sum);
            }
        }
        if(is) printf("Case #%d: It is a B2-Sequence.\n\n", c++);

        else printf("Case #%d: It is not a B2-Sequence.\n\n", c++);
    }
    return 0;
}
