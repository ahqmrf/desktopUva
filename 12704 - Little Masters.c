#include<stdio.h>
#include<math.h>

int main (void)
{
    int cases;
    double x, y, r, shortest;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%lf %lf %lf", &x, &y, &r);
        shortest = r - sqrt(x*x+y*y);
        printf("%.2lf %.2lf\n", shortest, 2.0*r - shortest);
    }
    return 0;
}
