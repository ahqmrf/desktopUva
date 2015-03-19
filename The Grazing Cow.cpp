#include<cstdio>
#include<cmath>

#define PI acos(-1)
using namespace std;

int main (void)
{
    double L, D;
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%lf %lf", &D, &L);
        L/=2.0;
        D/=2.0;
        printf("%.3lf\n", PI * L*sqrt(L*L - D*D));
    }
    return 0;
}

