#include <iostream>
#include <complex>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;
typedef complex <double> point;
#define X real()
#define Y imag()
#define polar(r,t) ((r)*exp(point(0,(t))))
#define length(a) hypot((a).X,(a).Y)
#define angle(a) atan2((a).Y,(a).X)
#define vec(a,b) ((b)-(a))
#define dot(a,b) ((conj(a)*(b)).real())
#define cross(a,b) ((conj(a)*(b)).imag())
#define lengthSqr(a) dot(a,a)
#define rotate(v,t) ((v)*exp(point(0,t)))
#define rotateAbout(v,t,a) (rotate(vex(a,v),t)+(a))
#define reflect(V,M) (conj((V)/(M))*(M))
#define same(a,b) (lengthSqr(vec(a,b))==0)
#define EPS 1.0e-10
#define PI 2*acos(0)
bool intersectLine(const point &a, const point &b, const point &p, const point &q, point & ret)
{
    double d1 = cross(p - a, b - a);
    double d2 = cross(q - a, b - a);
    ret = (d1 * q - d2 * p) / (d1 - d2);
    return fabs(d1-d2) > EPS;
}
void perBisector(point &a,point &b,point &c,point &d)
{
    point mid = (a+0.5*(b-a));
    double x = vec(a,b).X;
    double y = vec(a,b).Y;
    point p1(-1*y,x);
    point p2(y,-1*x);
    p1=p1+mid;
    p2=p2+mid;
    c=p1;
    d=p2;
}
int main()
{
    double x1,y1,x2,y2,x3,y3;
    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
    {
        point A (x1,y1);
        point B (x2,y2);
        point C (x3,y3);
        point p1,p2,p3,p4,center;
        perBisector(A,B,p1,p2);
        perBisector(B,C,p3,p4);
        intersectLine(p1,p2,p3,p4,center);
        double r = length(vec(center,A));
        double x = center.X;
        double y = center.Y;
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
