#include<stdio.h>
#include<math.h>

int main (void)
{
    int cases;
    double const pi = 2 * acos(0.0);
    scanf("%d", &cases);
    while(cases--)
    {
        double L;
        scanf("%lf", &L);
        double w = L * 6/10;
        double r = L / 5;

        printf("%.2lf %.2lf\n", pi*r*r, w*L - (pi*r*r));

    }

    return 0;
}
