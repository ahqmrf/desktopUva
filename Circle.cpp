#include <iostream>
#include <complex>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iomanip>
#include<cmath>

using namespace std;


int main (void)
{
    double x1, y1, x2, y2, x3, y3;
    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
    {
        double mr = (y2 - y1) / (x2 - x1);
        double mt = (y3 - y2) / (x3 - x2);
        double a = mr * mt * (y3 - y1);
        double b = mr * (x2 + x3);
        double c = mt * (x1 + x2);
        double d = 2.0 * (mr - mt);
        double A = a + b - c;
        double x = A / d;
        a = -1.0 / mr;
        b = (x1 + x2)/2.0;
        b = x - b;
        c = (y1 + y2)/2.0;
        double y = a * b + c;

        double r = (x1 - x)*(x1 - x) + (y1 - y)*(y1 - y);
        r = sqrt(r);
        double h = x;
        double k = y;

        cout << "(x ";
        if(h<0){
        cout << "+ ";
        printf("%.3f",fabs(-1*h));
        cout << ")^2 + (y ";

        }else {
            cout << "- " ;
            printf("%.3f",fabs(h));
            cout << ")^2 + (y ";
        }if(k<0){
        cout << "+ ";
         printf("%.3f",fabs(-1*k));
         cout << ")^2 = ";
       }
       else {
       cout << "- ";
       printf("%.3f",fabs(k));
       cout << ")^2 = ";
       }
       printf("%.3f^2\n",r);

        cout << "x^2 + y^2 ";
        if(-2*h<0)
            cout <<"- ";
        else cout <<"+ ";
        printf("%.3fx ",fabs(-2*h));
        if(-2*k<0)
            cout<<"- ";
        else cout <<"+ ";
        printf("%.3fy ",fabs(-2*k));
        if(k*k+h*h-r*r<0)
        cout << "- ";
        else cout <<"+ ";
        printf("%.3f = 0\n\n",fabs(k*k+h*h-r*r));


    }
    return 0;
}

