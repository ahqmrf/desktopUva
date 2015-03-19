#include<stdio.h>
#include<stdlib.h>

int main (void)
{
    int n, i;
    while(scanf("%d", &n), n)
    {
        double *cost = (double*)malloc(n*sizeof(double));
        double avg = 0;
        for(i=0; i<n; i++)
        {
            scanf("%lf", &cost[i]);
            avg += cost[i];
        }
        avg /= n;
        double pos = 0, neg = 0, d;
        for(i=0; i<n; i++)
        {
            d = (long)((cost[i]-avg)*100.0)/100.0;
            if(d > 0) pos += d;
            else neg+=d;
        }
        neg = -neg;
        if(neg > pos) pos = neg;
        printf("$%.2lf\n", pos);
        free(cost);
    }
    return 0;
}
