#include<stdio.h>
#include<math.h>

int main ()
{
    double const pi = 2 * acos(0.0);
    double a, b, c;
    while(scanf("%lf%lf%lf", &a, &b, &c) == 3)
    {
        double s = (a+b+c)/2.000000;
        double triangle = sqrt(s*(s-a)*(s-b)*(s-c));
        double R = (a*b*c)/sqrt((a+b+c) * (a+b-c) * (b+c-a) * (c+a-b));
        double r = ((s-a)*(s-b)*(s-c)/s);

        double BigCircle = pi * R * R;
        double SmallCircle = pi * r;

        printf("%.4lf %.4lf %.4lf\n", BigCircle-triangle, triangle-SmallCircle, SmallCircle);

    }
    return 0;
}
