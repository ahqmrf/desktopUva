#include<bits/stdc++.h>
#define pi acos(-1)

using namespace std;

int main()
{
    double R, theta[512];
    int N;
    while(scanf("%d %lf", &N, &R) == 2 && N)
    {
        for(int i = 0; i < N; i++)
        {
            scanf("%lf", &theta[i]);
            theta[i] *= pi/180;
        }
        if(N < 3) puts("0");
        else
        {
            double area = 0;
            sort(theta, theta + N);
            for(int i = 0; i < N - 1; i++)
                for(int j = i + 1; j < N; j++)
                    area += (N + 2*i - 2*j) * sin(theta[j]-theta[i]);

            area *= R*R/2;
            printf("%.0lf\n", area);
        }
    }
    return 0;
}
