#include<stdio.h>
#include<math.h>

int main (void)
{
    int cases, i;
    scanf("%d", &cases);
    for(i = 1; i <= cases; i++)
    {
        double a, b, h, w;
        scanf("%lf %lf %lf", &a, &b, &h);
        if(a == b)
        {
            w = a*a - 4.0 * h * h;
            w = sqrt(w);
        }

        else
        {
            if( b > a)
            {
                double temp = a;
                a = b;
                b = temp;
            }

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
            w = sqrt(hehe);
        }

        printf("Case %d: %.10lf\n", i, w);
    }
}
