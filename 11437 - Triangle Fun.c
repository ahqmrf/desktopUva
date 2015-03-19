#include<stdio.h>
#include<math.h>

double x, y;

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
    x = (c2-c1)/(m1-m2);
    y = m1 * x + c1;
}

int main (void)
{
    double s, a, b, c, ax, ay, bx, by, cx, cy, dx, dy, ex, ey, fx, fy, px, py, qx, qy, rx, ry;
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%lf%lf%lf%lf%lf%lf", &ax, &ay, &bx, &by, &cx, &cy);
        dx = (cx+2*bx)/3; dy = (cy+2*by)/3;
        ex = (ax+2*cx)/3; ey = (ay+2*cy)/3;
        fx = (bx+2*ax)/3; fy = (by+2*ay)/3;
        intersect(ax, ay, dx, dy, bx, by, ex, ey);
        px = x; py = y;
        intersect(cx, cy, fx, fy, bx, by, ex, ey);
        qx = x; qy = y;
        intersect(ax, ay, dx, dy, cx, cy, fx, fy);
        rx = x; ry = y;
        a = sqrt((qx-rx)*(qx-rx)+(qy-ry)*(qy-ry));
        b = sqrt((px-rx)*(px-rx)+(py-ry)*(py-ry));
        c = sqrt((qx-px)*(qx-px)+(qy-py)*(qy-py));
        s = (a+b+c)/2;
        printf("%.0lf\n", sqrt(s*(s-a)*(s-b)*(s-c)));

    }

}
