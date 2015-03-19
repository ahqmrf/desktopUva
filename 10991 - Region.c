#include<stdio.h>
#include<math.h>
#define PI acos(-1)

int main (void)
{
    double r1, r2, r3, a, b, c, ta, s, A, B, C, aa, ab, ac;
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%lf%lf%lf", &r1, &r2, &r3);
        a = r1+r3;
        b = r1+r2;
        c = r2+r3;
        s = (a+b+c)/2;
        ta = sqrt(s*(s-a)*(s-b)*(s-c));
        A = acos((b*b+c*c-a*a)/(2*b*c));
        B = acos((a*a+c*c-b*b)/(2*a*c));
        C = acos((b*b+a*a-c*c)/(2*b*a));
        aa = (A/2)*r2*r2;
        ab = (B/2)*r3*r3;
        ac = (C/2)*r1*r1;
        double area = ta-(aa+ab+ac);
        printf("%.6lf\n", area);

    }
    return 0;
}
