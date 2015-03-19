#include<stdio.h>
#include<math.h>
#define PI acos(-1)
struct co
{
    double x;
    double y;
} A, B, C, D;

int main (void)
{
    double AB, BC, CD, AD, BD, AC;
    int cases, i;
    scanf("%d", &cases);
    for(i=1; i<=cases; i++)
    {
        scanf("%lf%lf", &A.x, &A.y);
        scanf("%lf%lf", &B.x, &B.y);
        scanf("%lf%lf", &C.x, &C.y);
        scanf("%lf%lf", &D.x, &D.y);

        AB = sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));
        AD = sqrt((A.x-D.x)*(A.x-D.x) + (A.y-D.y)*(A.y-D.y));
        BC = sqrt((C.x-B.x)*(C.x-B.x) + (C.y-B.y)*(C.y-B.y));
        CD = sqrt((C.x-D.x)*(C.x-D.x) + (C.y-D.y)*(C.y-D.y));
        BD = sqrt((B.x-D.x)*(B.x-D.x) + (B.y-D.y)*(B.y-D.y));
        AC = sqrt((C.x-A.x)*(C.x-A.x) + (C.y-A.y)*(C.y-A.y));
        printf("Case %d: ", i);

        if(AB == BC && BC == CD && CD == AD)
        {
            if(AC == BD) printf("Square\n");
            else printf("Rhombus\n");
        }

        else if(AB == CD && BC == AD)
        {
            if(AC == BD) printf("Rectangle\n");
            else printf("Parallelogram\n");
        }

        else
        {
            double BDC, ABD, ADB, DBC;
            BDC = acos((CD*CD+BD*BD-BC*BC)/(2.0*CD*BD));
            ABD = acos((BD*BD+AB*AB-AD*AD)/(2.0*BD*AB));
            ADB = acos((AD*AD+BD*BD-AB*AB)/(2.0*AD*BD));
            DBC = acos((BC*BC+BD*BD-CD*CD)/(2.0*BC*BD));

            if(BDC == ABD || ADB == DBC) printf("Trapezium\n");
            else printf("Ordinary Quadrilateral\n");
        }
    }
    return 0;
}
