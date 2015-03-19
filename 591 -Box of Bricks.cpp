#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main (void)
{
    int n, case_no = 0;
    while(scanf("%d", &n) == 1 && n)
    {
        vector<int> bricks;
        int avg = 0;
        for(int i = 0; i < n; ++i)
        {
            int h;
            scanf("%d", &h);
            avg += h;
            bricks.push_back(h);
        }

        avg /= n;

        sort(bricks.begin(), bricks.end());

        int moves = 0;

        for(int i = 0; i < n/2; ++i)
        {
            int dif = avg - bricks[i];
            if(dif < 0) dif = dif * (-1);
            moves += dif;
        }

        printf("Set #%d\nThe minimum number of moves is %d.\n\n", ++case_no, moves);

    }
    return 0;
}
