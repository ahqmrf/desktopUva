#include<stdio.h>
#include<math.h>

int main (void)
{
    double a = 40.0 , b = 30.0, h = 10.0;
    double hehe = a*a - b*b;
    double d = sqrt(hehe);
    double c = 4*h / d;
    double m = 64.0/27.0 + 0.25 * c * c * c * c;
    m = sqrt(m);
    double l = 0.5 * c * c;
    double cubic = 1.0 / 3.0;
    double m1 = pow(m - l, cubic);
    double m2 = pow(m + l, cubic);
    double u = m1 - m2;
    double v = c*c + 4.0 * u;
    double t1 = 0.25 * sqrt(v);
    double t2 = 0.5*c + 0.5 * sqrt(v);
    v = u*u + 4.0;
    double t3 = 2 * sqrt(v) - 2*u;
    v = t2*t2 + t3;
    double x = 0.25 * c + t1 + 0.5* sqrt(v);
    double p = 0.5 * (x + 1.0/x) * d;
    hehe = a*a - p*p;
    double w = sqrt(hehe);
    printf("%.10lf\n", w);
}
