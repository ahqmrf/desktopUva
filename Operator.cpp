#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

typedef struct point
{
    double x,y;
    point(double xx=0,double yy=0):x(xx),y(yy){}
}vector;
vector operator - (point a,point b)
{
    return vector(a.x-b.x,a.y-b.y);
}
point operator + (point a,vector b)
{
    return point(a.x+b.x,a.y+b.y);
}
double dot(vector a,vector b)
{
    return a.x*b.x+a.y*b.y;
}
double len(vector a)
{
    return sqrt(dot(a,a));
}
vector resiz(vector a,double b)
{
    return vector(a.x*b,a.y*b);
}

int main()
{
    int t;
    double m1,m2,m3,m4,m5,m6;
    point p,q,r,pa,pb,pc;
    double k,a,b,c;
    cin>>t;
    while(t--)
    {
        cin>>p.x>>p.y>>q.x>>q.y>>r.x>>r.y;
        cin>>m1>>m2>>m3>>m4>>m5>>m6;
        k=(m1/m2)*(m3/m4)*(m5/m6);
        a=(m5/m6)*(m1/m2+1);
        b=(m1/m2)*(m3/m4+1);
        c=(m3/m4)*(m5/m6+1);
        pa=r+resiz(r-p,(a+k)/(1-k));
        pb=p+resiz(p-q,(b+k)/(1-k));
        pc=q+resiz(q-r,(c+k)/(1-k));
        cout<<fixed<<setprecision(8)<<pa.x<<" "<<pa.y<<" "<<pb.x<<" "<<pb.y<<" "<<pc.x<<" "<<pc.y<<endl;
    }
    return 0;
}
