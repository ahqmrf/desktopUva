#include<stdio.h>
double const error = 1e-7;

int main (void)
{
    int case_no = 0;
    double a, b, c, p, q;
    while(scanf("%lf %lf %lf", &a, &b, &c), a != -1){
        p = (a*c)/b;
        printf("Set %d:\n", ++case_no);
        if(b == p || b == 0.0) printf("Poor King!\n");
        else
        {
            q = (p+a) * (p+c) / (b-p);
            (p+q>0) ? printf("%.4lf\n",p+q): printf("Poor King!\n");
        }
    }

    return 0;
}
