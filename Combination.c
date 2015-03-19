#include<stdio.h>

long double Factorial[101];

int main (void)
{
    int j = 0;
    long double i, temp = 1;
    long double value = 1;
    for(i = 1; i < 101; i++)
    {
        value *= temp;
        Factorial[j] = value;
        temp++;
        j++;
    }

    int N, M;

    while(scanf("%d%d", &N, &M) == 2 && N!=0 && M!=0)
    {
        long double C = Factorial[N]/(Factorial[N-M] * Factorial[M]);
        printf("%lf\n", Factorial[0]);
        printf("%d things taken %d at a time is %Lf exactly.\n", N, M, C);
    }
    return 0;
}
