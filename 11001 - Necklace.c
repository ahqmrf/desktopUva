#include <stdio.h>
#include <math.h>
int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) == 2)
    {
        if(n == 0 && m == 0) break;
        int p = 0, i;
        double Max = 0, var;
        for(i = 1; i < n; i++)
        {
            var = n*1.0/i-m;
            if(var < 0)   break;
            double sum = 0.3*sqrt(var)*i;
            if(fabs(Max - sum) <= 1e-10)  p = 0;
            else if(sum > Max) Max = sum, p = i;
        }
        printf("%d\n", p);
    }
    return 0;
}
