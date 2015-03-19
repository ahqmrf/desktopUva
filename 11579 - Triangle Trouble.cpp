#include<bits/stdc++.h>
#define maxN 100001
#define sci(a) scanf("%d", &a)
#define scd(a) scanf("%lf", &a)

using namespace std;

double sides[maxN];

bool myCompare(double a, double b)
{
    return a > b;
}

bool valid(double a, double b, double c)
{
    if(a + b > c || b + c > a || c + a > b) return true;
    return false;
}

double area(double a, double b, double c)
{
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s-a) * (s-b) * (s-c));
}


int main()
{
    int N, cases;
    sci(cases);
    while(cases--)
    {
        sci(N);
        for(int i = 0; i < N; i++)
            scd(sides[i]);
        double ans = 0.00;
        sort(sides, sides+N, myCompare);

        for(int i = 0; i < N-2; i++)
        {
            if(valid(sides[i], sides[(i+1)%N], sides[(i+2)%N]))
                ans = max(ans, area(sides[i], sides[(i+1)%N], sides[(i+2)%N]));
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}
