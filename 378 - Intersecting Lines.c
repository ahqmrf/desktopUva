#include<stdio.h>
#include<math.h>

double x, y;
int flag;
void intersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    double m1 = dy / dx;
    double c1 = y1 - m1 * x1;

    dx = x4 - x3;
    dy = y4 - y3;
    double m2 = dy / dx;
    double c2 = y4 - m2 * x4;

    flag = 1;
    x = (c2-c1)/(m1-m2);
    y = m1 * x + c1;
}

int main (void)
{
    int cases;
    scanf("%d", &cases);
    printf("INTERSECTING LINES OUTPUT\n");
    double x1, y1, x2, y2, x3, y3, x4, y4;
    while(cases--)
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
        intersect(x1, y1, x2, y2, x3, y3, x4, y4);

        printf("POINT %.2lf %.2lf\n", x, y);

    }
    printf("END OF OUTPUT\n");
    return 0;
}

