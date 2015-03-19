#include<vector>
#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

bool flag[11][11];
int grid[11][11];
int N;


int main (void)
{

    for(int c=1; ; c++)
    {
        scanf("%d", &N);
        if(!N) break;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                scanf("%d", &grid[i][j]);
        memset(flag, true, sizeof(flag));
        int left = 0, right = N-1;
        vector<int>sums;
        while(left<=right)
        {
            int total = 0;
            for(int i=0; i<N; i++)
            {
                for(int j=0; j<N; j++)
                {
                    if((i==left||i==right||j==left||j==right) && flag[i][j])
                    {
                        total += grid[i][j];
                        flag[i][j]=false;
                    }
                }
            }
            sums.push_back(total);
            left++;
            right--;
        }

        int s = sums.size();
        printf("Case %d:",c);
        for(int i = 0; i<s; i++)
        {
            printf(" %d", sums[i]);
        }
        printf("\n");
    }

    return 0;

}
