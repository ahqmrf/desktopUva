#include<math.h>
#include<stdio.h>
#define PI acos(-1)

int main (void)
{
    double l,w, h, theta;
    while(scanf("%lf%lf%lf%lf", &l, &w, &h, &theta)!=EOF)
    {
        double volume = l*w*h;
        theta = (PI*theta)/180.0;
        double tH = l*tan(theta);
        double vol;
        if(tH > h)
        {
            double base = h/tan(theta);
            vol = h * base * 0.5 * w;
        }

        else
        {
            vol = volume - 0.5 * l * tH * w;
        }

        printf("%.3lf mL\n", vol);
    }
    return 0;
}
