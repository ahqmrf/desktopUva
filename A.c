#include<stdio.h>
#include<math.h>

int main (void)
{
    double x1, x2, y1, y2, x3, y3;
    while(scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3)==6)
    {
        double mr, mt;
        mr = (y2-y1)/(x2-x1);

        mt = (y3-y2)/(x3-x2);

        double dy = mr*mt*(y3-y1);
        double dx1 = mr*(x2+x3);
        double dx2 = mt*(x1+x2);
        double dx3 = 2*(mr - mt);

        double x = (dy + dx1 - dx2);
        x = x / dx3;
        double y = -(1/mr) * (x - (x1+x2)/2) + (y1+y2)/2;
        char ch1, ch2;
        if(x < 0.000000) ch1 = '+';
        else ch1 = '-';
        if(y < 0.000000) ch2 = '+';
        else ch2 = '-';

        double X, Y;
        if(x < 0.00000) X = -1* x;
        else X = x;
        if(y < 0.00000) Y = -1* y;
        else Y = y;

        double r = sqrt((x2-x)*(x2-x) + (y2-y)*(y2-y));

        printf("(x %c %.3lf)^2 + (y %c %.3lf)^2 = %.3lf^2\n", ch1, X, ch2,  Y, r);

        if(x < 0.00000) X = -2* x;
        else X = 2*x;
        if(y < 0.00000) Y = -2* y;
        else Y = 2*y;

        double constant = x*x + y*y - r*r;
        char ch3;
        if(constant < 0.000000) ch3 = '-';
        else ch3 = '+';
        if(constant < 0.000000) constant = -1*constant;
        printf("x^2 + y^2 %c %.3lfx %c %.3lfy %c %.3lf = 0\n\n", ch1, X, ch2, Y, ch3, constant);
    }
    return 0;
}
