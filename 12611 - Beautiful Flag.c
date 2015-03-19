#include<stdio.h>
struct coordinate
{
    int x;
    int y;
} A, B, C, D;


int main (void)
{
    int cases, r, i;

    scanf("%d", &cases);
    for(i = 1; i <= cases; ++i)
    {
        scanf("%d", &r);
        A.x = D.x = (-9*r) / 4;
        B.x = C.x = (11 * r) / 4;
        A.y = B.y = (3*r)/2;
        C.y = D.y = -1*A.y;

        printf("Case %d:\n%d %d\n%d %d\n%d %d\n%d %d\n", i, A.x, A.y, B.x, B.y, C.x, C.y, D.x, D.y);
    }
    return 0;
}
