#include<string>
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main (void)
{
    string zerosOnes;
    int case_no = 0;
    while(getline(cin, zerosOnes))
    {
        int queries;
        scanf("%d", &queries);
        printf("Case %d:\n", ++case_no);
        while(queries--)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            if(a == b) printf("Yes\n");
            else
            {
                int x = min(a, b);
                int y = max(a, b);
                bool flag = true;

                for(int i = x; i < y; i++)
                {
                    if(zerosOnes[i] != zerosOnes[i+1])
                    {
                        flag = false;
                        break;
                    }
                }

                if(flag) printf("Yes\n");
                else printf("No\n");
                string hudai;
                getline(cin, hudai);
            }
        }
    }
    return 0;
}
