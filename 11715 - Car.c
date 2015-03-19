#include<stdio.h>
#include<math.h>

int main (void)
{
    int n, case_no = 0;
    while(scanf("%d", &n) == 1 && n)
    {
        if(n == 1)
        {
            double u, v, t;
            scanf("%lf %lf %lf", &u, &v, &t);
            double s, a;
            a = (v-u)/t;
            s = u*t + .5 * a * t * t;

            printf("Case %d: %.3lf %.3lf\n", ++case_no, s, a);
        }

        else if(n == 2)
        {
            double u, v, a;
            scanf("%lf %lf %lf", &u, &v, &a);
            double s, t;
            t = (v - u)/a;
            s = u*t + .5 * a * t * t;

            printf("Case %d: %.3lf %.3lf\n", ++case_no, s, t);
        }

        else if(n == 3)
        {
            double u, a, s;
            scanf("%lf %lf %lf", &u, &a, &s);
            double v, t;
            v = sqrt(u*u + 2*a*s);
            t = (v - u)/a;

            printf("Case %d: %.3lf %.3lf\n", ++case_no, v, t);
        }

        else if(n == 4)
        {
            double v, a, s;
            scanf("%lf %lf %lf", &v, &a, &s);
            double u, t;
            u = sqrt(v*v - 2*a*s);
            t = (v - u) / a;

            printf("Case %d: %.3lf %.3lf\n", ++case_no, u, t);
        }
    }

    return 0;
}
