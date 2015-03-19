#include<stdio.h>
int main (void)
{
    int cases, i;
    scanf("%d", &cases);
    for(i = 1; i <= cases; i++)
    {
        float C, inF, F;
        scanf("%f%f", &C, &inF);
        F = C*9.0/5.0 + 32.0;
        F += inF;
        C = 5.0*(F-32.0)/9.0;
        printf("Case %d: %.2f\n", i, C);
    }
    return 0;
}
