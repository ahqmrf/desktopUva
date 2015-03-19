#include<cmath>
#include<iostream>
#include<cstdio>

using namespace std;

int main (void)
{
    int cases, case_no = 0;
    double a, b, r;
    char colon;
    double coneA, coneB, coneC, B, l, w;
    double const pi = 2*acos(0.0);

    while(cin >> a >> colon >> b){
        coneC = atan(a/b);
        coneB = pi - 2*coneC;
        B = coneB;
        coneA = pi - coneB;
        coneB = (B*180)/(pi*360);
        r = 800/(2*sqrt(2-2*cos(coneA))+4*pi*coneB);
        w = r*cos(coneC);
        l = sqrt(r*r-w*w);

        printf("Case %d: %.10lf %.10lf\n", ++case_no, l, w);
    }

    return 0;
}

